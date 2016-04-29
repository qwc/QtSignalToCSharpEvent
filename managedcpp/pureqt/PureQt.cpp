#include "PureQt.h"

PureQt::PureQt(QString name)
{
    this->someVar = "ctor("+name+")";
}

QString PureQt::getSomeVar()
{
    return this->someVar;
}

void PureQt::someFunc(const QString &string)
{
    this->someVar += "someFunc("+string+")";
    emit someFuncWasCalled(this->someVar);
}
