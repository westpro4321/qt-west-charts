#include "qoc_bar_chart.h"
#include "qoc_adaptor_model.h"
#include "qoc_axis.h"

QocBarChart::QocBarChart(QObject *parent) :
	QocAbstractChart(parent)
{
	m_vAxis = new QocAxis(QPointF(20, 130), QPointF(20, 20), this);
	m_hAxis = new QocAxis(QPointF(20, 130), QPointF(180, 130), this);
}

QocBarChart::QocBarChart(const QSizeF &size, QObject *parent) :
	QocAbstractChart(size, parent)
{
	m_vAxis = new QocAxis(QPointF(20, 130), QPointF(20, 20), this);
	m_hAxis = new QocAxis(QPointF(20, 130), QPointF(180, 130), this);
}

void QocBarChart::setModel(const QVariant &model)
{
	QocAbstractChart::setModel(model);
	for(int i=0; i<m_adaptorModel->seriesCount(); ++i)
	{

	}
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
}

void QocBarChart::drawHighLayer(QPainter *painter, const QRectF &rect)
{

}
