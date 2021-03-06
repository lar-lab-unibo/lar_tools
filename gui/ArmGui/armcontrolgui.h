#ifndef ARMCONTROLGUI_H
#define ARMCONTROLGUI_H

#include <QMainWindow>
#include <QSlider>
#include <QLCDNumber>
#include <QInputDialog>
#include <QListWidgetItem>
#include <QUdpSocket>
#include <QThread>


#define ARMCONTROLGUI_ARM_JOINTS_SIZE 7
#define ARMCONTROLGUI_USER_FOLDER_PREFIX ".armcontrolgui"
#define ARMCONTROLGUI_SHAPE_EXTENSION ".txt"

#define COMMAND_RECEIVE_JOINTS 333
#define COMMAND_RECEIVE_CARTESIAN 777

#define COMMAND_SEND_JOINTS 333
#define COMMAND_SEND_CARTESIAN 777
#define COMMAND_SEND_CARTESIAN_TARGET 778


#define OP_MODE_JOINT 10001
#define OP_MODE_CARTESIAN 10005
#define OP_MODE_TARGET 10010

namespace Ui {
class ArmControlGui;

}

class MyThread;

/**
 * @brief The JointShape struct
 */
struct JointShape{
    double joints[ARMCONTROLGUI_ARM_JOINTS_SIZE];
    QString name;
};

/**
 * @brief The CartesianConfiguration struct
 */
struct CartesianConfiguration{
    double x;
    double y;
    double z;
    double roll;
    double pitch;
    double yaw;
};

/**
 * @brief The UserFolderTree struct
 */
struct UserFolderTree{
    QString base;
    QString shapes;
};

/**
 * @brief The UDPMessage struct
 */
struct UDPMessage{
    int command;
    long time;
    float payload[32];
};

/**
 * @brief The ArmControlGui class
 */
class ArmControlGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit ArmControlGui(std::string robot_name, QWidget *parent = 0);
    void consumeUDPMessage(UDPMessage& message);
    ~ArmControlGui();

private slots:
    void jointsSignal(int value);
    void cartesiansSignal(int value);
    void listShapeClick(QListWidgetItem*);
    void btnSaveShape();
    void btnLoadShape();
    void btnDeleteShape();
    void receiveMessage();
    //TESTING
    void testCheck(int value);
    void testTarget(int value);
    void on_gripper_reset_clicked();

    void on_gripper_open_clicked();

    void on_gripper_close_clicked();

private:
    bool connected;
    int op_mode;

    QUdpSocket* receive_socket;
    QUdpSocket* send_socket;
    QHostAddress remote_host;
    int remote_port;
    UDPMessage send_message;
    MyThread* receive_thread;

    int time;
    QString robot_name;
    UserFolderTree user_folder;


    Ui::ArmControlGui *ui;
    std::vector<QSlider*> sliders_joints;
    std::vector<QLCDNumber*> lcd_joints;
    std::vector<QLCDNumber*> lcd_joints_real;


    std::vector<JointShape> available_shapes;

    void initializeUserFolder();
    void initializeJoints();
    void updateJointsLCD();
    void sendJoints();
    void sendCartesian();
    void sendWhatever();
    void updateCartesianLCD();


    void saveShape(JointShape& shape);
    void loadShape(QString& filename,JointShape& shape);
    void loadShapes();
    bool findShapeByName(const QString& name, JointShape& out_shape);

    UserFolderTree createUserFolder(QString& robot_name);
    JointShape getCurrentJointShape(QString& name);
    void setCurrentJointShape(JointShape& shape);

};

/**
 * @brief The MyThread class
 */
class MyThread : public QThread
{
public:

    explicit MyThread(QString s,ArmControlGui* gui,QUdpSocket* socket) :name(s){
        this->gui = gui;
        this->socket=socket;
    }

    void run(){
        while(true){
            this->socket->readDatagram( (char*)&message, sizeof(message) );
            qDebug()<<"Readed "<<message.payload[0];
            this->gui->consumeUDPMessage(this->message);
            this->msleep(100);
        }
    }
private:
    UDPMessage message;
    QString name;
    ArmControlGui* gui;
    QUdpSocket* socket;

};

#endif // ARMCONTROLGUI_H
