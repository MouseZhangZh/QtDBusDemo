/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp demo.xml -i mytype.h -p MyTypeInterface
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef MYTYPEINTERFACE_H
#define MYTYPEINTERFACE_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include "mytype.h"

/*
 * Proxy class for interface a.b.c.d
 */
class ABCDInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "a.b.c.d"; }

public:
    ABCDInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    ~ABCDInterface();

    Q_PROPERTY(QString nickname READ nickname WRITE setNickname)
    inline QString nickname() const
    { return qvariant_cast< QString >(property("nickname")); }
    inline void setNickname(const QString &value)
    { setProperty("nickname", QVariant::fromValue(value)); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> hello(MyType MyType)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(MyType);
        return asyncCallWithArgumentList(QStringLiteral("hello"), argumentList);
    }

    inline QDBusPendingReply<QDBusVariant> helloJerry(const QString &name)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(name);
        return asyncCallWithArgumentList(QStringLiteral("helloJerry"), argumentList);
    }

    inline QDBusPendingReply<QDBusVariant> helloTom()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("helloTom"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void sayHello();
};

namespace a {
  namespace b {
    namespace c {
      typedef ::ABCDInterface d;
    }
  }
}
#endif