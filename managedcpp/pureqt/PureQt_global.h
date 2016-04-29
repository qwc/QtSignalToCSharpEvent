#ifndef MANAGEDCPP_GLOBAL_H
#define MANAGEDCPP_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MANAGEDCPPQT_LIBRARY)
#  define PUREQTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PUREQTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // MANAGEDCPP_GLOBAL_H
