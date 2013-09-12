#include "qoc_abstract_chart.h"
#include "qoc_adaptor_model.h"

#include <QPainter>
#include <QDebug>

QocAbstractChart::QocAbstractChart(QObject *parent) :
	QObject(parent),
	m_antialiased(true),
	m_title("Chart Title"),
	m_titleFont(QFont("Arial", 12, QFont::Normal)),
	m_titleVisible(true),
	m_titleFlags(Qt::AlignHCenter | Qt::AlignTop),
	m_adaptorModel(new QocAdaptorModel(this))
{
	connect(m_adaptorModel, SIGNAL(modelChanged()), this, SIGNAL(modelChanged()));
}

QocAbstractChart::QocAbstractChart(const QSizeF &size, QObject *parent) :
	QObject(parent),
	m_chartSize(size),
	m_adaptorModel(new QocAdaptorModel(this))
{
}

void QocAbstractChart::draw(QPainter *painter, const QRectF &rect)
{
	m_viewGeometry = rect;

//	painter->setClipping(true);

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

QBrush QocAbstractChart::backgroundBrush() const
{
	return m_backgroundBrush;
}

void QocAbstractChart::setBackgroundBrush(const QBrush &brush)
{
	m_backgroundBrush = brush;
}

QBrush QocAbstractChart::foregroundBrush() const
{
	return m_foregroundBrush;
}

void QocAbstractChart::setForegroundBrush(const QBrush &brush)
{
	m_foregroundBrush = brush;
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
	//TODO: Weryfikacja poprawności
	QPointF retVal;
	if ( m_viewGeometry.width() && m_viewGeometry.height() )
	{
		retVal.setX((p.x() - m_viewGeometry.x()) * m_chartSize.width() / m_viewGeometry.width());
		retVal.setY((p.y() - m_viewGeometry.y()) * m_chartSize.height() / m_viewGeometry.height());
	}
	return retVal;
}

QPointF QocAbstractChart::mapToGlobal(QPointF p)
{
	//TODO: Weryfikacja poprawności
	qDebug() << Q_FUNC_INFO << p << m_viewGeometry << m_chartSize;

	QPointF retVal;
	if ( m_chartSize.width() && m_chartSize.height() )
	{
		retVal.setX(m_viewGeometry.x() + p.x() * m_viewGeometry.width() / m_chartSize.width());
		retVal.setY(m_viewGeometry.y() + p.y() * m_viewGeometry.height() / m_chartSize.height());
	}
	qDebug() << Q_FUNC_INFO << retVal;
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

void QocAbstractChart::drawBackground(QPainter *painter, const QRectF &rect)
{
	qDebug() << Q_FUNC_INFO << painter << rect;
	if ( m_backgroundBrush.style() != Qt::NoBrush )
	{
		painter->save();
		painter->setBrush(QBrush(m_backgroundBrush));
		painter->drawRect(rect);
		painter->restore();
	}
}

void QocAbstractChart::drawForeground(QPainter *painter, const QRectF &rect)
{
	if ( m_foregroundBrush.style() != Qt::NoBrush )
	{

		painter->save();
		painter->setBrush(QBrush(m_foregroundBrush));
		painter->drawRect(rect);
		painter->restore();
	}
}
