#include "qoc_bar_item.h"
#include "qoc_abstract_chart.h"
#include "qoc_bar_chart.h"

#include <QPainter>


const int _barWidth = 3;

QocBarItem::QocBarItem(QObject *parent) :
	QocAbstractValueItem(parent),
	m_height(0)
{
}

qreal QocBarItem::height() const
{
	return m_height;
}

void QocBarItem::setHeight(qreal h)
{
	if ( h != m_height )
	{
		m_height = h;
		emit heightChanged(h);
	}
}

void QocBarItem::draw(QPainter *painter, const QRectF &rect)
{
	painter->save();

	painter->setBrush(color());
	QRectF r(m_chart->mapToGlobal(boundingRect().topLeft()),
			 m_chart->mapToGlobal(boundingRect().bottomRight()));

	QocBarChart *chart = qobject_cast<QocBarChart *>(m_chart);
	painter->drawRoundedRect(r, chart->radius(), chart->radius());

	painter->restore();
}

QRectF QocBarItem::boundingRect() const
{
	if ( height() >= 0 )
		return QRectF(m_pos.x(), m_pos.y()+height(), _barWidth, height());
	return QRectF(m_pos.x(), m_pos.y(), _barWidth, height());
}
