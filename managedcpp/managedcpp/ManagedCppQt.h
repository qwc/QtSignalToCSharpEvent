// ManagedCppQt.h

#pragma once
#include "conversion.h"
#include "../pureqt/PureQt.h"
//#include "SignalProxy.h"
#include <QObject>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;

namespace ManagedCppQtSpace {

    delegate void someFuncWasCalled(String^);
//    delegate void someFuncWasCalledU(QString str);

//    [StructLayoutAttribute(LayoutKind::Sequential)]
//    public ref struct DelegateWrapper {
//        [MarshalAsAttribute(UnmanagedType::FunctionPtr)]
//        someFuncWasCalledU^ delegate;
//    };

	public ref class ManagedCppQt
	{
	public:
        ManagedCppQt(String^ name){
			pureQtObject = new PureQt(StringToQString(name));
//            proxy = new SignalProxy(pureQtObject);
//			proxy->setCallback(this);
//            wrapper = gcnew DelegateWrapper();
//            wrapper->delegate = gcnew someFuncWasCalledU(this, &ManagedCppQt::signalCallback);
//            signalCallbackProxy callbackproxy;
//            Marshal::StructureToPtr(wrapper, callbackproxy, false);
//            QObject::connect(pureQtObject, &PureQt::someFuncWasCalled,
//                             &wrapper->delegate);
        };
        ~ManagedCppQt(){
            delete pureQtObject;
        };

        event someFuncWasCalled ^ someFuncCalled;

        void someFunc(String^ string){
			pureQtObject->someFunc(StringToQString(string));
        };

        String^ getSomeString() {
            return QStringToString(pureQtObject->getSomeVar());
        }

        void signalCallback(QString str)
        {
            someFuncCalled(QStringToString(str));
        }

//        DelegateWrapper ^ wrapper;

	private:
        PureQt * pureQtObject;
        //SignalProxy * proxy;
    };
}
