#ifndef QOC_GLOBAL_H
#define QOC_GLOBAL_H

#include <qglobal.h>



#ifdef QWT_DLL

#if defined(QWT_MAKEDLL)     // create a Qwt DLL library
#define QOC_EXPORT Q_DECL_EXPORT
#else                        // use a Qwt DLL library
#define QOC_EXPORT Q_DECL_IMPORT
#endif

#endif // QWT_DLL

#ifndef QWT_EXPORT
#define QWT_EXPORT
#endif

// #define QWT_NO_COMPAT 1 // disable withdrawn functionality

#endif
