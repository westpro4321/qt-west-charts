#include "qoc_legend.h"
#include "qoc_pie_chart.h"
#include "qoc_pie_sector.h"

#include <QPainter>

const int g_margin = 10; //px

QocLegend::QocLegend(QObject *parent) :
	QObject(parent),
	m_chart(0),
	m_size(10, 10)
{
}

void QocLegend::draw(QPainter *p, const QRectF &rect)
{
	if ( m_chart )
	{
		p->save();
		p->setFont(m_font);

		for(int i=0; i< m_chart->items().size(); ++i)
		{
			p->setBrush(m_chart->items().at(i)->brush());
			p->drawRect(rect.x() + g_margin, rect.y() + (2 * g_margin + m_size.height()) * (i + 1),
						m_size.width(), m_size.height());
			p->drawText(rect.x() + 2 * g_margin + m_size.width(), rect.y() + m_size.height() +(2 * g_margin + m_size.height()) * (i + 1),
						m_chart->items().at(i)->title());
		}
		p->restore();
	}
}


void QocLegend::setChart(QocPieChart *chart)
{
	m_chart = chart;
}


QSize QocLegend::colorSize() const
{
	return m_size;
}

void QocLegend::setColorSize(QSize size)
{
	m_size = size;
}
