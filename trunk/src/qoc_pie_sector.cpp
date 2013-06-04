#include "qoc_pie_sector.h"
#include "qoc_pie_chart.h"

#include <QPainter>
#include <QtCore/qmath.h>
#include <QDebug>

const int fullCircle = 5760;

QocPieSector::QocPieSector(const QString &title, QObject *parent) :
	QocAbstractChartItem(title, parent),
	m_chart(qobject_cast<QocPieChart *>(parent)),
	m_startAngle(0),
	m_spanAngle(0),
	m_offset(0)
{
	qDebug() << Q_FUNC_INFO << metaObject()->propertyOffset();
}

void QocPieSector::draw(QPainter *painter, const QRectF &rect)
{
	painter->save();
	painter->setPen(*m_pen);
	painter->setBrush(*m_brush);

	QRectF r = rect;
	if ( m_offset )
	{
		r = getRectWithOffset(rect);
	}
	painter->drawPie(r, m_chart->startAngle() + m_startAngle, m_spanAngle);

	painter->restore();
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

QRectF QocPieSector::boundingRect() const
{
	return QRect();
}

uint QocPieSector::offset()
{
	return m_offset;
}

void QocPieSector::setOffset(uint pix)
{
	if ( m_offset != pix )
	{
		m_offset = pix;
		m_chart->repaint();
	}
}

QRectF QocPieSector::getRectWithOffset(const QRectF &rect)
{
	QRectF retVal;
	double alfa = m_chart->startAngle() + m_startAngle + m_spanAngle / 2;

	retVal.setX(rect.x() + qCos(2 * alfa / fullCircle * M_PI) * offset());
	retVal.setY(rect.y() - qSin(2 * alfa / fullCircle * M_PI) * offset());

	retVal.setWidth(rect.width());
	retVal.setHeight(rect.height());

	return retVal;
}
