#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "APP/QTCApplication.h"

int main(int argc, char *argv[])
{
    QTC::QTCApplication app(argc, argv);

    app.init();

    return app.exec();
}
