#include "qoc_view_widget.h"
#include "qoc_abstract_chart.h"
#include "qoc_abstract_value_item.h"

#include <QPaintEvent>
#include <QPainter>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <QPushButton>

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
	if ( m_chart )
	{
		disconnect(m_chart, SIGNAL(repaint()), this, SLOT(update()));
	}
	m_chart = c;

	connect(m_chart, SIGNAL(repaint()), this, SLOT(update()));
}

void QocViewWidget::rebuildChart() const
{
	QPushButton *pb = qobject_cast<QPushButton *>(sender());
	QParallelAnimationGroup *group = new QParallelAnimationGroup();
//	QSequentialAnimationGroup *group = new QSequentialAnimationGroup();

	if (pb)
	{
		pb->setEnabled(false);
		connect(group, SIGNAL(finished()), this, SLOT(animationFinished()));
		connect(this, SIGNAL(animationEnded(bool)), pb, SLOT(setEnabled(bool)));
	}
	QList<QocAbstractChartItem *> items = m_chart->items(QocAbstractChart::ChartLayer);
	foreach(QocAbstractChartItem *item, items)
	{
		QocAbstractValueItem *i = qobject_cast<QocAbstractValueItem *>(item);
		if ( i )
		{
			QPropertyAnimation *anim = new QPropertyAnimation(i, "value", group);
			anim->setStartValue(0);
			anim->setEndValue(i->value());
			anim->setDuration(2000);
//			anim->setDuration(100);
			group->addAnimation(anim);

//			i->blockSignals(true);
			i->setValue(0);
//			i->blockSignals(false);
		}
	}
	//connect(group, SIGNAL(finished()), group, SLOT(deleteLater()));
	group->start(QAbstractAnimation::DeleteWhenStopped);
}

void QocViewWidget::animationFinished()
{
	emit animationEnded(true);
}

void QocViewWidget::paintEvent(QPaintEvent *event)
{
	if ( m_chart )
	{
		QPainter p(this);
		m_chart->draw(&p, event->rect());
	}
}
