// ThemeManager.cpp
#include "ThemeManager.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>

namespace QTC {
namespace ThemeConfig {
using json = nlohmann::json;
QTC_LOGGING_CATEGORY(ThemeManagerLog, "qtc.themes.ThemeManager")

Q_GLOBAL_STATIC(ThemeManager, _ThemeManagerRegisterInstance);

ThemeManager *ThemeManager::instance() { return _ThemeManagerRegisterInstance(); }

bool ThemeManager::loadTheme(const QString &filePath) {
  QFile file(filePath);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
    qCWarning(ThemeManagerLog) << "Failed to open theme file:" << filePath;
    return false;
  }
  QTextStream in(&file);
  // in./*setCodec*/("UTF-8");
  QString jsonStr = in.readAll();
  file.close();
  try {
    json j = json::parse(jsonStr.toStdString());

    m_themeData->fromJson(j);
    return true;
  } catch (const nlohmann::json::parse_error &e) {
    qWarning() << "JSON parse error:" << e.what();
    return false;
  } catch (const std::exception &e) {
    qWarning() << "Other exception:" << e.what();
    return false;
  }
}

bool ThemeManager::saveTheme(const QString &filePath) {
  json j;
  j = m_themeData->toJson();

  QFile file(filePath);
  if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return false;
  QTextStream out(&file);
  out << QString::fromStdString(j.dump(4));
  file.close();
  return true;
}

}  // namespace ThemeConfig
}  // namespace QTC
