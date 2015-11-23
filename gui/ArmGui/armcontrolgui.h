#ifndef ARMCONTROLGUI_H
#define ARMCONTROLGUI_H

#include <QMainWindow>
#include <QSlider>
#include <QLCDNumber>
#include <QInputDialog>
#include <QListWidgetItem>

#define ARMCONTROLGUI_ARM_JOINTS_SIZE 7
#define ARMCONTROLGUI_USER_FOLDER_PREFIX ".armcontrolgui"
#define ARMCONTROLGUI_SHAPE_EXTENSION ".txt"

namespace Ui {
class ArmControlGui;
}

/**
 * @brief The JointShape struct
 */
struct JointShape{
    double joints[ARMCONTROLGUI_ARM_JOINTS_SIZE];
    QString name;
};

/**
 * @brief The UserFolderTree struct
 */
struct UserFolderTree{
    QString base;
    QString shapes;
};

/**
 * @brief The ArmControlGui class
 */
class ArmControlGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit ArmControlGui(std::string robot_name, QWidget *parent = 0);
    ~ArmControlGui();

private slots:
    void jointsSignal(int value);
    void listShapeClick(QListWidgetItem*);
    void btnSaveShape();
    void btnLoadShape();
    void btnDeleteShape();
private:
    QString robot_name;
    UserFolderTree user_folder;


    Ui::ArmControlGui *ui;
    std::vector<QSlider*> sliders_joints;
    std::vector<QLCDNumber*> lcd_joints;


    std::vector<JointShape> available_shapes;

    void initializeUserFolder();
    void initializeJoints();
    void updateJointsLCD();


    void saveShape(JointShape& shape);
    void loadShape(QString& filename,JointShape& shape);
    void loadShapes();
    bool findShapeByName(const QString& name, JointShape& out_shape);

    UserFolderTree createUserFolder(QString& robot_name);
    JointShape getCurrentJointShape(QString& name);
    void setCurrentJointShape(JointShape& shape);

};

#endif // ARMCONTROLGUI_H
