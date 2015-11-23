#include "armcontrolgui.h"
#include "ui_armcontrolgui.h"
#include <QDebug>
#include <QDir>
#include <QDirIterator>


/**
 * @brief ArmControlGui::ArmControlGui
 * @param robot_name
 * @param parent
 */
ArmControlGui::ArmControlGui(std::string robot_name,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ArmControlGui)
{
    ui->setupUi(this);







    /* USER FOLDER */
    this->robot_name = QString(robot_name.c_str());
    this->user_folder = this->createUserFolder(this->robot_name);
    this->initializeUserFolder();

    /* SLIDERS */
    this->sliders_joints.resize(ARMCONTROLGUI_ARM_JOINTS_SIZE);
    this->lcd_joints.resize(ARMCONTROLGUI_ARM_JOINTS_SIZE);
    this->lcd_joints_real.resize(ARMCONTROLGUI_ARM_JOINTS_SIZE);

    for(int i = 0; i < ARMCONTROLGUI_ARM_JOINTS_SIZE; i++){
        QSlider* slider = ui->group_joints->findChild<QSlider*>(QString("slider_j%1").arg(i+1));
        QLCDNumber* lcd = ui->group_joints->findChild<QLCDNumber*>(QString("lcd_j%1").arg(i+1));
        QLCDNumber* lcd_real = ui->group_joints->findChild<QLCDNumber*>(QString("lcd_jreal%1").arg(i+1));
        this->sliders_joints[i] = slider;
        this->lcd_joints[i] = lcd;
        this->lcd_joints_real[i] = lcd_real;
        connect(slider,SIGNAL(valueChanged(int)),this,SLOT(jointsSignal(int)));
    }
    this->updateJointsLCD();
    //CARTESIAN
    connect(ui->slider_cart_x,SIGNAL(valueChanged(int)),this,SLOT(cartesiansSignal(int)));
    connect(ui->slider_cart_y,SIGNAL(valueChanged(int)),this,SLOT(cartesiansSignal(int)));
    connect(ui->slider_cart_z,SIGNAL(valueChanged(int)),this,SLOT(cartesiansSignal(int)));
    connect(ui->slider_cart_roll,SIGNAL(valueChanged(int)),this,SLOT(cartesiansSignal(int)));
    connect(ui->slider_cart_pitch,SIGNAL(valueChanged(int)),this,SLOT(cartesiansSignal(int)));
    connect(ui->slider_cart_yaw,SIGNAL(valueChanged(int)),this,SLOT(cartesiansSignal(int)));




    /* BUTTONS */
    connect(ui->btn_shape_save, SIGNAL (released()),this, SLOT (btnSaveShape()));
    connect(ui->btn_shape_delete, SIGNAL (released()),this, SLOT (btnDeleteShape()));
    connect(ui->btn_test_2, SIGNAL (released()),this, SLOT (btnLoadShape()));

    /* LISTS */
    connect(ui->list_shapes, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(listShapeClick(QListWidgetItem*)));



    /* SOCKETS */
    this->receive_socket = new QUdpSocket(this);
    this->receive_socket->bind(QHostAddress::LocalHost, 7751);
    this->send_socket = new QUdpSocket(this);
    this->remote_host = QHostAddress::LocalHost;
    this->remote_port = 7750;
    this->time =0;
    receive_thread = new MyThread("receive_thread",this,receive_socket);
    receive_thread->start();
}

/**
 * @brief ArmControlGui::~ArmControlGui
 */
ArmControlGui::~ArmControlGui()
{
    delete ui;
}

void ArmControlGui::receiveMessage(){
    while (this->receive_socket->hasPendingDatagrams()) {
        qDebug()<<"OK";
    }
}

/**
 * @brief ArmControlGui::initializeUserFolder
 */
void ArmControlGui::initializeUserFolder(){

    qDebug() << "Checking user folder: "<<user_folder.base;
    if(!QDir(this->user_folder.base).exists()){
        qDebug()<<"User folder not found! Creating..";

        QDir().mkpath(this->user_folder.base);
        QDir().mkpath(this->user_folder.shapes);
        qDebug()<<"Creating: "<<this->user_folder.base;
        qDebug()<<"Creating: "<<this->user_folder.shapes;

        this->initializeUserFolder();
    }else{
        qDebug()<<"User folder OK!";
    }
}

/**
 * @brief ArmControlGui::createUserFolder
 * @param robot_name
 */
UserFolderTree ArmControlGui::createUserFolder(QString& robot_name){
    UserFolderTree user_folder;
    user_folder.base = QDir::homePath()+"/"+ ARMCONTROLGUI_USER_FOLDER_PREFIX+"_"+robot_name+"/";
    user_folder.shapes = user_folder.base +"shapes/";
    return user_folder;
}

/**
 * @brief ArmControlGui::jointsSignal
 * @param value
 */
void ArmControlGui::jointsSignal(int value){
    QSlider* obj = (QSlider*)sender();
    qDebug()<<obj->objectName()<<" "<<value;
    this->updateJointsLCD();
    this->sendJoints();
}

/**
 * @brief ArmControlGui::sendJoints
 */
void ArmControlGui::sendJoints(){
    this->send_message.command=333;
    for(int i = 0; i < ARMCONTROLGUI_ARM_JOINTS_SIZE; i++){
        this->send_message.payload[i] = this->sliders_joints[i]->value();
    }
    char* arr = reinterpret_cast<char*>(&this->send_message);
    this->send_socket->writeDatagram(arr,sizeof(this->send_message),this->remote_host,this->remote_port);
}

/**
 * @brief ArmControlGui::cartesiansSignal
 * @param value
 */
void ArmControlGui::cartesiansSignal(int value){
    this->updateCartesianLCD();
}

/**
 * @brief ArmControlGui::updateJointsLCD
 */
void ArmControlGui::updateJointsLCD(){
    QSlider* slider;
    QLCDNumber* lcd;
    for(int i = 0; i < ARMCONTROLGUI_ARM_JOINTS_SIZE; i++){
        slider = this->sliders_joints[i];
        lcd = this->lcd_joints[i];
        lcd->display(slider->value());
    }
}

/**
 * @brief ArmControlGui::updateCartesianLCD
 */
void ArmControlGui::updateCartesianLCD(){

    ui->lcd_cart_x->display(ui->slider_cart_x->value());
    ui->lcd_cart_y->display(ui->slider_cart_y->value());
    ui->lcd_cart_z->display(ui->slider_cart_z->value());
    ui->lcd_cart_roll->display(ui->slider_cart_roll->value());
    ui->lcd_cart_pitch->display(ui->slider_cart_pitch->value());
    ui->lcd_cart_yaw->display(ui->slider_cart_yaw->value());
}

/**
 * @brief ArmControlGui::btnSaveShape
 */
void ArmControlGui::btnSaveShape(){

    qDebug()<<"Saving Shape...";
    bool ok;
    QInputDialog* inputDialog = new QInputDialog();
    inputDialog->setOptions(QInputDialog::NoButtons);
    QString text =  inputDialog->getText(NULL ,"Shape Name","Name:", QLineEdit::Normal,"shape_name", &ok);
    if(ok){
        JointShape shape = this->getCurrentJointShape(text);
        this->saveShape(shape);
        this->loadShapes();
    }else{

    }
}

/**
 * @brief ArmControlGui::btnDeleteShape
 */
void ArmControlGui::btnDeleteShape(){
    if(ui->list_shapes->selectedItems().size()>0){
        QListWidgetItem* item =  ui->list_shapes->selectedItems()[0];
        qDebug()<<item->text();
    }
}

/**
 * @brief ArmControlGui::btnLoadShape
 */
void ArmControlGui::btnLoadShape(){

    loadShapes();
    return ;
    qDebug()<<"Loading Shape...";
    bool ok;
    QInputDialog* inputDialog = new QInputDialog();
    inputDialog->setOptions(QInputDialog::NoButtons);
    QString text =  inputDialog->getText(NULL ,"Shape Name","Name:", QLineEdit::Normal,"/home/daniele/.armcontrolgui_comauSmartSix/shapes/shape_name.txt", &ok);
    if(ok){
        JointShape shape;// = this->getCurrentJointShape(text);
        this->loadShape(text,shape);
        this->setCurrentJointShape(shape);
    }else{

    }
}

/**
 * @brief ArmControlGui::saveShape
 * @param shape
 */
void ArmControlGui::saveShape(JointShape &shape){
    QString shapeFileName = this->user_folder.shapes+ shape.name+ QString(ARMCONTROLGUI_SHAPE_EXTENSION);
    QFile file(shapeFileName);
    if(file.open(QIODevice::ReadWrite)){
        QTextStream out(&file);   // we will serialize the data into the file
        out << "name "<<shape.name<<endl;   // serialize a string
        for(int i = 0; i < ARMCONTROLGUI_ARM_JOINTS_SIZE; i++){
           qDebug()<<"Saving "<<this->sliders_joints[i]->value();
           out << "j"<<(i+1)<<" "<<this->sliders_joints[i]->value()<<endl;   // serialize a string
        }
    }
}

/**
 * @brief ArmControlGui::loadShape
 * @param shape
 */
void ArmControlGui::loadShape(QString& filename,JointShape &shape){
    QString shapeFileName =  filename;
    QFile file(shapeFileName);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream in(&file);   // we will serialize the data into the file
        QString header = in.readLine();
        shape.name = header.split(" ")[1];   // serialize a string
        qDebug() << "Loading shape: " << shape.name;
        for(int i = 0; i < ARMCONTROLGUI_ARM_JOINTS_SIZE; i++){
           QString row = in.readLine();
           shape.joints[i] = row.split(" ")[1].toDouble();
           qDebug()<< row.split(" ")[0] <<" "<<shape.joints[i];
        }
    }
}

/**
 * @brief ArmControlGui::loadShapes
 */
void ArmControlGui::loadShapes(){
    available_shapes.clear();
    QDirIterator it(this->user_folder.shapes,  QDir::Files);
    while (it.hasNext()) {
        QString filename = it.next();
        if(filename.contains("~"))continue;
        qDebug()<<"F: "<<filename;
        JointShape shape;
        this->loadShape(filename,shape);
        if(!this->findShapeByName(shape.name,shape)){
            available_shapes.push_back(shape);
        }
    }

    ui->list_shapes->clear();
    for(int i = 0; i < available_shapes.size();i++){
        QListWidgetItem* item = new QListWidgetItem(available_shapes[i].name);
        ui->list_shapes->addItem(item);
    }
}

/**
 * @brief ArmControlGui::listShapeClick
 * @param item
 */
void ArmControlGui::listShapeClick(QListWidgetItem * item){
    JointShape shape;

    if(this->findShapeByName(item->text(),shape)==true){
        this->setCurrentJointShape(shape);
    }
}

/**
 * @brief ArmControlGui::findShapeByName
 * @param name
 * @param out_shape
 * @return
 */
bool ArmControlGui::findShapeByName(const QString &name, JointShape &out_shape){
    for(int i = 0; i < available_shapes.size();i++){
         if(available_shapes[i].name==name){
             out_shape = available_shapes[i];
             return true;
         }
    }
    return false;
}

/**
 * @brief ArmControlGui::getCurrentJointShape
 * @return
 */
JointShape ArmControlGui::getCurrentJointShape(QString& name){
    JointShape shape;
    shape.name = name;
    for(int i = 0; i < ARMCONTROLGUI_ARM_JOINTS_SIZE; i++){
        shape.joints[i] = this->sliders_joints[i]->value();
    }
    return shape;
}

/**
 * @brief ArmControlGui::setCurrentJointShape
 * @param shape
 */
void ArmControlGui::setCurrentJointShape(JointShape &shape){
    QSlider* slider;
    for(int i = 0; i < ARMCONTROLGUI_ARM_JOINTS_SIZE; i++){
        slider = this->sliders_joints[i];
        slider->setValue(shape.joints[i]);
    }
}

/**
 * @brief ArmControlGui::consumeUDPMessage
 * @param message
 */
void ArmControlGui::consumeUDPMessage(UDPMessage &message){

    if(message.command==333){
        QLCDNumber* lcd;
        for(int i = 0; i < ARMCONTROLGUI_ARM_JOINTS_SIZE; i++){
            lcd = this->lcd_joints_real[i];
            lcd->display(message.payload[i]);
        }
    }
}
