#ifndef QOC_QUICK_DATA_SERIES_H
#define QOC_QUICK_DATA_SERIES_H

#include <qoc_data_series.h>

#include "qoc_quick_global.h"


class QOC_QUICK_API QocQuickDataSeries : public QocDataSeries
{
	Q_OBJECT
public:
	explicit QocQuickDataSeries(QObject *parent = 0);
	
signals:
	
public slots:
	
};

Q_DECLARE_METATYPE(QocQuickDataSeries *)

#endif // QOC_QUICK_DATA_SERIES_H
