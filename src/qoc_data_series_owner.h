#ifndef QOC_DATA_SERIES_OWNER_H
#define QOC_DATA_SERIES_OWNER_H

#include "qoc_data_series.h"

template <typename T>
class QocDataSeriesOwner
{
public:
	QocDataSeriesOwner();

	virtual void setSeries(QocDataSeries<T> *ds);

protected:
	QocDataSeries<T> *m_series;
};

template <typename T>
QocDataSeriesOwner<T>::QocDataSeriesOwner() :
	m_series(0)
{
}

template <typename T>
void QocDataSeriesOwner<T>::setSeries(QocDataSeries<T> *ds)
{
	delete m_series;
	m_series = ds;
}
#endif // QOC_DATA_SERIES_OWNER_H
