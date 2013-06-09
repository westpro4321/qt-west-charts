#include "qoc_pie_chart.h"
#include "qoc_abstract_chart_item.h"

#include <QPainter>
#include <QWidget>

QocPieChart::QocPieChart(QObject *parent) :
	QocAbstractChart(parent),
	m_startAngle(0)
{
}

void QocPieChart::draw(QPainter *p, const QRectF &r)
{
	m_printRect = r;
	m_itemsRect = getItemsRect(r);

	if ( p->isActive() )
	{
		p->save();
		p->setRenderHint(QPainter::Antialiasing, m_antialiased);

		drawBackground(p, r);
		drawItems(p, m_itemsRect);
		drawTitle(p, r);

		p->restore();
	}
}

QList<QocPieSector *> QocPieChart::items()
{
	return m_items;
}

void QocPieChart::setSeries(QocDataSeries<QPointF> *ds)
{
	QocDataSeriesOwner<QPointF>::setSeries(ds);

	m_items.clear();
	int startAngle = 0/*m_startAngle*/;

	foreach(QPointF p, m_series->samples())
	{
		QocPieSector *ps = new QocPieSector(QString("Untitled %1").arg(m_items.size()), this);
		ps->setStartAngle(startAngle);
		int spanAngle = (-1) * g_fullCircle * p.y() / m_series->sumOfValues();
		ps->setSpanAngle(spanAngle);
		startAngle += spanAngle;
		m_items.append(ps);
	}
}




QocPieSector *QocPieChart::item(double x)
{
	for(int i=0; i<m_series->size(); ++i)
	{
		if ( m_series->sample(i).x() == x )
		{
			return m_items.at(i);
		}
	}
	return 0;
}

QocPieSector *QocPieChart::itemAt(size_t i)
{
	return m_items.at(i);
}

void QocPieChart::repaint()
{
	QPainter p;
	draw(&p, m_printRect);
}

int QocPieChart::startAngle() const
{
	return m_startAngle;
}

QRectF QocPieChart::printRect() const
{
	return m_printRect;
}

QRectF QocPieChart::itemsRect() const
{
	return m_itemsRect;
}

void QocPieChart::setStartAngle(int start)
{
	if ( m_startAngle != start )
	{
		m_startAngle = start;
		repaint();
	}
}

void QocPieChart::drawBackground(QPainter *painter, const QRectF &rect)
{
	if ( m_backgroundBrush )
	{
		painter->setBackground(*m_backgroundBrush);
		painter->fillRect(rect, *m_backgroundBrush);
	}
}

void QocPieChart::drawItems(QPainter *painter, const QRectF &rect)
{
	foreach(QocPieSector *i, m_items)
	{
		if ( i->isVisible() && ! i->isSelected() )
			i->draw(painter, rect);
	}

	foreach(QocPieSector *i, m_items)
	{
		if ( i->isVisible() && i->isSelected() )
			i->draw(painter, rect);
	}

	foreach(QocPieSector *i, m_items)
	{
		if ( i->isVisible() )
			i->drawTitle(painter, rect);
	}
}

void QocPieChart::drawTitle(QPainter *painter, const QRectF &rect)
{
	if ( m_titleVisible )
	{
		painter->setFont(m_titleFont);
		painter->drawText(rect, m_titleFlags, m_title);
	}
}

QRectF QocPieChart::getItemsRect(const QRectF &r)
{
	QRectF retVal;
	retVal.setWidth(r.width() - r.width() * (m_leftMargin + m_rightMargin));
	retVal.setHeight(r.height() - r.height() * (m_topMargin + m_bottomMargin));

	double length = qMin(retVal.width(), retVal.height());

	retVal.setX(r.x() + r.width() / 2 - length / 2);
	retVal.setY(r.y() + r.height() / 2 - length / 2);
	retVal.setWidth(length);
	retVal.setHeight(length);

	return retVal;
}
