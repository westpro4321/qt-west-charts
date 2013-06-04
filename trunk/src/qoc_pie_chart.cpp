#include "qoc_pie_chart.h"
#include "qoc_abstract_chart_item.h"

#include <QPainter>
#include <QWidget>

QocPieChart::QocPieChart(QObject *parent) :
	QObject(parent),
	m_antialiased(true),
	m_backgroundBrush(0),
	m_xMargin(0),
	m_yMargin(0),
	m_startAngle(16*90)
{
}

void QocPieChart::draw(QPainter *p, const QRectF &r)
{
	m_printRect = r;

	if ( p->isActive() )
	{
		QRectF rect = getPrintRect(r);

		p->save();
		p->setRenderHint(QPainter::Antialiasing, m_antialiased);

		if ( m_backgroundBrush )
		{
			p->setBackground(*m_backgroundBrush);
			p->fillRect(r, *m_backgroundBrush);
		}

		foreach(QocPieSector *i, m_items)
		{
			i->draw(p, rect);
		}

		p->restore();
	}
}

void QocPieChart::setSeries(QocDataSeries<QPointF> *ds)
{
	QocDataSeriesOwner<QPointF>::setSeries(ds);

	m_items.clear();
	int startAngle = 0/*m_startAngle*/;

	foreach(QPointF p, m_series->samples())
	{
		QocPieSector *ps = new QocPieSector("Untitled", this);
		ps->setStartAngle(startAngle);
		int spanAngle = (-1) * fullCircle * p.y() / m_series->sumOfValues();
		ps->setSpanAngle(spanAngle);
		startAngle += spanAngle;
		m_items.append(ps);
	}
}

bool QocPieChart::isAntialiased()
{
	return m_antialiased;
}

void QocPieChart::setAntialiased(bool b)
{
	m_antialiased = b;
}

QBrush QocPieChart::background() const
{
	return *m_backgroundBrush;
}

void QocPieChart::setBackground(QBrush *brush)
{
	delete m_backgroundBrush;
	m_backgroundBrush = brush;
}

double QocPieChart::xMargin()
{
	return m_xMargin;
}


void QocPieChart::setXMargin(double fraction)
{
	Q_ASSERT(0.0 <= fraction && fraction <= 0.5);

	m_xMargin = fraction;
}

double QocPieChart::yMargin()
{
	return m_yMargin;
}

void QocPieChart::setYMargin(double fraction)
{
	Q_ASSERT(0.0 <= fraction && fraction <= 0.5);

	m_yMargin = fraction;
}

void QocPieChart::setMargins(double x, double y)
{
	setXMargin(x);
	setYMargin(y);
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

void QocPieChart::repaint()
{
	QPainter p;
	draw(&p, m_printRect);
}

int QocPieChart::startAngle()
{
	return m_startAngle;
}

void QocPieChart::setStartAngle(int start)
{
	if ( m_startAngle != start )
	{
		m_startAngle = start;
		repaint();
	}
}

QRectF QocPieChart::getPrintRect(const QRectF &r)
{
	QRectF retVal;

	retVal.setX(r.x() + r.width() * m_xMargin);
	retVal.setY(r.y() + r.height() * m_yMargin);
	retVal.setWidth(r.width() - 2 * r.width() * m_xMargin);
	retVal.setHeight(r.height() - 2 * r.height() * m_yMargin);

	return retVal;
}
