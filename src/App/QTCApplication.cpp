#include "QTCApplication.h"
#include <QSharedPointer>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include "App/QTCMainWindow.h"
#include <QQuickStyle>
#include "Themes/ThemeManager.h"
 #include <QQmlContext>



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

  ThemeConfig::ThemeManager::instance()->loadTheme(":/themes/dark.json");

  _qmlAppEngine = QTCMainWindow::instance()->createQmlApplicationEngine(this);
  _qmlAppEngine->rootContext()->setContextProperty(QStringLiteral("ThemesManager"), ThemeConfig::ThemeManager::instance());
  QObject::connect(_qmlAppEngine.data(), &QQmlApplicationEngine::objectCreationFailed, this, QCoreApplication::quit, Qt::QueuedConnection);

  QTCMainWindow::instance()->createRootWindow(_qmlAppEngine);
  QTCLoggingCategoryRegister::instance()->setFilterRulesFromSettings("full");
  qCDebug(QGCApplicationLog) << "init start";
}

} // namespace QTC
