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
    QHBoxLayout *lay_j2;
    QSlider *slider_j2;
    QLCDNumber *lcd_j2;
    QHBoxLayout *lay_j3;
    QSlider *slider_j3;
    QLCDNumber *lcd_j3;
    QHBoxLayout *lay_j4;
    QSlider *slider_j4;
    QLCDNumber *lcd_j4;
    QHBoxLayout *lay_j5;
    QSlider *slider_j6;
    QLCDNumber *lcd_j5;
    QHBoxLayout *lay_j6;
    QSlider *slider_j5;
    QLCDNumber *lcd_j6;
    QHBoxLayout *lay_j7;
    QSlider *slider_j7;
    QLCDNumber *lcd_j7;
    QGroupBox *group_shapes;
    QVBoxLayout *verticalLayout_2;
    QListWidget *list_shapes;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_shape_save;
    QPushButton *btn_test_2;
    QPushButton *btn_shape_delete;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ArmControlGui)
    {
        if (ArmControlGui->objectName().isEmpty())
            ArmControlGui->setObjectName(QStringLiteral("ArmControlGui"));
        ArmControlGui->resize(961, 646);
        centralWidget = new QWidget(ArmControlGui);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        group_joints = new QGroupBox(centralWidget);
        group_joints->setObjectName(QStringLiteral("group_joints"));
        group_joints->setGeometry(QRect(9, 9, 371, 361));
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


        verticalLayout->addLayout(lay_j7);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        group_shapes = new QGroupBox(centralWidget);
        group_shapes->setObjectName(QStringLiteral("group_shapes"));
        group_shapes->setGeometry(QRect(400, 20, 381, 351));
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

        ArmControlGui->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ArmControlGui);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 961, 25));
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
    } // retranslateUi

};

namespace Ui {
    class ArmControlGui: public Ui_ArmControlGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARMCONTROLGUI_H
