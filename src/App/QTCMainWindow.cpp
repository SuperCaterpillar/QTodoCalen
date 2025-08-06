#include "QTCMainWindow.h"

#include <QQmlApplicationEngine>
#include <QtCore/qapplicationstatic.h>
#include <QQuickWindow>
#include "Utilities/QTCLoggingCategory.h"


namespace QTC {
QTC_LOGGING_CATEGORY(QTCMainWindowLog, "qtc.api.QTCMainWindow");

Q_APPLICATION_STATIC(QTCMainWindow, _QTCMainWindowInstance);


QTCMainWindow::QTCMainWindow(QObject *parent) : QObject{parent} {

    qCDebug(QTCMainWindowLog) << Q_FUNC_INFO;
}

QTCMainWindow *QTCMainWindow::instance()
{
    return _QTCMainWindowInstance();
}

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

void QTCMainWindow::createRootWindow(QQmlApplicationEnginePtr& engine)
{
    engine->load(QUrl(QStringLiteral("qrc:/qml/QTodoCalen/UI/MainWindow/MainWindow.qml")));
}



}  // namespace QTC
