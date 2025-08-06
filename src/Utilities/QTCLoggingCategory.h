#pragma once

#include <QtCore/QLoggingCategory>
#include <QtCore/QObject>
#include <QtCore/QStringList>

/// This is a QGC specific replacement for Q_LOGGING_CATEGORY. It will register the category name into a
/// global list. It's usage is the same as Q_LOGGING_CATEOGRY.
#define QTC_LOGGING_CATEGORY(name, ...) \
    static QGCLoggingCategory qtcCategory ## name (__VA_ARGS__); \
    Q_LOGGING_CATEGORY(name, __VA_ARGS__)


class QTCLoggingCategoryRegister : public QObject
{
    Q_GADGET

public:
    static QTCLoggingCategoryRegister *instance();

    /// Registers the specified logging category to the system.
    void registerCategory(const QString &category) { _registeredCategories << category; }

    /// Returns the list of available logging category names.
    Q_INVOKABLE QStringList registeredCategories();

    /// Turns on/off logging for the specified category. State is saved in app settings.
    Q_INVOKABLE static void setCategoryLoggingOn(const QString &category, bool enable);

    /// Returns true if logging is turned on for the specified category.
    Q_INVOKABLE static bool categoryLoggingOn(const QString &category);

    /// Sets the logging filters rules from saved settings.
    ///     @param commandLineLogggingOptions Logging options which were specified on the command line
    void setFilterRulesFromSettings(const QString &commandLineLoggingOptions) const;

private:
    QStringList _registeredCategories;

    static constexpr const char *kFilterRulesSettingsGroup = "LoggingFilters";
    static constexpr const char *kAllLogCategory = "AllLog";
};

/*===========================================================================*/

class QGCLoggingCategory
{
public:
    QGCLoggingCategory(const QString &category) { QTCLoggingCategoryRegister::instance()->registerCategory(category); }
};
