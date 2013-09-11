#ifndef QOC_GLOBAL_H
#define QOC_GLOBAL_H

#include <QtCore/QtGlobal>

#if defined(QOC_LIBRARY)
#  define QOC_API Q_DECL_EXPORT
#else
#  define QOC_API Q_DECL_IMPORT
#endif

namespace Qoc {

	enum ItemDataRole {
		SeriesTitleRole,
		SeriesColorRole,
		XValueRole,
		YValueRole,
		ZValueRole,
		TitleRole,
		ColorRole,
		CustomRole
	};
}

#endif // QOC_GLOBAL_H
