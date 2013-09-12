#include "qoc_bar_chart.h"
#include "qoc_adaptor_model.h"
#include "qoc_axis.h"
#include "qoc_bar_item.h"

#include <QDebug>


QocBarChart::QocBarChart(QObject *parent) :
	QocAbstractChart(parent)
{
	setupAxes();
}

QocBarChart::QocBarChart(const QSizeF &size, QObject *parent) :
	QocAbstractChart(size, parent)
{
	setupAxes();
}


void QocBarChart::setModel(const QVariant &model)
{
	QocAbstractChart::setModel(model);
	QList<QocAbstractChartItem *> items;
	for(int i=0; i<m_adaptorModel->seriesCount(); ++i)
	{
		for(int j=0; j<m_adaptorModel->size(i); ++j)
		{
			QocBarItem *item = new QocBarItem(this);
			item->setPosition(m_hAxis->valueToPos(m_adaptorModel->data(i, Qoc::XValueRole).toReal()));
//			item->setHeight((m_vAxis->valueToPos(m_vAxis->minValue()) -
//							m_vAxis->valueToPos(m_adaptorModel->data(i, Qoc::YValueRole).toReal())).y());
			item->setHeight(m_adaptorModel->data(i, Qoc::YValueRole).toReal());
			item->setColor(m_adaptorModel->data(i, Qoc::ColorRole).value<QColor>());
			items.append(item);
		}
	}
	m_itemsMap.insert(ChartLayer, items);
}

uint QocBarChart::radius() const
{
	return m_radius;
}

void QocBarChart::setRadius(uint r)
{
	if ( m_radius != r )
	{
		m_radius = r;
		emit radiusChanged(r);
	}
}

void QocBarChart::drawLowLayer(QPainter *painter, const QRectF &rect)
{

}

void QocBarChart::drawChartLayer(QPainter *p, const QRectF &rect)
{
	m_vAxis->draw(p);
	m_hAxis->draw(p);

	foreach (QocAbstractChartItem *i, m_itemsMap.value(ChartLayer))
	{
		i->draw(p, rect);
	}

	qDebug() << Q_FUNC_INFO << m_hAxis->valueToPos(10) << m_vAxis->valueToPos(10);
}

void QocBarChart::drawHighLayer(QPainter *painter, const QRectF &rect)
{

}

void QocBarChart::setupAxes()
{
	m_vAxis = new QocAxis(QPointF(20, 130), QPointF(20, 20), this);
	m_vAxis->setMinValue(0);
	m_vAxis->setMaxValue(10);
	m_hAxis = new QocAxis(QPointF(20, 130), QPointF(180, 130), this);
	m_hAxis->setMinValue(0);
	m_hAxis->setMaxValue(10);
}