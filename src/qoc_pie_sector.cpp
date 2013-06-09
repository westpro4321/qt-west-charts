#include "qoc_pie_sector.h"
#include "qoc_pie_chart.h"

#include <QPainter>
#include <QtCore/qmath.h>
#include <QDebug>
#include <QPointF>

const int g_fullCircle = 5760;
const int g_titleMargin = 10; //px
const int g_startAngle = 16*90;


QocPieSector::QocPieSector(const QString &title, QObject *parent) :
	QocAbstractChartItem(title, parent),
	m_chart(qobject_cast<QocPieChart *>(parent)),
	m_startAngle(0),
	m_spanAngle(0),
	m_offset(0),
	m_mode(TitlePercentMode)
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
	painter->drawPie(r, g_startAngle + m_chart->startAngle() + m_startAngle, m_spanAngle);

	painter->restore();
}

void QocPieSector::drawTitle(QPainter *painter, const QRectF &rect)
{
	if ( m_titleVisible )
	{
		painter->save();

		QString label;

		switch ( m_mode )
		{
			case TitleOnlyMode:
				label = m_title;
				break;

			case PercentOnlyMode:
				label = QString::number(percentage(), 'g', 4) + "%";
				break;

			case TitlePercentMode:
				label = m_title + QString("\n") + QString::number(percentage(), 'g', 4) + "%";
				break;
		}

		QRectF r = getTitleRect(rect);
		qDebug() << Q_FUNC_INFO << r; ;
		painter->drawText(r, label);

		painter->restore();
	}
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

QocPieSector::LabelMode QocPieSector::labelMode() const
{
	return m_mode;
}

void QocPieSector::setLabelMode(QocPieSector::LabelMode mode)
{
	m_mode = mode;
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
	double alfa = g_startAngle + m_chart->startAngle() + m_startAngle + m_spanAngle / 2;

	retVal.setX(rect.x() + qCos(2 * alfa / g_fullCircle * M_PI) * offset());
	retVal.setY(rect.y() - qSin(2 * alfa / g_fullCircle * M_PI) * offset());

	retVal.setWidth(rect.width());
	retVal.setHeight(rect.height());

	return retVal;
}

QRectF QocPieSector::getTitleRect(const QRectF &rect)
{
	QRectF retVal;
	double alfa = g_startAngle + m_chart->startAngle() + m_startAngle + m_spanAngle / 2;

	retVal.setX(rect.center().x() + qCos(2 * alfa / g_fullCircle * M_PI) * rect.width() / 2);
	retVal.setY(rect.center().y() - qSin(2 * alfa / g_fullCircle * M_PI) * rect.height() / 2);

	retVal.setX(retVal.x() + qCos(2 * alfa / g_fullCircle * M_PI) * (g_titleMargin + m_offset));
	retVal.setY(retVal.y() - qSin(2 * alfa / g_fullCircle * M_PI) * (g_titleMargin + m_offset));
	retVal.setWidth(100);
	retVal.setHeight(100);

	return retVal;
}

double QocPieSector::percentage()
{
	return qAbs(static_cast<double>(m_spanAngle)) / g_fullCircle * 100;
}
