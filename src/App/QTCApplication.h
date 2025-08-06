#ifndef QTCAPPLICATION_H
#define QTCAPPLICATION_H

#include <QtWidgets/QApplication>
#include "App/QTCMainWindow.h"
#include "Utilities/QTCLoggingCategory.h"

namespace QTC {
// Q_DECLARE_LOGGING_CATEGORY(QTCApplicationLog)
class QTCApplication : public QApplication
{
    Q_OBJECT
public:
    QTCApplication(int &argc, char *argv[]);

    void init();

    QQmlApplicationEnginePtr qmlAppEngine() const { return _qmlAppEngine; }

private:
    QSharedPointer<QQmlApplicationEngine> _qmlAppEngine = nullptr;
    QSharedPointer<QQuickWindow>_mainRootWindow = nullptr;
};

} // namespace QTC
#endif // QTCAPPLICATION_H
