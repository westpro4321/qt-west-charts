#ifndef QOC_VIEW_WIDGET_H
#define QOC_VIEW_WIDGET_H

#include <QWidget>

#include "qoc_global.h"

class QocAbstractChart;


class QOC_API QocViewWidget : public QWidget
{
	Q_OBJECT
public:
	explicit QocViewWidget(QWidget *parent = 0);
	
	bool event(QEvent *);
	void setChart(QocAbstractChart *c);

	virtual bool eventFilter(QObject *watched, QEvent *event);
signals:
	void animationEnded(bool);
public slots:
	void rebuildChart();
	void animationFinished();
protected:
	virtual void paintEvent(QPaintEvent * event);
private:
	QocAbstractChart *m_chart;
	bool m_animationStarted;
	int m_events;
};

#endif // QOC_VIEW_WIDGET_H
