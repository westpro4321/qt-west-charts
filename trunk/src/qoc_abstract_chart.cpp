#include "qoc_abstract_chart.h"
#include "qoc_adaptor_model.h"
#include "qoc_abstract_chart_item.h"

#include <QPainter>
#include <QDebug>


QocAbstractChart::QocAbstractChart(QObject *parent) :
	QObject(parent),
	m_antialiased(true),
	m_title("Chart Title"),
	m_titleFont(QFont("Arial", 12, QFont::Normal)),
	m_titleVisible(true),
	m_titleFlags(Qt::AlignHCenter | Qt::AlignTop),
	m_size(QSizeF(200, 150)),
	m_adaptorModel(new QocAdaptorModel(this))
{
	connect(m_adaptorModel, SIGNAL(modelChanged()), this, SIGNAL(modelChanged()));
}

QocAbstractChart::QocAbstractChart(const QSizeF &size, QObject *parent) :
	QObject(parent),
	m_antialiased(true),
	m_size(size),
	m_adaptorModel(new QocAdaptorModel(this))
{
}

void QocAbstractChart::draw(QPainter *painter, const QRectF &rect)
{
	if ( rect.isValid() )
		m_viewGeometry = rect;

	painter->save();

	QPen pen = painter->pen();
	qreal scale = xScale() <= yScale() ? xScale() : yScale();
	pen.setWidthF(pen.widthF() * scale / 2);
	painter->setPen(pen);

	painter->setRenderHint(QPainter::Antialiasing, isAntialiased());
	drawBackground(painter, rect);
	drawLowLayer(painter, rect);
	drawChartLayer(painter, rect);
	drawHighLayer(painter, rect);
	drawForeground(painter, rect);

	painter->restore();
}

bool QocAbstractChart::isAntialiased()
{
	return m_antialiased;
}

void QocAbstractChart::setAntialiased(bool b)
{
	m_antialiased = b;
}

QBrush QocAbstractChart::backgroundBrush() const
{
	return m_backgroundBrush;
}

void QocAbstractChart::setBackgroundBrush(const QBrush &brush)
{
	m_backgroundBrush = brush;
	repaint();
}

QBrush QocAbstractChart::foregroundBrush() const
{
	return m_foregroundBrush;
}

void QocAbstractChart::setForegroundBrush(const QBrush &brush)
{
	m_foregroundBrush = brush;
	repaint();
}

QPen QocAbstractChart::selectionPen() const
{
	return m_selectionPen;
}

void QocAbstractChart::setSelectionPen(const QPen &pen)
{
	m_selectionPen = pen;
}

QVariant QocAbstractChart::model() const
{
	return m_adaptorModel->model();
}

void QocAbstractChart::setModel(const QVariant &model)
{
	m_adaptorModel->setModel(model);
}

QSizeF QocAbstractChart::size() const
{
	return m_size;
}

void QocAbstractChart::setSize(const QSizeF &size)
{
	if ( m_size != size )
	{
		m_size = size;
		emit sizeChanged(size);
	}
}

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
	QPointF retVal;
	if ( m_viewGeometry.width() && m_viewGeometry.height() )
	{
		retVal.setX((p.x() - m_viewGeometry.x()) * m_size.width() / m_viewGeometry.width());
		retVal.setY((p.y() - m_viewGeometry.y()) * m_size.height() / m_viewGeometry.height());
	}
	return retVal;
}

QPointF QocAbstractChart::mapToGlobal(QPointF p)
{
	QPointF retVal;
	if ( m_size.width() && m_size.height() )
	{
		retVal.setX(m_viewGeometry.x() + p.x() * m_viewGeometry.width() / m_size.width());
		retVal.setY(m_viewGeometry.y() + p.y() * m_viewGeometry.height() / m_size.height());
	}
	return retVal;
}

void QocAbstractChart::addItem(QocAbstractChart::Layer layer, QocAbstractChartItem *item)
{
	m_itemsMap[layer].append(item);
}

void QocAbstractChart::removeItem(QocAbstractChart::Layer layer, QocAbstractChartItem *item)
{
	m_itemsMap[layer].removeOne(item);
}

void QocAbstractChart::removeItem(QocAbstractChartItem *item)
{
	for(int i=0; i<m_itemsMap.keys().size(); ++i)
	{
		m_itemsMap[static_cast<Layer>(i)].removeOne(item);
	}
}

qreal QocAbstractChart::xScale() const
{
	return m_size.width() ? m_viewGeometry.width()/m_size.width() : 0;
}

qreal QocAbstractChart::yScale() const
{
	return m_size.height() ? m_viewGeometry.height()/m_size.height() : 0;
}

QList<QocAbstractChartItem *> QocAbstractChart::items(QocAbstractChart::Layer l)
{
	return m_itemsMap.value(l);
}

QRectF QocAbstractChart::viewGeometry() const
{
	return m_viewGeometry;
}

void QocAbstractChart::setViewGeometry(const QRectF &r)
{
	if ( m_viewGeometry != r )
	{
		m_viewGeometry = r;
		emit repaint();
	}
}

void QocAbstractChart::drawBackground(QPainter *painter, const QRectF &rect)
{
	if ( m_backgroundBrush.style() != Qt::NoBrush )
	{
		painter->save();
		painter->setPen(m_backgroundBrush.color());
		painter->setBrush(m_backgroundBrush);
		painter->drawRect(rect);
		painter->restore();
	}
}

void QocAbstractChart::drawLowLayer(QPainter *painter, const QRectF &rect)
{
	foreach (QocAbstractChartItem *i, m_itemsMap.value(LowLayer))
	{
		i->draw(painter, rect);
	}
}

void QocAbstractChart::drawHighLayer(QPainter *painter, const QRectF &rect)
{
	foreach (QocAbstractChartItem *i, m_itemsMap.value(HighLayer))
	{
		i->draw(painter, rect);
	}
}

void QocAbstractChart::drawForeground(QPainter *painter, const QRectF &rect)
{
	if ( m_foregroundBrush.style() != Qt::NoBrush )
	{

		painter->save();
		painter->setPen(m_foregroundBrush.color());
		painter->setBrush(m_foregroundBrush);
		painter->drawRect(rect);
		painter->restore();
	}
}
