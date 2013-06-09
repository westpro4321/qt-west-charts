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
	vector.append(QPointF(1,11));
	vector.append(QPointF(2,21));
	vector.append(QPointF(3,31));
	vector.append(QPointF(4,41));
	vector.append(QPointF(5,5));
	vector.append(QPointF(6,11));

	series->setSamples(vector);

	pieChart.setSeries(series);

	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setMinimumHeight(320);
	setMinimumWidth(480);

	QBrush *br = new QBrush(Qt::SolidPattern);
	br->setColor(QColor(Qt::blue).lighter(180));
	pieChart.setBackground(br);

	pieChart.item(2)->setOffset(20);
	pieChart.item(4)->setVisible(false);

	pieChart.item(2)->setBrush(new QBrush(Qt::yellow));
	pieChart.item(3)->setBrush(new QBrush(Qt::green));
	pieChart.item(4)->setBrush(new QBrush(Qt::blue));
	pieChart.item(5)->setBrush(new QBrush(Qt::darkCyan));
	pieChart.item(6)->setBrush(new QBrush(Qt::magenta));

	pieChart.item(1)->setTitle(pieChart.item(1)->brush().color().name());
	pieChart.item(2)->setTitle(pieChart.item(2)->brush().color().name());
	pieChart.item(3)->setTitle(pieChart.item(3)->brush().color().name());
	pieChart.item(4)->setTitle(pieChart.item(4)->brush().color().name());
	pieChart.item(5)->setTitle(pieChart.item(5)->brush().color().name());
	pieChart.item(6)->setTitle(pieChart.item(6)->brush().color().name());



	legend.setChart(&pieChart);
}

TestWidget::~TestWidget()
{
	delete ui;
}

void TestWidget::paintEvent(QPaintEvent *event)
{
	QPainter p(this);
	pieChart.draw(&p, event->rect());
	legend.draw(&p, event->rect());
}
