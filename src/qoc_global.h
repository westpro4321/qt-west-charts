#include <QtCore/QtGlobal>

#if defined(QOC_LIBRARY)
#  define QOC_API Q_DECL_EXPORT
#else
#  define QOC_API Q_DECL_IMPORT
#endif
