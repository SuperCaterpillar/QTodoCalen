#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "APP/QTCApplication.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    // qputenv("QML_DEBUG", "1");
    // QQmlApplicationEngine engine;
    // engine.addImportPath(QStringLiteral("qrc:/qml"));
    // QObject::connect(
    //     &engine,
    //     &QQmlApplicationEngine::objectCreationFailed,
    //     &app,
    //     []() { QCoreApplication::exit(-1); },
    //     Qt::QueuedConnection);


    // engine.loadFromModule("QTodoCalen.UI.MainWindowModule", "MainWindow");

    return app.exec();
}
