#include "SignalProxy.h"

SignalProxy::SignalProxy(PureQt* pqt)
{
    pureQt = pqt;
    this->connect(pureQt, SIGNAL(PureQt::someFuncWasCalled(QString)), this, SLOT(someFuncSlot(QString)));
}

SignalProxy::~SignalProxy()
{}

//void SignalProxy::setCallback(ManagedCppQt^ cbObj)
//{
//    this->mgmdCppQtObj = cbObj;
//}

void SignalProxy::someFuncSlot(QString str)
{
    if(this->scallback != NULL)
        this->scallback(str);
    //mgmdCppQtObj->signalCallback(str);
}

