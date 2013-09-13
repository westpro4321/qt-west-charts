#include <QApplication>
#include <QDebug>
#include <QtCore/qmath.h>

#include <QLayout>
#include <QHBoxLayout>
#include <QPushButton>

#include <qoc_data_series.h>
#include <qoc_data_item.h>
#include <qoc_adaptor_model.h>
#include <qoc_view_widget.h>
#include <qoc_bar_chart.h>

const int itemsCount = 13;


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QWidget *w = new QWidget;
	w->setMinimumSize(480, 360);
	w->setLayout(new QHBoxLayout(w));

	QocViewWidget *wgt = new QocViewWidget(w);
	wgt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	QocBarChart *bc = new QocBarChart(QSize(200, 150),wgt);
	QocDataSeries *series = new QocDataSeries(bc);


	for(int i=0; i<itemsCount; ++i)
	{
		QocDataItem *item = new QocDataItem(series);
		item->setData(QColor(static_cast<Qt::GlobalColor>(4+i)), Qoc::ColorRole);
		item->setData(i+1, Qoc::XValueRole);
		item->setData(qPow(i-itemsCount/2, 2) + 5, Qoc::YValueRole);
		series->append(item);
	}
	for(int i=0; i<itemsCount; ++i)
	{
		QocDataItem *item = new QocDataItem(series);
		item->setData(QColor(static_cast<Qt::GlobalColor>(4+i)).lighter(140), Qoc::ColorRole);
		item->setData(itemsCount + i + 1, Qoc::XValueRole);
		item->setData(qPow(i-itemsCount/2, 2) + 5, Qoc::YValueRole);
		series->append(item);
	}



	QVariant model = QVariant::fromValue(series);
//	QocAdaptorModel *adapt = new QocAdaptorModel();
//	adapt->setModel(model);
	bc->setModel(model);
	bc->setBackgroundBrush(QBrush("lightblue"));
//	bc->setForegroundBrush(QBrush("yellow", Qt::CrossPattern));

	wgt->setChart(bc);

	QPushButton *pb = new QPushButton(w);
	pb->setText("Rebuild");
	QObject::connect(pb, SIGNAL(clicked()), wgt, SLOT(rebuildChart()));

	w->layout()->addWidget(wgt);
	w->layout()->addWidget(pb);
	w->show();
	return a.exec();
}


