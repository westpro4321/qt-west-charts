#include <QApplication>
#include <QMainWindow>
#include <QPointF>
#include <QDebug>
#include <QPainter>
#include <QVBoxLayout>

#include "testwidget.h"
#include "qoc_data_series.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QMainWindow mw;
	mw.setLayout(new QVBoxLayout(&mw));
	mw.layout()->addWidget(new TestWidget(&mw));

	QocDataSeries<QPointF> series;

	QVector<QPointF> vector;
	vector.append(QPointF(1,1));
	vector.append(QPointF(1,2));
	vector.append(QPointF(1,3));
	vector.append(QPointF(1,4));

	series.setSamples(vector);

	qDebug() << series.samples();

	mw.show();


	return a.exec();
}

