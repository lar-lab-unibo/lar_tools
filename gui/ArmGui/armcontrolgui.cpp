#include "armcontrolgui.h"
#include "ui_armcontrolgui.h"
#include <QDebug>
#include <QDir>
#include <QDirIterator>
#include <QProcess>
#include <QStringList>

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

    /* CONNECTION CHECK FLAG */
    this->connected = false;
    this->op_mode = OP_MODE_JOINT;



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

    //TEST
    connect(ui->test_cartesian_check,SIGNAL(stateChanged(int)),this,SLOT(testCheck(int)));
    connect(ui->test_target_check,SIGNAL(stateChanged(int)),this,SLOT(testCheck(int)));
    connect(ui->test_slider_target_azimuth,SIGNAL(valueChanged(int)),this,SLOT(testTarget(int)));
    connect(ui->test_slider_target_zenith,SIGNAL(valueChanged(int)),this,SLOT(testTarget(int)));
    connect(ui->test_slider_target_distance,SIGNAL(valueChanged(int)),this,SLOT(testTarget(int)));
    connect(ui->test_slider_target_roll,SIGNAL(valueChanged(int)),this,SLOT(testTarget(int)));



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
    //qDebug()<<obj->objectName()<<" "<<value;
    this->updateJointsLCD();
    if(this->op_mode == OP_MODE_JOINT){
        this->sendJoints();
    }
}

/**
 * @brief ArmControlGui::sendJoints
 */
void ArmControlGui::sendJoints(){
    if(this->connected){
        this->send_message.command=COMMAND_SEND_JOINTS;
        for(int i = 0; i < ARMCONTROLGUI_ARM_JOINTS_SIZE; i++){
            this->send_message.payload[i] = this->sliders_joints[i]->value();
        }
        char* arr = reinterpret_cast<char*>(&this->send_message);
        this->send_socket->writeDatagram(arr,sizeof(this->send_message),this->remote_host,this->remote_port);
    }
}

/**
 * @brief ArmControlGui::sendWhatever
 */
void ArmControlGui::sendWhatever(){
    if(this->op_mode == OP_MODE_JOINT){
        this->sendJoints();
    }
    if(this->op_mode==OP_MODE_CARTESIAN){
        this->sendCartesian();
    }
}

/**
 * @brief ArmControlGui::testCheck
 * @param value
 */
void ArmControlGui::testCheck(int value){
    if(this->ui->test_cartesian_check->isChecked()){
        this->op_mode = OP_MODE_CARTESIAN;
    }else{
        this->op_mode = OP_MODE_JOINT;
    }
    if(this->ui->test_target_check->isChecked()){
        this->op_mode = OP_MODE_TARGET;

    }
    this->sendWhatever();
}

/**
 * @brief ArmControlGui::testTarget
 * @param value
 */
void ArmControlGui::testTarget(int value){
    qDebug()<<COMMAND_SEND_CARTESIAN_TARGET;
    this->send_message.command = COMMAND_SEND_CARTESIAN_TARGET;
    this->send_message.payload[0] = this->ui->test_target_x->text().toDouble();
    this->send_message.payload[1] = this->ui->test_target_y->text().toDouble();
    this->send_message.payload[2] = this->ui->test_target_z->text().toDouble();

    this->send_message.payload[3] = this->ui->test_slider_target_azimuth->value();
    this->send_message.payload[4] = this->ui->test_slider_target_zenith->value();
    this->send_message.payload[5] = this->ui->test_slider_target_roll->value();
    this->send_message.payload[6] = this->ui->test_slider_target_distance->value();
    this->send_message.payload[7] = this->op_mode == OP_MODE_TARGET ? 1000:-1000;
    char* arr = reinterpret_cast<char*>(&this->send_message);
    this->send_socket->writeDatagram(arr,sizeof(this->send_message),this->remote_host,this->remote_port);

}

/**
 * @brief ArmControlGui::cartesiansSignal
 * @param value
 */
void ArmControlGui::cartesiansSignal(int value){
    this->updateCartesianLCD();
    if(this->op_mode==OP_MODE_CARTESIAN){
        this->sendCartesian();
    }
}


void ArmControlGui::sendCartesian(){
    if(this->connected){
        this->send_message.command=COMMAND_SEND_CARTESIAN;
        this->send_message.payload[0] = this->ui->slider_cart_x->value();
        this->send_message.payload[1] = this->ui->slider_cart_y->value();
        this->send_message.payload[2] = this->ui->slider_cart_z->value();
        this->send_message.payload[3] = this->ui->slider_cart_roll->value();
        this->send_message.payload[4] = this->ui->slider_cart_pitch->value();
        this->send_message.payload[5] = this->ui->slider_cart_yaw->value();
        char* arr = reinterpret_cast<char*>(&this->send_message);
        this->send_socket->writeDatagram(arr,sizeof(this->send_message),this->remote_host,this->remote_port);
    }
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


    QVector<QString> shape_names;

    while (it.hasNext()) {
        QString filename = it.next();
        if(filename.contains("~"))continue;
        qDebug()<<"F: "<<filename;
        JointShape shape;
        this->loadShape(filename,shape);
        if(!this->findShapeByName(shape.name,shape)){
            available_shapes.push_back(shape);
            shape_names.push_back(shape.name);
        }
    }

    //A-Z order
    qSort(shape_names.begin(),shape_names.end());



    ui->list_shapes->clear();
    for(int i = 0; i < shape_names.size();i++){
        QListWidgetItem* item = new QListWidgetItem(shape_names[i]);
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

    if(message.command==COMMAND_RECEIVE_JOINTS){
        QLCDNumber* lcd;
        for(int i = 0; i < ARMCONTROLGUI_ARM_JOINTS_SIZE; i++){
            lcd = this->lcd_joints_real[i];
            lcd->display(message.payload[i]);
        }
        if(!this->connected){
            for(int i = 0; i < ARMCONTROLGUI_ARM_JOINTS_SIZE; i++){
                this->sliders_joints[i]->setValue(message.payload[i]);
            }
        }
        this->connected = true;
        if(this->op_mode == OP_MODE_CARTESIAN || this->op_mode == OP_MODE_TARGET){
            for(int i = 0; i < ARMCONTROLGUI_ARM_JOINTS_SIZE; i++){
                this->sliders_joints[i]->setValue(message.payload[i]);
            }
            this->updateJointsLCD();
        }

    }
    if(message.command==COMMAND_RECEIVE_CARTESIAN){
        if(this->op_mode == OP_MODE_JOINT || this->op_mode == OP_MODE_TARGET){
            QLCDNumber* lcd;
            this->ui->slider_cart_x->setValue(message.payload[0]);
            this->ui->slider_cart_y->setValue(message.payload[1]);
            this->ui->slider_cart_z->setValue(message.payload[2]);
            this->ui->slider_cart_roll->setValue(message.payload[3]);
            this->ui->slider_cart_pitch->setValue(message.payload[4]);
            this->ui->slider_cart_yaw->setValue(message.payload[5]);
            //this->updateCartesianLCD();
        }
    }

}

//DA QUI IN POI é SOLO TEST!!
void ArmControlGui::on_gripper_reset_clicked()
{
    QProcess process;
    QStringList arguments;
    arguments << "0";
    process.start("/usr/bin/gripper_command",arguments);

    if(!process.waitForStarted()){
        qDebug()<<"BOH";
    }


    // Continue reading the data until EOF reached
    QByteArray data;

    while(process.waitForReadyRead())
        data.append(process.readAll());

    // Output the data
    qDebug(data.data());
    qDebug("Done!");
}

void ArmControlGui::on_gripper_open_clicked()
{
    QProcess process;
    QStringList arguments;
    arguments << "90";
    process.start("/usr/bin/gripper_command",arguments);

    if(!process.waitForStarted()){
        qDebug()<<"BOH";
    }


    // Continue reading the data until EOF reached
    QByteArray data;

    while(process.waitForReadyRead())
        data.append(process.readAll());

    // Output the data
    qDebug(data.data());
    qDebug("Done!");
}

void ArmControlGui::on_gripper_close_clicked()
{
    QProcess process;
    QStringList arguments;
    arguments << "150";
    process.start("gripper_command 150",arguments);
    process.waitForFinished();
    process.close();
    if(!process.waitForStarted()){
        qDebug()<<"BOH";
    }
    process.waitForFinished(3000);


    // Continue reading the data until EOF reached
    QByteArray data;

    while(process.waitForReadyRead())
        data.append(process.readAll());

    // Output the data
    qDebug(data.data());
    qDebug("Done!");
}
