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

signals:
	
public slots:
	void rebuildChart() const;
protected:
	virtual void paintEvent(QPaintEvent * event);
private:
	QocAbstractChart *m_chart;
};

#endif // QOC_VIEW_WIDGET_H
