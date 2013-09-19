#include "qoc_quick_bar_chart.h"

#include <qoc_bar_chart.h>


QocQuickBarChart::QocQuickBarChart(QObject *parent) :
	QocQuickAbstractChart(parent)
{
	QocBarChart *chart = new QocBarChart(this);
	m_chart = chart;

	connect(m_chart, SIGNAL(repaint()), this, SIGNAL(repaint()));

	connect(chart, SIGNAL(radiusChanged(qreal)), this, SIGNAL(radiusChanged(qreal)));
}

QocAxis *QocQuickBarChart::verticalAxis()
{
	return chart()->verticalAxis();
}

QocAxis *QocQuickBarChart::horizontalAxis()
{
	return chart()->horizontalAxis();
}

QQmlListProperty<QocBarItem> QocQuickBarChart::bars()
{
	return QQmlListProperty<QocBarItem>(this, 0,
										  &QocQuickBarChart::count_item,
										&QocQuickBarChart::at_item);
}

qreal QocQuickBarChart::radius() const
{
	return chart()->radius();
}

void QocQuickBarChart::setRadius(qreal r)
{
	chart()->setRadius(r);
}

QocBarChart *QocQuickBarChart::chart() const
{
	return qobject_cast<QocBarChart *>(m_chart);
}

QocBarItem *QocQuickBarChart::at_item(QQmlListProperty<QocBarItem> *list, int index)
{
	QocQuickBarChart *c = qobject_cast<QocQuickBarChart *>(list->object);
	if ( c )
	{
		return qobject_cast<QocBarItem *>(c->m_chart->items(QocAbstractChart::ChartLayer).at(index));
	}

	return 0;
}

int QocQuickBarChart::count_item(QQmlListProperty<QocBarItem> *list)
{
	QocQuickBarChart *c = qobject_cast<QocQuickBarChart *>(list->object);
	if ( c )
	{
		return c->m_chart->items(QocAbstractChart::ChartLayer).size();
	}
	return 0;
}
