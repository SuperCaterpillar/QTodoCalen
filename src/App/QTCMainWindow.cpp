#include "QTCMainWindow.h"

#include <QQmlApplicationEngine>

#include <QQuickWindow>


namespace QTC {

// Make sure to include the header where QQmlApplicationEnginePtr is defined, or use QQmlApplicationEngine* directly if QQmlApplicationEnginePtr is a typedef or smart pointer.

QTCMainWindow::QTCMainWindow(QObject *parent) : QObject{parent} {}

QQmlApplicationEnginePtr QTCMainWindow::createQmlApplicationEngine(
    QObject *parent) {
  QQmlApplicationEnginePtr _qmlAppEngine = qtc_create_shared_ptr<QQmlApplicationEngine>(parent);
  _qmlAppEngine->addImportPath(QStringLiteral("qrc:/qml"));
  // qmlEngine->rootContext()->setContextProperty(QStringLiteral("joystickManager"),
  // JoystickManager::instance());
  // qmlEngine->rootContext()->setContextProperty(QStringLiteral("debugMessageModel"),
  // QGCLogging::instance());
  // qmlEngine->rootContext()->setContextProperty(QStringLiteral("logDownloadController"),
  // LogDownloadController::instance());
  return _qmlAppEngine;
}

void QTCMainWindow::createRootWindow(QQmlApplicationEnginePtr engine)
{
    engine->load(QUrl(QStringLiteral("qrc:/qml/QTodoCalen/UI/MainWindow/MainWindow.qml")));
}

}  // namespace QTC
