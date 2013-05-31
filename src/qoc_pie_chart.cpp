#include "qoc_pie_chart.h"
#include "qoc_abstract_chart_item.h"

#include <QPainter>

QocPieChart::QocPieChart(QObject *parent) :
	QObject(parent)
{
}

void QocPieChart::draw(QPainter *p, const QRectF &rect)
{
	p->save();
	foreach(QocAbstractChartItem *i, m_items)
	{
		i->draw(p, rect);
	}

	p->restore();
}

void QocPieChart::setSeries(QocDataSeries<QPoint> *ds)
{
	QocDataSeriesOwner<QPoint>::setSeries(ds);

//	foreach(QPoint p, m_series->samples())
//	{
//		QocPieSector *ps = new QocPieSector();
//		ps->set
//		m_items.append();
//	}
}
