#include "qoc_axis.h"
#include "qoc_abstract_chart.h"

#include <QPainter>
#include <QtCore/qmath.h>

const int nWidth = 2;
const qreal fTheta = M_PI/6;

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

	// Drawing Arrow -- don't touch
	QPointF lineVector = m_end - m_begin;
	qreal lineLength = qSqrt(qPow(lineVector.x(), 2) + qPow(lineVector.y(), 2));
	qreal tPointOnLine = nWidth / (2 * (qTan(fTheta) / 2) * lineLength);
	QPointF pointOnLine = m_end + -tPointOnLine * lineVector;
	QPointF normalVector = QPointF(-lineVector.y(), lineVector.x());
	qreal tNormal = nWidth / (2 * lineLength);
	QPointF leftPoint = pointOnLine + tNormal * normalVector;
	QPointF rightPoint = pointOnLine + -tNormal * normalVector;
	QPolygonF arrow;
	arrow.clear();
	arrow << m_chart->mapToGlobal(m_end);
	arrow << m_chart->mapToGlobal(leftPoint);
	arrow << m_chart->mapToGlobal(rightPoint);

	p->setBrush(p->pen().color());
	p->drawPolygon(arrow);

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

qreal QocAxis::minValue() const
{
	return m_min;
}

void QocAxis::setMinValue(qreal v)
{
	if ( m_min != v )
	{
		m_min = v;
		emit minValueChanged(v);
	}
}

qreal QocAxis::maxValue() const
{
	return m_max;
}

void QocAxis::setMaxValue(qreal v)
{
	if ( m_max != v )
	{
		m_max = v;
		emit maxValueChanged(v);
	}
}

QPointF QocAxis::valueToPos(qreal v)
{
	QPointF vector = m_end - m_begin;
	vector.rx() = qAbs(vector.x());
	vector.ry() = qAbs(vector.y());
	vector *= (v - m_min) / (m_max - m_min);
//	qSqrt(qPow(vector.x(), 2) + qPow(vector.y(), 2));
	return QPointF(m_begin.x() + vector.x(), m_begin.y() - vector.y());
}

