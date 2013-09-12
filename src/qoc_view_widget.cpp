#include "qoc_view_widget.h"
#include "qoc_abstract_chart.h"

#include <QPaintEvent>
#include <QPainter>
#include <QDebug>

QocViewWidget::QocViewWidget(QWidget *parent) :
	QWidget(parent),
	m_chart(0)
{
}

bool QocViewWidget::event(QEvent *e)
{
//	if ( m_chart && !m_chart->event(e) )
//	{
//		return true;
//	}

	return QWidget::event(e);
}

void QocViewWidget::setChart(QocAbstractChart *c)
{
	m_chart = c;
}

void QocViewWidget::paintEvent(QPaintEvent *event)
{
	qDebug() << Q_FUNC_INFO << event;

	if ( m_chart )
	{
		QPainter p(this);
		m_chart->draw(&p, event->rect());
	}
}
