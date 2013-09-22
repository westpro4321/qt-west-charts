#include "qoc_quick_view.h"
#include "qoc_quick_abstract_chart.h"

#include <QPainter>


QocQuickView::QocQuickView(QQuickItem *parent) :
	QQuickPaintedItem(parent),
	m_chart(0)
{
}

QocQuickAbstractChart *QocQuickView::chart() const
{
	return m_chart;
}

void QocQuickView::setChart(QocQuickAbstractChart *chart)
{
	if ( m_chart != chart )
	{
		disconnect(m_chart, SIGNAL(repaint()), this, SLOT(update()));

		m_chart = chart;
		m_chart->setViewGeometry(QRect(x(), y(), width(), height()));
		connect(m_chart, SIGNAL(repaint()), this, SLOT(update()));
		emit chartChanged();
	}
}

void QocQuickView::paint(QPainter *p)
{
	p->save();

	if ( m_chart )
	{
		m_chart->draw(p, boundingRect());
	}

	p->restore();
}

void QocQuickView::geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry)
{
	QQuickPaintedItem::geometryChanged(newGeometry, oldGeometry);
	if ( m_chart && newGeometry != oldGeometry )
	{
		m_chart->setViewGeometry(newGeometry);
	}
}
