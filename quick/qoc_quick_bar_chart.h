#ifndef QOC_QUICK_BAR_CHART_H
#define QOC_QUICK_BAR_CHART_H

#include "qoc_quick_abstract_chart.h"
#include "qoc_quick_global.h"

#include <qoc_bar_item.h>

#include <QQmlListProperty>

class QocAxis;
class QocBarChart;

class QOC_QUICK_API QocQuickBarChart : public QocQuickAbstractChart
{
	Q_OBJECT
	Q_PROPERTY(QocAxis* verticalAxis READ verticalAxis)
	Q_PROPERTY(QocAxis* horizontalAxis READ horizontalAxis)
	Q_PROPERTY(QQmlListProperty<QocBarItem> bars READ bars)
	Q_PROPERTY(qreal radius READ radius WRITE setRadius NOTIFY radiusChanged)

public:
	explicit QocQuickBarChart(QObject *parent = 0);
	
	QocAxis *verticalAxis();
	QocAxis *horizontalAxis();
	QQmlListProperty<QocBarItem> bars();

	qreal radius() const;
	void setRadius(qreal r);

signals:
	void radiusChanged(qreal);

public slots:

protected:
	QocBarChart *chart() const;

private:
	static QocBarItem *at_item(QQmlListProperty<QocBarItem> *list, int index);
	static int count_item(QQmlListProperty<QocBarItem> *list);
};

#endif // QOC_QUICK_BAR_CHART_H
