#include <QApplication>
#include <QDebug>
#include <QtCore/qmath.h>

#include <qoc_data_series.h>
#include <qoc_data_item.h>
#include <qoc_adaptor_model.h>
#include <qoc_view_widget.h>
#include <qoc_bar_chart.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QocViewWidget *wgt = new QocViewWidget;
	QocBarChart *bc = new QocBarChart(QSize(200, 150),wgt);
	QocDataSeries *series = new QocDataSeries(bc);

	for(int i=0; i<5; ++i)
	{
		QocDataItem *item = new QocDataItem(series);
		item->setData(QColor(static_cast<Qt::GlobalColor>(4+i)), Qoc::ColorRole);
		item->setData(i, Qoc::XValueRole);
		item->setData(qPow(i, 2), Qoc::YValueRole);
		series->append(item);
	}

	QVariant model = QVariant::fromValue(series);
//	QocAdaptorModel *adapt = new QocAdaptorModel();
//	adapt->setModel(model);
	bc->setModel(model);
	bc->setBackgroundBrush(QBrush("lightblue"));
	bc->setForegroundBrush(QBrush("yellow", Qt::Dense6Pattern));

	wgt->setChart(bc);

	wgt->show();
	return a.exec();
}


