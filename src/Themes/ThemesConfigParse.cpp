#include "ThemesConfigParse.h"
namespace QTC {
namespace ThemeConfig {

    void ThemeData::fromJson(const nlohmann::json &j) {
    if (j.contains("global")) m_global->fromJson(j["global"]);
    if (j.contains("QTCMainWindow")) m_mainWindow->fromJson(j["QTCMainWindow"]);
  }

  nlohmann::json ThemeData::toJson() const {
    return {{"global", m_global->toJson()}, {"QTCMainWindow", m_mainWindow->toJson()}};
  }
}
}  // namespace QTC