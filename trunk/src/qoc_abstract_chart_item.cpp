#include "qoc_abstract_chart_item.h"
#include "qoc_abstract_chart.h"

#include <QPen>
#include <QBrush>

QocAbstractChartItem::QocAbstractChartItem(QObject *parent) :
	QObject(parent),
	m_chart(qobject_cast<QocAbstractChart *>(parent)),
	m_titleAnchor(TopAnchor),
	m_titleVisible(true),
	m_visible(true),
	m_pen(new QPen(QColor(Qt::black))),
	m_brush(new QBrush(Qt::red)),
	m_selected(false)
{
}


QocAbstractChartItem::TitleAnchor QocAbstractChartItem::titleAnchor() const
{
	return m_titleAnchor;
}

void QocAbstractChartItem::setTitleAnchor(QocAbstractChartItem::TitleAnchor ta)
{
	m_titleAnchor = ta;
}

void QocAbstractChartItem::setTitle(QString t)
{
	m_title = t;
}

bool QocAbstractChartItem::isTitleVisible()
{
	return m_titleVisible;
}

void QocAbstractChartItem::setTitleVisible(bool b)
{
	m_titleVisible = b;
}

quint64 QocAbstractChartItem::z() const
{
	return m_z;
}

void QocAbstractChartItem::setZ(quint64 z)
{
	m_z = z;
}

QString QocAbstractChartItem::title() const
{
	return m_title;
}

QColor QocAbstractChartItem::color() const
{
	return m_color;
}

void QocAbstractChartItem::setColor(const QColor &c)
{
	m_color = c;
}

bool QocAbstractChartItem::isVisible()
{
	return m_visible;
}

void QocAbstractChartItem::setVisible(bool b)
{
	m_visible = b;
}

QPen QocAbstractChartItem::pen()
{
	return *m_pen;
}

void QocAbstractChartItem::setPen(QPen *pen)
{
	delete m_pen;
	m_pen = pen;
}

QBrush QocAbstractChartItem::brush() const
{
	return *m_brush;
}

void QocAbstractChartItem::setBrush(QBrush *brush)
{
	delete m_brush;
	m_brush = brush;
}

bool QocAbstractChartItem::isSelected() const
{
	return m_selected;
}

void QocAbstractChartItem::setSelected(bool b)
{
	m_selected = b;
}
