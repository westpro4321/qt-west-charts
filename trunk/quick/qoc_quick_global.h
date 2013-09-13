#ifndef QOC_QUICK_GLOBAL_H
#define QOC_QUICK_GLOBAL_H

#include <QtCore/QtGlobal>

#if defined(QOC_QUICK_LIBRARY)
#  define QOC_QUICK_API Q_DECL_EXPORT
#else
#  define QOC_QUICK_API Q_DECL_IMPORT
#endif

#endif // QOC_QUICK_GLOBAL_H
