#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>

#include "qoc_pie_chart.h"
#include "qoc_legend.h"

namespace Ui {
class TestWidget;
}

class TestWidget : public QWidget
{
	Q_OBJECT
	
public:
	explicit TestWidget(QWidget *parent = 0);
	~TestWidget();

protected:
	virtual void paintEvent(QPaintEvent *event);

public:
	QocPieChart pieChart;
	QocLegend legend;

private:
	Ui::TestWidget *ui;
};

#endif // TESTWIDGET_H
