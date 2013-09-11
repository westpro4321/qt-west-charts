#include "qoc_data_series.h"

QocDataSeries::QocDataSeries(QObject *parent) :
	QObject(parent)
{
}

QString QocDataSeries::title() const
{
	return m_title;
}

void QocDataSeries::setTitle(const QString &s)
{
	if ( m_title != s )
	{
		m_title = s;
		emit titleChanged(s);
	}
}

QColor QocDataSeries::color() const
{
	m_color;
}

void QocDataSeries::setColor(const QColor &c)
{
	if ( m_color != c )
	{
		m_color = c;
		emit colorChanged(c);
	}
}
