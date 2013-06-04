#ifndef QOC_DATA_SERIES_H
#define QOC_DATA_SERIES_H

#include <QVector>


template <typename T>
class QocDataSeries
{
public:
	QocDataSeries();

	void setSamples(const QVector<T> &samples);
	QVector<T> samples() const;

	virtual size_t size() const;
	virtual T sample( size_t index ) const;

	double sumOfValues();

protected:
	QVector<T> m_samples;
	double m_sum;
};

template <typename T>
QocDataSeries<T>::QocDataSeries()
{
}

template <typename T>
void QocDataSeries<T>::setSamples(const QVector<T> &samples)
{
	m_samples = samples;
	m_sum = 0;
	foreach(T t, samples)
	{
		m_sum += t.y();
	}
}

template <typename T>
QVector<T> QocDataSeries<T>::samples() const
{
	return m_samples;
}

template <typename T>
size_t QocDataSeries<T>::size() const
{
	return m_samples.size();
}

template <typename T>
T QocDataSeries<T>::sample(size_t index) const
{
	return m_samples.at(index);
}

template <typename T>
double QocDataSeries<T>::sumOfValues()
{
	return m_sum;
}
#endif // QOC_DATA_SERIES_H
