#include "testwidget.h"
#include "ui_testwidget.h"
#include "qoc_data_series.h"

#include <QPaintEvent>
#include <QPainter>


TestWidget::TestWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::TestWidget),
	pieChart(this)
{
	ui->setupUi(this);

	QocDataSeries<QPointF> *series = new QocDataSeries<QPointF>();

	QVector<QPointF> vector;
	vector.append(QPointF(1,1));
	vector.append(QPointF(2,2));
	vector.append(QPointF(3,3));
	vector.append(QPointF(4,4));
	series->setSamples(vector);

	pieChart.setSeries(series);

	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setMinimumHeight(320);
	setMinimumWidth(480);

	QBrush *br = new QBrush(Qt::SolidPattern);
	br->setColor(QColor(Qt::blue).lighter(180));
	pieChart.setBackground(br);

	pieChart.item(2)->setOffset(10);
	pieChart.item(4)->setOffset(20);

	pieChart.item(2)->setBrush(new QBrush(Qt::yellow));
	pieChart.item(3)->setBrush(new QBrush(Qt::green));
	pieChart.item(4)->setBrush(new QBrush(Qt::blue));
}

TestWidget::~TestWidget()
{
	delete ui;
}

void TestWidget::paintEvent(QPaintEvent *event)
{
	QPainter p(this);
	pieChart.draw(&p, event->rect());
}
