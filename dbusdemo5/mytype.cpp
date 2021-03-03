#include "mytype.h"

MyType::MyType(QString& name, int& age)
{
    this->s_name = name;
    this->i_age = age;
}

QDBusArgument& operator<<(QDBusArgument &argument, const MyType &message)
{
    argument.beginStructure();
    argument << "My name is " << message.s_name << " and I'm " << message.i_age << " years old.";
    argument.endStructure();
    return argument;
}

const QDBusArgument& operator>>(const QDBusArgument &argument, MyType &message)
{
    argument.beginStructure();
    argument >> message.s_name >> message.i_age;
    argument.endStructure();
    return argument;
}

void MyType::registerMetaType()
{
    qRegisterMetaType<MyType>("MyType");
    qDBusRegisterMetaType<MyType>();
}

