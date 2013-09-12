#include "qoc_axis.h"
#include "qoc_abstract_chart.h"

#include <QPainter>


QocAxis::QocAxis(QObject *parent) :
	QocAbstractChartItem(parent),
	m_begin(0, 0),
	m_end(0, 0)
{
}

QocAxis::QocAxis(const QPointF &begin, const QPointF &end, QObject *parent) :
	QocAbstractChartItem(parent),
	m_begin(begin),
	m_end(end)
{
}

void QocAxis::draw(QPainter *p, const QRectF &rect)
{
	Q_UNUSED(rect)

	p->save();

	p->drawLine(m_chart->mapToGlobal(m_begin), m_chart->mapToGlobal(m_end));

	p->restore();
}

QRectF QocAxis::boundingRect() const
{
	QPointF topLeft, bottomRight;
	topLeft.rx() = m_begin.x() <= m_end.x() ? m_begin.x() : m_end.x();
	topLeft.ry() = m_begin.y() <= m_end.y() ? m_begin.y() : m_end.y();
	bottomRight.rx() = m_begin.x() >= m_end.x() ? m_begin.x() : m_end.x();
	bottomRight.ry() = m_begin.y() >= m_end.y() ? m_begin.y() : m_end.y();

	return QRectF(topLeft, bottomRight);
}

