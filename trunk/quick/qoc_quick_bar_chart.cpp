#include "qoc_quick_bar_chart.h"

#include <qoc_bar_chart.h>
#include <QDebug>


QocQuickBarChart::QocQuickBarChart(QObject *parent) :
	QocQuickAbstractChart(parent)
{
	m_chart = new QocBarChart(this);

	qDebug() << Q_FUNC_INFO;
}
