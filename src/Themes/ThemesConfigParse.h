#pragma once
#include <QColor>
#include <QObject>
#include <QSize>
#include <QString>
#include <nlohmann/json.hpp>

// using json = nlohmann::json;

namespace QTC {
namespace ThemeConfig {
class IconData : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString source READ source WRITE setSource NOTIFY sourceChanged)
 public:
  explicit IconData(QObject *parent = nullptr) : QObject(parent) {}
  QString source() const { return m_source; }
  void setSource(const QString &src) {
    if (m_source != src) {
      m_source = src;
      emit sourceChanged();
    }
  }

  void fromJson(const nlohmann::json &j) {
    if (j.contains("source")) setSource(QString::fromStdString(j["source"]));
  }
  nlohmann::json toJson() const { return {{"source", m_source.toStdString()}}; }

 signals:
  void sourceChanged();

 private:
  QString m_source;
};

// ======================= Title 数据 =======================
class TitleData : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
  Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
  Q_PROPERTY(int fontSize READ fontSize WRITE setFontSize NOTIFY fontSizeChanged)
 public:
  explicit TitleData(QObject *parent = nullptr) : QObject(parent) {}
  QString text() const { return m_text; }
  void setText(const QString &t) {
    if (m_text != t) {
      m_text = t;
      emit textChanged();
    }
  }
  QColor color() const { return m_color; }
  void setColor(const QColor &c) {
    if (m_color != c) {
      m_color = c;
      emit colorChanged();
    }
  }
  int fontSize() const { return m_fontSize; }
  void setFontSize(int fs) {
    if (m_fontSize != fs) {
      m_fontSize = fs;
      emit fontSizeChanged();
    }
  }

  void fromJson(const nlohmann::json &j) {
    if (j.contains("text")) setText(QString::fromStdString(j["text"]));
    if (j.contains("color")) setColor(QColor(QString::fromStdString(j["color"])));
    if (j.contains("fontSize")) setFontSize(j["fontSize"].get<int>());
  }
  nlohmann::json toJson() const {
    return {{"text", m_text.toStdString()}, {"color", m_color.name().toStdString()}, {"fontSize", m_fontSize}};
  }

 signals:
  void textChanged();
  void colorChanged();
  void fontSizeChanged();

 private:
  QString m_text;
  QColor m_color;
  int m_fontSize = 0;
};

// ======================= 按钮数据 =======================
class ButtonData : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString normal READ normal WRITE setNormal NOTIFY normalChanged)
  Q_PROPERTY(QString hover READ hover WRITE setHover NOTIFY hoverChanged)
  Q_PROPERTY(QString pressed READ pressed WRITE setPressed NOTIFY pressedChanged)
 public:
  explicit ButtonData(QObject *parent = nullptr) : QObject(parent) {}
  QString normal() const { return m_normal; }
  void setNormal(const QString &v) {
    if (m_normal != v) {
      m_normal = v;
      emit normalChanged();
    }
  }
  QString hover() const { return m_hover; }
  void setHover(const QString &v) {
    if (m_hover != v) {
      m_hover = v;
      emit hoverChanged();
    }
  }
  QString pressed() const { return m_pressed; }
  void setPressed(const QString &v) {
    if (m_pressed != v) {
      m_pressed = v;
      emit pressedChanged();
    }
  }

  void fromJson(const nlohmann::json &j) {
    if (j.contains("normal")) setNormal(QString::fromStdString(j["normal"]));
    if (j.contains("hover")) setHover(QString::fromStdString(j["hover"]));
    if (j.contains("pressed")) setPressed(QString::fromStdString(j["pressed"]));
  }
  nlohmann::json toJson() const {
    return {{"normal", m_normal.toStdString()}, {"hover", m_hover.toStdString()}, {"pressed", m_pressed.toStdString()}};
  }

 signals:
  void normalChanged();
  void hoverChanged();
  void pressedChanged();

 private:
  QString m_normal, m_hover, m_pressed;
};

// ======================= Items 数据 =======================
class ItemsData : public QObject {
  Q_OBJECT
  Q_PROPERTY(IconData *icon READ icon CONSTANT)
  Q_PROPERTY(TitleData *title READ title CONSTANT)
  Q_PROPERTY(ButtonData *minimizeButton READ minimizeButton CONSTANT)
  Q_PROPERTY(ButtonData *maximizeButton READ maximizeButton CONSTANT)
  Q_PROPERTY(ButtonData *closeButton READ closeButton CONSTANT)
 public:
  explicit ItemsData(QObject *parent = nullptr) : QObject(parent) {
    m_icon = new IconData(this);
    m_title = new TitleData(this);
    m_minimizeButton = new ButtonData(this);
    m_maximizeButton = new ButtonData(this);
    m_closeButton = new ButtonData(this);
  }
  IconData *icon() const { return m_icon; }
  TitleData *title() const { return m_title; }
  ButtonData *minimizeButton() const { return m_minimizeButton; }
  ButtonData *maximizeButton() const { return m_maximizeButton; }
  ButtonData *closeButton() const { return m_closeButton; }

  void fromJson(const nlohmann::json &j) {
    if (j.contains("icon")) m_icon->fromJson(j["icon"]);
    if (j.contains("title")) m_title->fromJson(j["title"]);
    if (j.contains("minimizeButton")) m_minimizeButton->fromJson(j["minimizeButton"]);
    if (j.contains("maximizeButton")) m_maximizeButton->fromJson(j["maximizeButton"]);
    if (j.contains("closeButton")) m_closeButton->fromJson(j["closeButton"]);
  }
  nlohmann::json toJson() const {
    return {{"icon", m_icon->toJson()},
            {"title", m_title->toJson()},
            {"minimizeButton", m_minimizeButton->toJson()},
            {"maximizeButton", m_maximizeButton->toJson()},
            {"closeButton", m_closeButton->toJson()}};
  }

 private:
  IconData *m_icon;
  TitleData *m_title;
  ButtonData *m_minimizeButton;
  ButtonData *m_maximizeButton;
  ButtonData *m_closeButton;
};

// ======================= TitleBar 数据 =======================
class TitleBarData : public QObject {
  Q_OBJECT
  Q_PROPERTY(double opacity READ opacity WRITE setOpacity NOTIFY opacityChanged)
  Q_PROPERTY(int height READ height WRITE setHeight NOTIFY heightChanged)
  Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor NOTIFY backgroundColorChanged)
  Q_PROPERTY(QColor textColor READ textColor WRITE setTextColor NOTIFY textColorChanged)
  Q_PROPERTY(int fontSize READ fontSize WRITE setFontSize NOTIFY fontSizeChanged)
  Q_PROPERTY(int radius READ radius WRITE setRadius NOTIFY radiusChanged)
  Q_PROPERTY(QString mode READ mode WRITE setMode NOTIFY modeChanged)
  Q_PROPERTY(ItemsData *items READ items CONSTANT)
 public:
  explicit TitleBarData(QObject *parent = nullptr) : QObject(parent) { m_items = new ItemsData(this); }
  double opacity() const { return m_opacity; }
  void setOpacity(double v) {
    if (m_opacity != v) {
      m_opacity = v;
      emit opacityChanged();
    }
  }
  int height() const { return m_height; }
  void setHeight(int v) {
    if (m_height != v) {
      m_height = v;
      emit heightChanged();
    }
  }
  QColor backgroundColor() const { return m_backgroundColor; }
  void setBackgroundColor(const QColor &c) {
    if (m_backgroundColor != c) {
      m_backgroundColor = c;
      emit backgroundColorChanged();
    }
  }
  QColor textColor() const { return m_textColor; }
  void setTextColor(const QColor &c) {
    if (m_textColor != c) {
      m_textColor = c;
      emit textColorChanged();
    }
  }
  int fontSize() const { return m_fontSize; }
  void setFontSize(int fs) {
    if (m_fontSize != fs) {
      m_fontSize = fs;
      emit fontSizeChanged();
    }
  }
  int radius() const { return m_radius; }
  void setRadius(int r) {
    if (m_radius != r) {
      m_radius = r;
      emit radiusChanged();
    }
  }
  QString mode() const { return m_mode; }
  void setMode(const QString &m) {
    if (m_mode != m) {
      m_mode = m;
      emit modeChanged();
    }
  }
  ItemsData *items() const { return m_items; }

  void fromJson(const nlohmann::json &j) {
    if (j.contains("opacity")) setOpacity(j["opacity"].get<double>());
    if (j.contains("height")) setHeight(j["height"].get<int>());
    if (j.contains("backgroundColor")) setBackgroundColor(QColor(QString::fromStdString(j["backgroundColor"])));
    if (j.contains("textColor")) setTextColor(QColor(QString::fromStdString(j["textColor"])));
    if (j.contains("fontSize")) setFontSize(j["fontSize"].get<int>());
    if (j.contains("radius")) setRadius(j["radius"].get<int>());
    if (j.contains("mode")) setMode(QString::fromStdString(j["mode"]));
    if (j.contains("items")) m_items->fromJson(j["items"]);
  }
  nlohmann::json toJson() const {
    return {{"opacity", m_opacity},
            {"height", m_height},
            {"backgroundColor", m_backgroundColor.name().toStdString()},
            {"textColor", m_textColor.name().toStdString()},
            {"fontSize", m_fontSize},
            {"radius", m_radius},
            {"mode", m_mode.toStdString()},
            {"items", m_items->toJson()}};
  }

 signals:
  void opacityChanged();
  void heightChanged();
  void backgroundColorChanged();
  void textColorChanged();
  void fontSizeChanged();
  void radiusChanged();
  void modeChanged();

 private:
  double m_opacity = 1.0;
  int m_height = 0;
  QColor m_backgroundColor;
  QColor m_textColor;
  int m_fontSize = 0;
  int m_radius = 0;
  QString m_mode;
  ItemsData *m_items;
};

// ======================= MainWindow 数据 =======================
class MainWindowData : public QObject {
  Q_OBJECT
  Q_PROPERTY(int width READ width WRITE setWidth NOTIFY widthChanged)
  Q_PROPERTY(int height READ height WRITE setHeight NOTIFY heightChanged)
  Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor NOTIFY backgroundColorChanged)
  Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
  Q_PROPERTY(int radius READ radius WRITE setRadius NOTIFY radiusChanged)
  Q_PROPERTY(IconData *icon READ icon CONSTANT)
  Q_PROPERTY(TitleBarData *titleBar READ titleBar CONSTANT)
 public:
  explicit MainWindowData(QObject *parent = nullptr) : QObject(parent) {
    m_icon = new IconData(this);
    m_titleBar = new TitleBarData(this);
  }
  int width() const { return m_width; }
  void setWidth(int v) {
    if (m_width != v) {
      m_width = v;
      emit widthChanged();
    }
  }
  int height() const { return m_height; }
  void setHeight(int v) {
    if (m_height != v) {
      m_height = v;
      emit heightChanged();
    }
  }
  QColor backgroundColor() const { return m_backgroundColor; }
  void setBackgroundColor(const QColor &c) {
    if (m_backgroundColor != c) {
      m_backgroundColor = c;
      emit backgroundColorChanged();
    }
  }
  QString title() const { return m_title; }
  void setTitle(const QString &t) {
    if (m_title != t) {
      m_title = t;
      emit titleChanged();
    }
  }
  int radius() const { return m_radius; }
  void setRadius(int r) {
    if (m_radius != r) {
      m_radius = r;
      emit radiusChanged();
    }
  }
  IconData *icon() const { return m_icon; }
  TitleBarData *titleBar() const { return m_titleBar; }

  void fromJson(const nlohmann::json &j) {
    if (j.contains("width")) setWidth(j["width"].get<int>());
    if (j.contains("height")) setHeight(j["height"].get<int>());
    if (j.contains("backgroundColor")) setBackgroundColor(QColor(QString::fromStdString(j["backgroundColor"])));
    if (j.contains("title")) setTitle(QString::fromStdString(j["title"]));
    if (j.contains("radius")) setRadius(j["radius"].get<int>());
    if (j.contains("icon")) m_icon->fromJson(j["icon"]);
    if (j.contains("QTCTitleBar")) m_titleBar->fromJson(j["QTCTitleBar"]);
  }
  nlohmann::json toJson() const {
    return {{"width", m_width},
            {"height", m_height},
            {"backgroundColor", m_backgroundColor.name().toStdString()},
            {"title", m_title.toStdString()},
            {"radius", m_radius},
            {"icon", m_icon->toJson()},
            {"QTCTitleBar", m_titleBar->toJson()}};
  }

 signals:
  void widthChanged();
  void heightChanged();
  void backgroundColorChanged();
  void titleChanged();
  void radiusChanged();

 private:
  int m_width = 0;
  int m_height = 0;
  QColor m_backgroundColor;
  QString m_title;
  int m_radius = 0;
  IconData *m_icon;
  TitleBarData *m_titleBar;
};

// ======================= Global 数据 =======================
class GlobalData : public QObject {
  Q_OBJECT
  Q_PROPERTY(int radius READ radius WRITE setRadius NOTIFY radiusChanged)
  Q_PROPERTY(double opacity READ opacity WRITE setOpacity NOTIFY opacityChanged)
 public:
  explicit GlobalData(QObject *parent = nullptr) : QObject(parent) {}
  int radius() const { return m_radius; }
  void setRadius(const int &c) {
    if (m_radius != c) {
      m_radius = c;
      emit radiusChanged();
    }
  }
  double opacity() const { return m_opacity; }
  void setOpacity(double v) {
    if (m_opacity != v) {
      m_opacity = v;
      emit opacityChanged();
    }
  }

  void fromJson(const nlohmann::json &j) {
    if (j.contains("radius")) setRadius(j["radius"].get<int>());
    if (j.contains("opacity")) setOpacity(j["opacity"].get<double>());
  }
  nlohmann::json toJson() const { return {{"radius", m_radius}, {"opacity", m_opacity}}; }

 signals:
  void radiusChanged();
  void opacityChanged();

 private:
  int m_radius;
  double m_opacity = 1.0;
};

class ThemeData : public QObject {
  Q_OBJECT
  Q_PROPERTY(GlobalData *global READ global CONSTANT)
  Q_PROPERTY(MainWindowData *mainWindow READ mainWindow CONSTANT)
 public:
  explicit ThemeData(QObject *parent = nullptr) : QObject(parent) {
    m_global = new GlobalData(this);
    m_mainWindow = new MainWindowData(this);
  }

  GlobalData *global() const { return m_global; }
  MainWindowData *mainWindow() const { return m_mainWindow; }
  void fromJson(const nlohmann::json &j);

  nlohmann::json toJson() const;

 private:
  GlobalData *m_global;
  MainWindowData *m_mainWindow;
};

}  // namespace ThemeConfig
}  // namespace QTC
