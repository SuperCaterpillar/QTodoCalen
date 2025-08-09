#pragma once
#include "ThemesConfigParse.h"
#include "Utilities/QTCLoggingCategory.h"
namespace QTC {
namespace ThemeConfig {

class ThemeManager : public QObject {
  Q_OBJECT
  Q_PROPERTY(ThemeData *themeData READ themeData WRITE setThemeData NOTIFY themeDataChanged)
 public:
  explicit ThemeManager(QObject *parent = nullptr) : QObject(parent), m_themeData(new ThemeData(this)) {
    // ThemeData 内部会初始化 GlobalData 和 MainWindowData
  }


  ThemeData *themeData() const { return m_themeData; }
  void setThemeData(ThemeData *data) {
    if (m_themeData == data) return;
    m_themeData = data;
    emit themeDataChanged();
  }

  Q_INVOKABLE bool loadTheme(const QString &filePath);
  Q_INVOKABLE bool saveTheme(const QString &filePath);

  static ThemeManager *instance();

 signals:
  void themeDataChanged();


 private:
  ThemeData *m_themeData;
};
}  // namespace ThemeConfig
}  // namespace QTC
