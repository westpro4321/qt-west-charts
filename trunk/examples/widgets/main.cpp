#include <QApplication>
//#include <QPointF>
//#include <QDebug>
//#include <QPainter>
//#include <QHBoxLayout>

//#include "mainwindow.h"

#include <qoc_data_series.h>
#include <qoc_data_item.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//MainWindow mw;
	//mw.show();

	QocDataSeries series;

	return a.exec();
}

