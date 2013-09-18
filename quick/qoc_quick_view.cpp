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
	qDebug() << Q_FUNC_INFO;
	if ( m_chart != chart )
	{
		m_chart = chart;
		m_chart->setViewGeometry(QRect(x(), y(), width(), height()));
		emit chartChanged();
	}
}

void QocQuickView::paint(QPainter *p)
{
	p->save();

	qDebug() << Q_FUNC_INFO;

	if ( m_chart )
	{
		m_chart->draw(p);
		qDebug() << Q_FUNC_INFO << m_chart->backgroundColor();

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
