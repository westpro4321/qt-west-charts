#include "qoc_abstract_chart.h"

QocAbstractChart::QocAbstractChart(QObject *parent) :
	QObject(parent),
	m_antialiased(true),
	m_backgroundBrush(0),
	m_selectionPen(new QPen),
	m_title("Chart Title"),
	m_titleFont(QFont("Arial", 12, QFont::Normal)),
	m_titleVisible(true),
	m_titleFlags(Qt::AlignHCenter | Qt::AlignTop)
{
//	setMargins(0.15, 0.05, 0.1, 0.2);
}

void QocAbstractChart::draw(QPainter *painter, const QRectF &rect)
{
	drawBackground(painter, rect);
	drawLowLayer(painter, rect);
	drawChartLayer(painter, rect);
	drawHighLayer(painter, rect);
	drawForeground(painter, rect);
}

bool QocAbstractChart::isAntialiased()
{
	return m_antialiased;
}

void QocAbstractChart::setAntialiased(bool b)
{
	m_antialiased = b;
}

QBrush QocAbstractChart::background() const
{
	return *m_backgroundBrush;
}

void QocAbstractChart::setBackground(const QBrush &brush)
{
	m_backgroundBrush = brush;
}

QBrush QocAbstractChart::foreground() const
{
	return m_foregroundBrush;
}

void QocAbstractChart::setForeground(const QBrush &brush)
{
	m_foregroundBrush = brush;
}

QPen QocAbstractChart::selectionPen() const
{
	return *m_selectionPen;
}

void QocAbstractChart::setSelectionPen(const QPen &pen)
{
	m_selectionPen = pen;
}

//double QocAbstractChart::topMargin()
//{
//	return m_topMargin;
//}


//void QocAbstractChart::setTopMargin(double fraction)
//{
//	Q_ASSERT(0.0 <= fraction && fraction <= 1.0);

//	m_topMargin = fraction;
//}

//double QocAbstractChart::bottomMargin()
//{
//	return m_bottomMargin;
//}

//void QocAbstractChart::setBottomMargin(double fraction)
//{
//	Q_ASSERT(0.0 <= fraction && fraction <= 1.0);

//	m_bottomMargin = fraction;
//}

//double QocAbstractChart::leftMargin()
//{
//	return m_leftMargin;
//}

//void QocAbstractChart::setLeftMargin(double fraction)
//{
//	Q_ASSERT(0.0 <= fraction && fraction <= 1.0);

//	m_leftMargin = fraction;
//}

//double QocAbstractChart::rightMargin()
//{
//	return m_rightMargin;
//}

//void QocAbstractChart::setRightMargin(double fraction)
//{
//	Q_ASSERT(0.0 <= fraction && fraction <= 1.0);

//	m_rightMargin = fraction;
//}

//void QocAbstractChart::setMargins(double top, double bottom, double left, double right)
//{
//	setTopMargin(top);
//	setBottomMargin(bottom);
//	setLeftMargin(left);
//	setRightMargin(right);
//}

QString QocAbstractChart::title() const
{
	return m_title;
}

void QocAbstractChart::setTitle(const QString &title)
{
	m_title = title;
}

QFont QocAbstractChart::titleFont() const
{
	return m_titleFont;
}

void QocAbstractChart::setTitleFont(const QFont &font)
{
	m_titleFont = font;
}

bool QocAbstractChart::isTitleVisible() const
{
	return m_titleVisible;
}

void QocAbstractChart::setTitleVisible(bool b)
{
	m_titleVisible = b;
}

int QocAbstractChart::titleFlags() const
{
	return m_titleFlags;
}

void QocAbstractChart::setTitleFlags(int flags)
{
	m_titleFlags = flags;
}

QPointF QocAbstractChart::mapFromGlobal(QPointF p)
{
	//TODO:
	QPointF retVal;
	if ( m_viewGeometry.width() && m_viewGeometry.height() )
	{
		retVal.setX((p.x() - m_viewGeometry.x()) * m_chartRect.width() / m_viewGeometry.width());
		retVal.setY((p.y() - m_viewGeometry.y()) * m_chartRect.height() / m_viewGeometry.height());
	}
	return retVal;
}

QPointF QocAbstractChart::mapToGlobal(QPointF p)
{
	//TODO:
	QPointF retVal;
	if ( m_chartRect.width() && m_chartRect.height() )
	{
		retVal.setX(m_viewGeometry.x() + p.x() * m_viewGeometry.width() / m_chartRect.width());
		retVal.setY(m_viewGeometry.y() + p.y() * m_viewGeometry.height() / m_chartRect.height());
	}
	return retVal;
}

void QocAbstractChart::drawBackground(QPainter *painter, const QRectF &rect)
{
	if ( m_backgroundBrush.style() != Qt::NoBrush )
	{

	}
}

void QocAbstractChart::drawForeground(QPainter *painter, const QRectF &rect)
{
	if ( m_foregroundBrush.style() != Qt::NoBrush )
	{

	}
}
