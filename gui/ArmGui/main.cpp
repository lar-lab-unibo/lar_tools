#include "armcontrolgui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ArmControlGui w("comauSmartSix");
    w.show();

    return a.exec();
}
