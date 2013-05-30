#include "qoc_abstract_chart.h"

QocAbstractChart::QocAbstractChart(QObject *parent) :
	QObject(parent),
	m_series(0)
{
}

void QocAbstractChart::setSeries(QocDataSeries *ds)
{
	delete m_series;
	m_series = ds;
}

void QocAbstractChart::addItem(QocAbstractChartItem *item)
{
	m_items.append(item);
}

bool QocAbstractChart::removeItem(QocAbstractChartItem *item)
{
	return m_items.removeOne(item);
}
