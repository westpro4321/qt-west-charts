#include "qoc_bar_chart.h"
#include "qoc_adaptor_model.h"
#include "qoc_axis.h"
#include "qoc_bar_item.h"

#include <QPainter>


QocBarChart::QocBarChart(QObject *parent) :
	QocAbstractChart(parent),
	m_radius(0)
{
	setupAxes();
}

QocBarChart::QocBarChart(const QSizeF &size, QObject *parent) :
	QocAbstractChart(size, parent),
	m_radius(0)
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

			connect(item, SIGNAL(valueChanged(qreal)), this, SLOT(onItemValueChanged(qreal)));

			item->setPosition(m_hAxis->valueToPos(m_adaptorModel->data(i, j, Qoc::XValueRole).toReal()));
//			item->setHeight((m_vAxis->valueToPos(m_vAxis->minValue()) -
//							m_vAxis->valueToPos(m_adaptorModel->data(i, Qoc::YValueRole).toReal())).y());
			item->setValue(m_adaptorModel->data(i, j, Qoc::YValueRole).toReal());
			item->setColor(m_adaptorModel->data(i, j, Qoc::ColorRole).value<QColor>());
			items.append(item);

			connect(item, SIGNAL(valueChanged(qreal)), this, SIGNAL(repaint()));
		}
	}
	m_itemsMap.insert(ChartLayer, items);
}

qreal QocBarChart::radius() const
{
	return m_radius;
}

void QocBarChart::setRadius(qreal r)
{
	if ( m_radius != r )
	{
		m_radius = r;
		emit radiusChanged(r);
	}
}

QocAxis *QocBarChart::verticalAxis()
{
	return m_vAxis;
}

QocAxis *QocBarChart::horizontalAxis()
{
	return m_hAxis;
}

void QocBarChart::drawLowLayer(QPainter *painter, const QRectF &rect)
{
	QocAbstractChart::drawLowLayer(painter, rect);
}

void QocBarChart::drawChartLayer(QPainter *p, const QRectF &rect)
{
	m_vAxis->draw(p);
	m_hAxis->draw(p);

	foreach (QocAbstractChartItem *i, m_itemsMap.value(ChartLayer))
	{
		i->draw(p, rect);
	}
}

void QocBarChart::drawHighLayer(QPainter *painter, const QRectF &rect)
{
	QocAbstractChart::drawHighLayer(painter, rect);
}

void QocBarChart::setupAxes()
{
	m_vAxis = new QocAxis(QPointF(20, 130), QPointF(20, 20), this);
	m_vAxis->setMinValue(0);
	m_vAxis->setMaxValue(11);
	connect(m_vAxis, SIGNAL(beginChanged(QPointF)), this, SIGNAL(repaint()));
	connect(m_vAxis, SIGNAL(endChanged(QPointF)), this, SIGNAL(repaint()));
	connect(m_vAxis, SIGNAL(minValueChanged(qreal)), this, SIGNAL(repaint()));
	connect(m_vAxis, SIGNAL(maxValueChanged(qreal)), this, SIGNAL(repaint()));
	connect(m_vAxis, SIGNAL(colorChanged(QColor)), this, SIGNAL(repaint()));


	m_hAxis = new QocAxis(QPointF(20, 130), QPointF(180, 130), this);
	m_hAxis->setMinValue(0);
	m_hAxis->setMaxValue(11);
	connect(m_hAxis, SIGNAL(beginChanged(QPointF)), this, SIGNAL(repaint()));
	connect(m_hAxis, SIGNAL(endChanged(QPointF)), this, SIGNAL(repaint()));
	connect(m_hAxis, SIGNAL(minValueChanged(qreal)), this, SIGNAL(repaint()));
	connect(m_hAxis, SIGNAL(maxValueChanged(qreal)), this, SIGNAL(repaint()));
	connect(m_hAxis, SIGNAL(colorChanged(QColor)), this, SIGNAL(repaint()));
}

void QocBarChart::onItemValueChanged(qreal val)
{
	QocBarItem *i = qobject_cast<QocBarItem *>(sender());
	if ( i )
	{
		i->setHeight(val*m_vAxis->unit());
	}
}
