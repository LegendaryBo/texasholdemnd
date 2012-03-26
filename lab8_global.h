#ifndef LAB8_GLOBAL_H
#define LAB8_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LAB8_LIBRARY)
#  define LAB8SHARED_EXPORT Q_DECL_EXPORT
#else
#  define LAB8SHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LAB8_GLOBAL_H
