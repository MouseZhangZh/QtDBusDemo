/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp com.scorpio.test.xml -p valueInterface
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef VALUEINTERFACE_H
#define VALUEINTERFACE_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface com.scorpio.test.value
 */
class ComScorpioTestValueInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "com.scorpio.test.value"; }

public:
    ComScorpioTestValueInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    ~ComScorpioTestValueInterface();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<int> maxValue()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("maxValue"), argumentList);
    }

    inline QDBusPendingReply<int> minValue()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("minValue"), argumentList);
    }

    inline QDBusPendingReply<int> value()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("value"), argumentList);
    }

Q_SIGNALS: // SIGNALS
};

namespace com {
  namespace scorpio {
    namespace test {
      typedef ::ComScorpioTestValueInterface value;
    }
  }
}
#endif
