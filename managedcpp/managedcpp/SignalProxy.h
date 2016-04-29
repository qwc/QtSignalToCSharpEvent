#ifndef SIGNALPROXY_H
#define SIGNALPROXY_H

#include <QObject>
#include "../pureqt/PureQt.h"
#include "ManagedCppQt.h"

using namespace System;
//using namespace ManagedCppQtSpace;

//ref class ManagedCppQt;

typedef void (*signalCallbackProxy) (QString str);

class SignalProxy : public QObject
{
    Q_OBJECT

public:
    explicit SignalProxy(PureQt* pqt);
    ~SignalProxy();
    //void setCallback(ManagedCppQt^ const cbObj);
signals:
public slots:
    void someFuncSlot(QString str);
private:
    PureQt* pureQt;
    signalCallbackProxy scallback;
//	gcroot<ManagedCppQt^> mgmdCppQtObj;
};

#endif // SIGNALPROXY_H
