#include "planegui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PlaneGUI w;
    w.show();

    return a.exec();
}
