#ifndef QTCCONSTANTS_H
#define QTCCONSTANTS_H
#include <QSharedPointer>

class QQmlApplicationEngine;
class QQuickWindow;

namespace QTC {

#define QTC_DECL_SHARED_PTR(cls) typedef QSharedPointer<cls> cls##Ptr;

#define QTC_DECL_SHARED_CONST_PTR(cls) \
  typedef QSharedPointer<const cls> cls##ConstPtr;

#define QTC_CREATE_SHARED_PTR(cls, ...) QSharedPointer<cls>::create(__VA_ARGS__)

template<typename T, typename... Args>
QSharedPointer<T> qtc_create_shared_ptr(Args&&... args) {
    return QSharedPointer<T>::create(std::forward<Args>(args)...);
}

QTC_DECL_SHARED_PTR(QQmlApplicationEngine)
QTC_DECL_SHARED_CONST_PTR(QQmlApplicationEngine)
QTC_DECL_SHARED_PTR(QQuickWindow)
QTC_DECL_SHARED_CONST_PTR(QQuickWindow)

}  // namespace QTC

#endif  // !1