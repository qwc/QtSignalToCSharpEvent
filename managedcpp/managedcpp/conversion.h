#pragma once

#include <QString>
#using <mscorlib.dll>
#include <vcclr.h>

using namespace System;

String^ QStringToString(const QString &qstring) {
    return gcnew String(qstring.toStdWString().c_str());
}

QString StringToQString(String^ string) {
    pin_ptr<const wchar_t> chars = &PtrToStringChars(string)[0];
    return QString::fromWCharArray(chars);
}
