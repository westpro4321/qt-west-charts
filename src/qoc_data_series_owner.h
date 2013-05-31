#ifndef QOCDATASERIESOWNER_H
#define QOCDATASERIESOWNER_H

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
#endif // QOCDATASERIESOWNER_H
