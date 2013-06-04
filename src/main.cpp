#include <QApplication>
#include <QPointF>
#include <QDebug>
#include <QPainter>
#include <QHBoxLayout>

#include "mainwindow.h"
#include "qoc_data_series.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow mw;
	mw.show();
	return a.exec();
}

