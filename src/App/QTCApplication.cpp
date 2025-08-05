#include "QTCApplication.h"
#include <QSharedPointer>
#include <QQmlApplicationEngine>
#include <QQuickWindow>

namespace QTC {

QTCApplication::QTCApplication(int &argc, char *argv[]):QApplication(argc,argv) {
  QString applicationName = QGC_APP_NAME;
  setApplicationName(applicationName);
}

void QTCApplication::init()
{

}

} // namespace QTC