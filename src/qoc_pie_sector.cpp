#include "qoc_pie_sector.h"

#include <QPainter>


QocPieSector::QocPieSector()
{
}

void QocPieSector::draw(QPainter *painter, const QRectF &rect)
{
	painter->drawPie(rect, m_startAngle, m_spanAngle);
}

int QocPieSector::startAngle() const
{
	return m_startAngle;
}

void QocPieSector::setStartAngle(int start)
{
	m_startAngle = start;
}

int QocPieSector::spanAngle() const
{
	return m_spanAngle;
}

void QocPieSector::setSpanAngle(int span)
{
	m_spanAngle = span;
}
