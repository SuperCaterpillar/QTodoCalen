#include "QTCApplication.h"
#include <QSharedPointer>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include "App/QTCMainWindow.h"
#include <QQuickStyle>



namespace QTC {
QTC_LOGGING_CATEGORY(QGCApplicationLog, "qgc.QTCApplication")

QTCApplication::QTCApplication(int &argc, char *argv[]):QApplication(argc,argv) {
  QString applicationName = QGC_APP_NAME;

  setApplicationName(applicationName);
  setWindowIcon(QIcon(":/res/qtodocalen.ico"));
}

void QTCApplication::init()
{
  QQuickStyle::setStyle("Basic");
  QTCMainWindow::instance();
  _qmlAppEngine = QTCMainWindow::instance()->createQmlApplicationEngine(this);
  QObject::connect(_qmlAppEngine.data(), &QQmlApplicationEngine::objectCreationFailed, this, QCoreApplication::quit, Qt::QueuedConnection);

  QTCMainWindow::instance()->createRootWindow(_qmlAppEngine);
  QTCLoggingCategoryRegister::instance()->setFilterRulesFromSettings("full");
  qCDebug(QGCApplicationLog) << "init start";
}

} // namespace QTC
