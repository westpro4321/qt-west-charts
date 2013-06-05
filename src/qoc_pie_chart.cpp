#include "qoc_pie_chart.h"
#include "qoc_abstract_chart_item.h"

#include <QPainter>
#include <QWidget>

QocPieChart::QocPieChart(QObject *parent) :
	QObject(parent),
	m_antialiased(true),
	m_backgroundBrush(0),
	m_startAngle(16*90),
	m_title("Chart Title"),
	m_titleFont(QFont("Arial", 12, QFont::Normal)),
	m_titleVisible(true),
	m_titleFlags(Qt::AlignHCenter | Qt::AlignTop)
{
	setMargins(0.1, 0.05, 0.1, 0.2);
}

void QocPieChart::draw(QPainter *p, const QRectF &r)
{
	m_printRect = r;

	if ( p->isActive() )
	{
		QRectF itemsRect = getItemsRect(r);

		p->save();
		p->setRenderHint(QPainter::Antialiasing, m_antialiased);

		drawBackground(p, r);
		drawItems(p, itemsRect);
		drawTitle(p, r);

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
		QocPieSector *ps = new QocPieSector(QString("Untitled %1").arg(m_items.size()), this);
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

double QocPieChart::topMargin()
{
	return m_topMargin;
}


void QocPieChart::setTopMargin(double fraction)
{
	Q_ASSERT(0.0 <= fraction && fraction <= 1.0);

	m_topMargin = fraction;
}

double QocPieChart::bottomMargin()
{
	return m_bottomMargin;
}

void QocPieChart::setBottomMargin(double fraction)
{
	Q_ASSERT(0.0 <= fraction && fraction <= 1.0);

	m_bottomMargin = fraction;
}

double QocPieChart::leftMargin()
{
	return m_leftMargin;
}

void QocPieChart::setLeftMargin(double fraction)
{
	Q_ASSERT(0.0 <= fraction && fraction <= 1.0);

	m_leftMargin = fraction;
}

double QocPieChart::rightMargin()
{
	return m_rightMargin;
}

void QocPieChart::setRightMargin(double fraction)
{
	Q_ASSERT(0.0 <= fraction && fraction <= 1.0);

	m_rightMargin = fraction;
}

void QocPieChart::setMargins(double top, double bottom, double left, double right)
{
	setTopMargin(top);
	setBottomMargin(bottom);
	setLeftMargin(left);
	setRightMargin(right);
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

QString QocPieChart::title() const
{
	return m_title;
}

void QocPieChart::setTitle(const QString &title)
{
	m_title = title;
}

QFont QocPieChart::titleFont() const
{
	return m_titleFont;
}

void QocPieChart::setTitleFont(const QFont &font)
{
	m_titleFont = font;
}

bool QocPieChart::isTitleVisible() const
{
	return m_titleVisible;
}

void QocPieChart::setTitleVisible(bool b)
{
	m_titleVisible = b;
}

int QocPieChart::titleFlags() const
{
	return m_titleFlags;
}

void QocPieChart::setTitleFlags(int flags)
{
	m_titleFlags = flags;
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
		i->draw(painter, rect);
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

//	retVal.setX(r.x() + r.width() * m_leftMargin);
//	retVal.setY(r.y() + r.height() * m_topMargin);
	retVal.setWidth(r.width() - r.width() * (m_leftMargin + m_rightMargin));
	retVal.setHeight(r.height() - r.height() * (m_topMargin + m_bottomMargin));

	double length = qMin(retVal.width(), retVal.height());

	retVal.setX(r.x() + r.width() / 2 - length / 2);
	retVal.setY(r.y() + r.height() / 2 - length / 2);
	retVal.setWidth(length);
	retVal.setHeight(length);

	return retVal;
}
