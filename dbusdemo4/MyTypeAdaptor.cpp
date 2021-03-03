/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp demo.xml -i mytype.h -a MyTypeAdaptor
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#include "MyTypeAdaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Implementation of adaptor class DAdaptor
 */

DAdaptor::DAdaptor(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

DAdaptor::~DAdaptor()
{
    // destructor
}

QString DAdaptor::nickname() const
{
    // get the value of property nickname
    return qvariant_cast< QString >(parent()->property("nickname"));
}

void DAdaptor::setNickname(const QString &value)
{
    // set the value of property nickname
    parent()->setProperty("nickname", QVariant::fromValue(value));
}

void DAdaptor::hello(MyType qqq)
{
    // handle method call a.b.c.d.hello
    QMetaObject::invokeMethod(parent(), "hello", Q_ARG(MyType, qqq));
}

QDBusVariant DAdaptor::helloJerry(const QString &name)
{
    // handle method call a.b.c.d.helloJerry
    QDBusVariant out0;
    QMetaObject::invokeMethod(parent(), "helloJerry", Q_RETURN_ARG(QDBusVariant, out0), Q_ARG(QString, name));
    return out0;
}

QDBusVariant DAdaptor::helloTom()
{
    // handle method call a.b.c.d.helloTom
    QDBusVariant out0;
    QMetaObject::invokeMethod(parent(), "helloTom", Q_RETURN_ARG(QDBusVariant, out0));
    return out0;
}

