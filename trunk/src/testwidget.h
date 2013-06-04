#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>

#include "qoc_pie_chart.h"

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

private:
	Ui::TestWidget *ui;
};

#endif // TESTWIDGET_H
