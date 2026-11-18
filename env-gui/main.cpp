#include <QApplication>
#include <QWidget>
#include "envgui.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    EnvGui window;
    window.show();

    return app.exec();
}