#include <QApplication>
#include <QPointF>
#include <QDebug>
#include <QPainter>
#include <QHBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QtCore/qmath.h>
#include <QRgb>

#include <qoc_data_series.h>
#include <qoc_data_item.h>
#include <qoc_view_widget.h>
#include <qoc_bar_chart.h>
#include <qoc_bar_item.h>
#include <qoc_axis.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QWidget *w = new QWidget;
	w->setWindowTitle("Bar Chart");
	w->setLayout(new QHBoxLayout(w));

		QocViewWidget *wgt = new QocViewWidget(w);
		w->setMinimumSize(QSize(1024, 480));
		wgt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
		QPushButton *pb = new QPushButton("Rebuild", w);
		w->layout()->addWidget(wgt);
		w->layout()->addWidget(pb);
		QObject::connect(pb, SIGNAL(clicked()), wgt, SLOT(rebuildChart()));

		QocBarChart *chart = new QocBarChart(QSize(200, 150),wgt);
		chart->setBackgroundBrush(QBrush(QColor("lightblue")));
		chart->verticalAxis()->setMaxValue(1000);
		chart->horizontalAxis()->setMaxValue(100);

		wgt->setChart(chart);
		QocDataSeries *series = new QocDataSeries(chart);

		for(int i=1; i<95; ++i)
		{
			QocDataItem *item = new QocDataItem(series);
			item->setData(QVariant(i), Qoc::XValueRole);
			item->setData(QVariant(1+(qFloor(qPow(i, 2)) % 1000)), Qoc::YValueRole);
			item->setData(QVariant::fromValue(QColor(static_cast<Qt::GlobalColor>(5+(i%14))).lighter(100 + i/4)), Qoc::ColorRole);
			series->append(item);
		}
		chart->setModel(QVariant::fromValue(series));


//	{
//		QocViewWidget *wgt = new QocViewWidget(w);
//		w->setMinimumSize(QSize(1024, 800));
//		wgt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//		w->layout()->addWidget(wgt);
//		w->layout()->addWidget(pb);
//		QObject::connect(pb, SIGNAL(clicked()), wgt, SLOT(rebuildChart()));

//		QocBarChart *chart = new QocBarChart(QSize(200, 150),wgt);
//		chart->setBackgroundBrush(QBrush(QColor("lightblue")));
//		chart->verticalAxis()->setMaxValue(1000);
//		chart->horizontalAxis()->setMaxValue(100);

//		wgt->setChart(chart);
//		QocDataSeries *series = new QocDataSeries(chart);

//		for(int i=1; i<95; ++i)
//		{
//			QocDataItem *item = new QocDataItem(series);
//			item->setData(QVariant(i), Qoc::XValueRole);
//			item->setData(QVariant(1+(qFloor(qPow(i, 2)) % 1000)), Qoc::YValueRole);
//			item->setData(QVariant::fromValue(QColor(static_cast<Qt::GlobalColor>(5+(i%14))).lighter(100 + i/4)), Qoc::ColorRole);
//			series->append(item);
//		}
//		chart->setModel(QVariant::fromValue(series));
//	}

	w->show();
	return a.exec();
}

