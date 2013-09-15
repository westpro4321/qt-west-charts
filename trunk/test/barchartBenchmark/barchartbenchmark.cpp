#include "barchartbenchmark.h"

#include <qoc_bar_chart.h>
#include <qoc_data_series.h>
#include <qoc_data_item.h>
#include <qoc_view_widget.h>

#include <QPixmap>
#include <QtCore/qmath.h>
#include <QPainter>

BarChartBenchmark::BarChartBenchmark(QObject *parent) :
	QObject(parent)
{
}

void BarChartBenchmark::draw()
{
	QFETCH(int, width);
	QFETCH(int, height);
	QFETCH(int, items);

	QPixmap image(width, height);
	QPainter p(&image);

	QocViewWidget *wgt = new QocViewWidget;
	QocBarChart *c =  new QocBarChart(QSize(width, height), wgt);
	c->setBackgroundBrush(QColor("blue"));
//	c->setViewGeometry(image.rect());

	QocDataSeries *s = new QocDataSeries(c);
	c->setModel(QVariant::fromValue(s));

	for(int i=0; i<items; ++i)
	{
		QocDataItem *item = new QocDataItem(s);
		item->setData(i, Qoc::XValueRole);
		item->setData(qAbs(50 - qPow(i, 2)), Qoc::YValueRole);
		item->setData(QVariant::fromValue(QColor(static_cast<Qt::GlobalColor>(i))), Qoc::ColorRole);
		s->append(item);
	}

	QBENCHMARK
	{
//		wgt->show();
		c->draw(&p);
	}
	wgt->deleteLater();
}

void BarChartBenchmark::draw_data()
{
	QTest::addColumn<int>("width");
	QTest::addColumn<int>("height");
	QTest::addColumn<int>("items");

	QTest::newRow("320x240 10") << 320 << 240 << 10;
	QTest::newRow("320x240 100") << 320 << 240 << 100;
	QTest::newRow("320x240 1000") << 320 << 240 << 1000;

	QTest::newRow("600x480 10") << 600 << 480 << 10;
	QTest::newRow("600x480 100") << 600 << 480 << 100;
	QTest::newRow("600x480 1000") << 600 << 480 << 1000;

	QTest::newRow("1024x768 10") << 1024 << 768 << 10;
	QTest::newRow("1024x768 100") << 1024 << 768 << 100;
	QTest::newRow("1024x768 1000") << 1024 << 768 << 1000;
}
