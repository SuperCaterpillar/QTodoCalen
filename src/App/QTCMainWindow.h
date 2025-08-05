#ifndef QTCCOREPLUGIN_H
#define QTCCOREPLUGIN_H

#include <QtWidgets/QApplication>

#include "constants/QTCConstants.h"

namespace QTC {
class QTCMainWindow : public QObject {
  Q_OBJECT
 public:
  explicit QTCMainWindow(QObject *parent = nullptr);

  virtual QQmlApplicationEnginePtr createQmlApplicationEngine(QObject *parent);
  virtual void createRootWindow(QQmlApplicationEnginePtr engine);
 
  signals:

//  private:
//   QQmlApplicationEnginePtr _qmlAppEngine = nullptr;
//   QQuickWindowPtr _mainRootWindow = nullptr;
};
}  // namespace QTC

#endif  // QTCCOREPLUGIN_H
