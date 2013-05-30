#include <QApplication>
#include <QMainWindow>
#include <QPointF>
#include <QDebug>

#include "qoc_data_series.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QMainWindow mw;

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

