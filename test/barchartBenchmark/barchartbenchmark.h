#ifndef BARCHARTBENCHMARK_H
#define BARCHARTBENCHMARK_H

#include <QObject>
#include <QtTest/QtTest>
#include <QtWidgets>

class BarChartBenchmark : public QObject
{
	Q_OBJECT
public:
	explicit BarChartBenchmark(QObject *parent = 0);
	
signals:
	
private slots:
	void draw();
	void draw_data();
	
};

#endif // BARCHARTBENCHMARK_H
