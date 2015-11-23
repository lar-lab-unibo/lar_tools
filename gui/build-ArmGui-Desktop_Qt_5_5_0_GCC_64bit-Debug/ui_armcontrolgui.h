/********************************************************************************
** Form generated from reading UI file 'armcontrolgui.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARMCONTROLGUI_H
#define UI_ARMCONTROLGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArmControlGui
{
public:
    QWidget *centralWidget;
    QGroupBox *group_joints;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *lay_j1;
    QSlider *slider_j1;
    QLCDNumber *lcd_j1;
    QLCDNumber *lcd_jreal1;
    QHBoxLayout *lay_j2;
    QSlider *slider_j2;
    QLCDNumber *lcd_j2;
    QLCDNumber *lcd_jreal2;
    QHBoxLayout *lay_j3;
    QSlider *slider_j3;
    QLCDNumber *lcd_j3;
    QLCDNumber *lcd_jreal3;
    QHBoxLayout *lay_j4;
    QSlider *slider_j4;
    QLCDNumber *lcd_j4;
    QLCDNumber *lcd_jreal4;
    QHBoxLayout *lay_j5;
    QSlider *slider_j6;
    QLCDNumber *lcd_j5;
    QLCDNumber *lcd_jreal5;
    QHBoxLayout *lay_j6;
    QSlider *slider_j5;
    QLCDNumber *lcd_j6;
    QLCDNumber *lcd_jreal6;
    QHBoxLayout *lay_j7;
    QSlider *slider_j7;
    QLCDNumber *lcd_j7;
    QLCDNumber *lcd_jreal7;
    QGroupBox *group_shapes;
    QVBoxLayout *verticalLayout_2;
    QListWidget *list_shapes;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_shape_save;
    QPushButton *btn_test_2;
    QPushButton *btn_shape_delete;
    QGroupBox *group_cartesian;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_cart_x;
    QSlider *slider_cart_x;
    QLCDNumber *lcd_cart_x;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_cart_y;
    QSlider *slider_cart_y;
    QLCDNumber *lcd_cart_y;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_cart_z;
    QSlider *slider_cart_z;
    QLCDNumber *lcd_cart_z;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_cart_roll;
    QSlider *slider_cart_roll;
    QLCDNumber *lcd_cart_roll;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_cart_pitch;
    QSlider *slider_cart_pitch;
    QLCDNumber *lcd_cart_pitch;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_cart_yaw;
    QSlider *slider_cart_yaw;
    QLCDNumber *lcd_cart_yaw;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ArmControlGui)
    {
        if (ArmControlGui->objectName().isEmpty())
            ArmControlGui->setObjectName(QStringLiteral("ArmControlGui"));
        ArmControlGui->resize(1129, 745);
        centralWidget = new QWidget(ArmControlGui);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        group_joints = new QGroupBox(centralWidget);
        group_joints->setObjectName(QStringLiteral("group_joints"));
        group_joints->setGeometry(QRect(9, 9, 461, 361));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(242, 194, 146, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(248, 224, 200, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(121, 97, 73, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(161, 129, 97, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        group_joints->setPalette(palette);
        gridLayout = new QGridLayout(group_joints);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        lay_j1 = new QHBoxLayout();
        lay_j1->setSpacing(6);
        lay_j1->setObjectName(QStringLiteral("lay_j1"));
        slider_j1 = new QSlider(group_joints);
        slider_j1->setObjectName(QStringLiteral("slider_j1"));
        slider_j1->setMinimum(-180);
        slider_j1->setMaximum(180);
        slider_j1->setOrientation(Qt::Horizontal);

        lay_j1->addWidget(slider_j1);

        lcd_j1 = new QLCDNumber(group_joints);
        lcd_j1->setObjectName(QStringLiteral("lcd_j1"));

        lay_j1->addWidget(lcd_j1);

        lcd_jreal1 = new QLCDNumber(group_joints);
        lcd_jreal1->setObjectName(QStringLiteral("lcd_jreal1"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush7(QColor(49, 179, 255, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush7);
        QBrush brush8(QColor(177, 226, 255, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush8);
        QBrush brush9(QColor(113, 202, 255, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush9);
        QBrush brush10(QColor(24, 89, 127, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush10);
        QBrush brush11(QColor(32, 119, 170, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush12(QColor(152, 217, 255, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        lcd_jreal1->setPalette(palette1);
        lcd_jreal1->setAutoFillBackground(true);

        lay_j1->addWidget(lcd_jreal1);


        verticalLayout->addLayout(lay_j1);

        lay_j2 = new QHBoxLayout();
        lay_j2->setSpacing(6);
        lay_j2->setObjectName(QStringLiteral("lay_j2"));
        slider_j2 = new QSlider(group_joints);
        slider_j2->setObjectName(QStringLiteral("slider_j2"));
        slider_j2->setMinimum(-180);
        slider_j2->setMaximum(180);
        slider_j2->setOrientation(Qt::Horizontal);

        lay_j2->addWidget(slider_j2);

        lcd_j2 = new QLCDNumber(group_joints);
        lcd_j2->setObjectName(QStringLiteral("lcd_j2"));

        lay_j2->addWidget(lcd_j2);

        lcd_jreal2 = new QLCDNumber(group_joints);
        lcd_jreal2->setObjectName(QStringLiteral("lcd_jreal2"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush8);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush9);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush10);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        lcd_jreal2->setPalette(palette2);
        lcd_jreal2->setAutoFillBackground(true);

        lay_j2->addWidget(lcd_jreal2);


        verticalLayout->addLayout(lay_j2);

        lay_j3 = new QHBoxLayout();
        lay_j3->setSpacing(6);
        lay_j3->setObjectName(QStringLiteral("lay_j3"));
        slider_j3 = new QSlider(group_joints);
        slider_j3->setObjectName(QStringLiteral("slider_j3"));
        slider_j3->setMinimum(-180);
        slider_j3->setMaximum(180);
        slider_j3->setOrientation(Qt::Horizontal);

        lay_j3->addWidget(slider_j3);

        lcd_j3 = new QLCDNumber(group_joints);
        lcd_j3->setObjectName(QStringLiteral("lcd_j3"));

        lay_j3->addWidget(lcd_j3);

        lcd_jreal3 = new QLCDNumber(group_joints);
        lcd_jreal3->setObjectName(QStringLiteral("lcd_jreal3"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush8);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush9);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush10);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        lcd_jreal3->setPalette(palette3);
        lcd_jreal3->setAutoFillBackground(true);

        lay_j3->addWidget(lcd_jreal3);


        verticalLayout->addLayout(lay_j3);

        lay_j4 = new QHBoxLayout();
        lay_j4->setSpacing(6);
        lay_j4->setObjectName(QStringLiteral("lay_j4"));
        slider_j4 = new QSlider(group_joints);
        slider_j4->setObjectName(QStringLiteral("slider_j4"));
        slider_j4->setMinimum(-180);
        slider_j4->setMaximum(180);
        slider_j4->setOrientation(Qt::Horizontal);

        lay_j4->addWidget(slider_j4);

        lcd_j4 = new QLCDNumber(group_joints);
        lcd_j4->setObjectName(QStringLiteral("lcd_j4"));

        lay_j4->addWidget(lcd_j4);

        lcd_jreal4 = new QLCDNumber(group_joints);
        lcd_jreal4->setObjectName(QStringLiteral("lcd_jreal4"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush8);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush9);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush10);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush9);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush9);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        lcd_jreal4->setPalette(palette4);
        lcd_jreal4->setAutoFillBackground(true);

        lay_j4->addWidget(lcd_jreal4);


        verticalLayout->addLayout(lay_j4);

        lay_j5 = new QHBoxLayout();
        lay_j5->setSpacing(6);
        lay_j5->setObjectName(QStringLiteral("lay_j5"));
        slider_j6 = new QSlider(group_joints);
        slider_j6->setObjectName(QStringLiteral("slider_j6"));
        slider_j6->setMinimum(-180);
        slider_j6->setMaximum(180);
        slider_j6->setOrientation(Qt::Horizontal);

        lay_j5->addWidget(slider_j6);

        lcd_j5 = new QLCDNumber(group_joints);
        lcd_j5->setObjectName(QStringLiteral("lcd_j5"));

        lay_j5->addWidget(lcd_j5);

        lcd_jreal5 = new QLCDNumber(group_joints);
        lcd_jreal5->setObjectName(QStringLiteral("lcd_jreal5"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette5.setBrush(QPalette::Active, QPalette::Light, brush8);
        palette5.setBrush(QPalette::Active, QPalette::Midlight, brush9);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush10);
        palette5.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette5.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush8);
        palette5.setBrush(QPalette::Inactive, QPalette::Midlight, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette5.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush8);
        palette5.setBrush(QPalette::Disabled, QPalette::Midlight, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette5.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        lcd_jreal5->setPalette(palette5);
        lcd_jreal5->setAutoFillBackground(true);

        lay_j5->addWidget(lcd_jreal5);


        verticalLayout->addLayout(lay_j5);

        lay_j6 = new QHBoxLayout();
        lay_j6->setSpacing(6);
        lay_j6->setObjectName(QStringLiteral("lay_j6"));
        slider_j5 = new QSlider(group_joints);
        slider_j5->setObjectName(QStringLiteral("slider_j5"));
        slider_j5->setMinimum(-180);
        slider_j5->setMaximum(180);
        slider_j5->setOrientation(Qt::Horizontal);

        lay_j6->addWidget(slider_j5);

        lcd_j6 = new QLCDNumber(group_joints);
        lcd_j6->setObjectName(QStringLiteral("lcd_j6"));

        lay_j6->addWidget(lcd_j6);

        lcd_jreal6 = new QLCDNumber(group_joints);
        lcd_jreal6->setObjectName(QStringLiteral("lcd_jreal6"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette6.setBrush(QPalette::Active, QPalette::Light, brush8);
        palette6.setBrush(QPalette::Active, QPalette::Midlight, brush9);
        palette6.setBrush(QPalette::Active, QPalette::Dark, brush10);
        palette6.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette6.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette6.setBrush(QPalette::Inactive, QPalette::Light, brush8);
        palette6.setBrush(QPalette::Inactive, QPalette::Midlight, brush9);
        palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette6.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette6.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette6.setBrush(QPalette::Disabled, QPalette::Light, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::Midlight, brush9);
        palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette6.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette6.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush7);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        lcd_jreal6->setPalette(palette6);
        lcd_jreal6->setAutoFillBackground(true);

        lay_j6->addWidget(lcd_jreal6);


        verticalLayout->addLayout(lay_j6);

        lay_j7 = new QHBoxLayout();
        lay_j7->setSpacing(6);
        lay_j7->setObjectName(QStringLiteral("lay_j7"));
        slider_j7 = new QSlider(group_joints);
        slider_j7->setObjectName(QStringLiteral("slider_j7"));
        slider_j7->setMinimum(-180);
        slider_j7->setMaximum(180);
        slider_j7->setOrientation(Qt::Horizontal);

        lay_j7->addWidget(slider_j7);

        lcd_j7 = new QLCDNumber(group_joints);
        lcd_j7->setObjectName(QStringLiteral("lcd_j7"));

        lay_j7->addWidget(lcd_j7);

        lcd_jreal7 = new QLCDNumber(group_joints);
        lcd_jreal7->setObjectName(QStringLiteral("lcd_jreal7"));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush8);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush9);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush10);
        palette7.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette7.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush8);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush9);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette7.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush8);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush9);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette7.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette7.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush7);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        lcd_jreal7->setPalette(palette7);
        lcd_jreal7->setAutoFillBackground(true);

        lay_j7->addWidget(lcd_jreal7);


        verticalLayout->addLayout(lay_j7);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        group_shapes = new QGroupBox(centralWidget);
        group_shapes->setObjectName(QStringLiteral("group_shapes"));
        group_shapes->setGeometry(QRect(530, 20, 381, 351));
        verticalLayout_2 = new QVBoxLayout(group_shapes);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        list_shapes = new QListWidget(group_shapes);
        list_shapes->setObjectName(QStringLiteral("list_shapes"));

        verticalLayout_2->addWidget(list_shapes);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_shape_save = new QPushButton(group_shapes);
        btn_shape_save->setObjectName(QStringLiteral("btn_shape_save"));

        horizontalLayout->addWidget(btn_shape_save);

        btn_test_2 = new QPushButton(group_shapes);
        btn_test_2->setObjectName(QStringLiteral("btn_test_2"));

        horizontalLayout->addWidget(btn_test_2);

        btn_shape_delete = new QPushButton(group_shapes);
        btn_shape_delete->setObjectName(QStringLiteral("btn_shape_delete"));

        horizontalLayout->addWidget(btn_shape_delete);


        verticalLayout_2->addLayout(horizontalLayout);

        group_cartesian = new QGroupBox(centralWidget);
        group_cartesian->setObjectName(QStringLiteral("group_cartesian"));
        group_cartesian->setGeometry(QRect(30, 410, 411, 271));
        gridLayout_2 = new QGridLayout(group_cartesian);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_cart_x = new QLabel(group_cartesian);
        label_cart_x->setObjectName(QStringLiteral("label_cart_x"));

        horizontalLayout_5->addWidget(label_cart_x);

        slider_cart_x = new QSlider(group_cartesian);
        slider_cart_x->setObjectName(QStringLiteral("slider_cart_x"));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush13(QColor(230, 38, 67, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush13);
        QBrush brush14(QColor(255, 132, 151, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Light, brush14);
        QBrush brush15(QColor(242, 85, 109, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Midlight, brush15);
        QBrush brush16(QColor(115, 19, 33, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Dark, brush16);
        QBrush brush17(QColor(153, 25, 44, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Mid, brush17);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush);
        palette8.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush13);
        palette8.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush18(QColor(242, 146, 161, 255));
        brush18.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::AlternateBase, brush18);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush13);
        palette8.setBrush(QPalette::Inactive, QPalette::Light, brush14);
        palette8.setBrush(QPalette::Inactive, QPalette::Midlight, brush15);
        palette8.setBrush(QPalette::Inactive, QPalette::Dark, brush16);
        palette8.setBrush(QPalette::Inactive, QPalette::Mid, brush17);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        palette8.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush18);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush16);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush13);
        palette8.setBrush(QPalette::Disabled, QPalette::Light, brush14);
        palette8.setBrush(QPalette::Disabled, QPalette::Midlight, brush15);
        palette8.setBrush(QPalette::Disabled, QPalette::Dark, brush16);
        palette8.setBrush(QPalette::Disabled, QPalette::Mid, brush17);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette8.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush16);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush13);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush13);
        palette8.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush13);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        slider_cart_x->setPalette(palette8);
        slider_cart_x->setMinimum(-2000);
        slider_cart_x->setMaximum(2000);
        slider_cart_x->setSingleStep(5);
        slider_cart_x->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(slider_cart_x);

        lcd_cart_x = new QLCDNumber(group_cartesian);
        lcd_cart_x->setObjectName(QStringLiteral("lcd_cart_x"));

        horizontalLayout_5->addWidget(lcd_cart_x);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 5);
        horizontalLayout_5->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_cart_y = new QLabel(group_cartesian);
        label_cart_y->setObjectName(QStringLiteral("label_cart_y"));

        horizontalLayout_4->addWidget(label_cart_y);

        slider_cart_y = new QSlider(group_cartesian);
        slider_cart_y->setObjectName(QStringLiteral("slider_cart_y"));
        slider_cart_y->setMinimum(-2000);
        slider_cart_y->setMaximum(2000);
        slider_cart_y->setSingleStep(5);
        slider_cart_y->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(slider_cart_y);

        lcd_cart_y = new QLCDNumber(group_cartesian);
        lcd_cart_y->setObjectName(QStringLiteral("lcd_cart_y"));

        horizontalLayout_4->addWidget(lcd_cart_y);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 5);
        horizontalLayout_4->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_cart_z = new QLabel(group_cartesian);
        label_cart_z->setObjectName(QStringLiteral("label_cart_z"));

        horizontalLayout_3->addWidget(label_cart_z);

        slider_cart_z = new QSlider(group_cartesian);
        slider_cart_z->setObjectName(QStringLiteral("slider_cart_z"));
        slider_cart_z->setMinimum(-2000);
        slider_cart_z->setMaximum(2000);
        slider_cart_z->setSingleStep(5);
        slider_cart_z->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(slider_cart_z);

        lcd_cart_z = new QLCDNumber(group_cartesian);
        lcd_cart_z->setObjectName(QStringLiteral("lcd_cart_z"));

        horizontalLayout_3->addWidget(lcd_cart_z);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 5);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_cart_roll = new QLabel(group_cartesian);
        label_cart_roll->setObjectName(QStringLiteral("label_cart_roll"));

        horizontalLayout_6->addWidget(label_cart_roll);

        slider_cart_roll = new QSlider(group_cartesian);
        slider_cart_roll->setObjectName(QStringLiteral("slider_cart_roll"));
        slider_cart_roll->setMinimum(-180);
        slider_cart_roll->setMaximum(180);
        slider_cart_roll->setPageStep(5);
        slider_cart_roll->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(slider_cart_roll);

        lcd_cart_roll = new QLCDNumber(group_cartesian);
        lcd_cart_roll->setObjectName(QStringLiteral("lcd_cart_roll"));

        horizontalLayout_6->addWidget(lcd_cart_roll);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 5);
        horizontalLayout_6->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_cart_pitch = new QLabel(group_cartesian);
        label_cart_pitch->setObjectName(QStringLiteral("label_cart_pitch"));

        horizontalLayout_2->addWidget(label_cart_pitch);

        slider_cart_pitch = new QSlider(group_cartesian);
        slider_cart_pitch->setObjectName(QStringLiteral("slider_cart_pitch"));
        slider_cart_pitch->setMinimum(-180);
        slider_cart_pitch->setMaximum(180);
        slider_cart_pitch->setPageStep(5);
        slider_cart_pitch->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(slider_cart_pitch);

        lcd_cart_pitch = new QLCDNumber(group_cartesian);
        lcd_cart_pitch->setObjectName(QStringLiteral("lcd_cart_pitch"));

        horizontalLayout_2->addWidget(lcd_cart_pitch);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 5);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_cart_yaw = new QLabel(group_cartesian);
        label_cart_yaw->setObjectName(QStringLiteral("label_cart_yaw"));

        horizontalLayout_7->addWidget(label_cart_yaw);

        slider_cart_yaw = new QSlider(group_cartesian);
        slider_cart_yaw->setObjectName(QStringLiteral("slider_cart_yaw"));
        slider_cart_yaw->setMinimum(-180);
        slider_cart_yaw->setMaximum(180);
        slider_cart_yaw->setPageStep(5);
        slider_cart_yaw->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(slider_cart_yaw);

        lcd_cart_yaw = new QLCDNumber(group_cartesian);
        lcd_cart_yaw->setObjectName(QStringLiteral("lcd_cart_yaw"));

        horizontalLayout_7->addWidget(lcd_cart_yaw);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 5);
        horizontalLayout_7->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout_7);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);

        ArmControlGui->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ArmControlGui);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1129, 25));
        ArmControlGui->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ArmControlGui);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ArmControlGui->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ArmControlGui);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ArmControlGui->setStatusBar(statusBar);

        retranslateUi(ArmControlGui);

        QMetaObject::connectSlotsByName(ArmControlGui);
    } // setupUi

    void retranslateUi(QMainWindow *ArmControlGui)
    {
        ArmControlGui->setWindowTitle(QApplication::translate("ArmControlGui", "ArmControlGui", 0));
        group_joints->setTitle(QApplication::translate("ArmControlGui", "Joints", 0));
        group_shapes->setTitle(QApplication::translate("ArmControlGui", "Joints Shapes", 0));
        btn_shape_save->setText(QApplication::translate("ArmControlGui", "Save", 0));
        btn_test_2->setText(QApplication::translate("ArmControlGui", "Load", 0));
        btn_shape_delete->setText(QApplication::translate("ArmControlGui", "Delete", 0));
        group_cartesian->setTitle(QApplication::translate("ArmControlGui", "Cartesian", 0));
        label_cart_x->setText(QApplication::translate("ArmControlGui", "X", 0));
        label_cart_y->setText(QApplication::translate("ArmControlGui", "Y", 0));
        label_cart_z->setText(QApplication::translate("ArmControlGui", "Z", 0));
        label_cart_roll->setText(QApplication::translate("ArmControlGui", "Roll", 0));
        label_cart_pitch->setText(QApplication::translate("ArmControlGui", "Pitch", 0));
        label_cart_yaw->setText(QApplication::translate("ArmControlGui", "Yaw", 0));
    } // retranslateUi

};

namespace Ui {
    class ArmControlGui: public Ui_ArmControlGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARMCONTROLGUI_H
