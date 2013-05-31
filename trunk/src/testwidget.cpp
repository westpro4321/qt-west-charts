#include "testwidget.h"

TestWidget::TestWidget(QWidget *parent) :
	QWidget(parent)
{
}

void TestWidget::paintEvent(QPaintEvent *event)
{
	QWidget::paintEvent(event);
}
