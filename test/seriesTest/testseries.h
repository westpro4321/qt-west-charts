#ifndef TESTSERIES_H
#define TESTSERIES_H

#include <QObject>
#include <QtTest/QtTest>


class TestSeries : public QObject
{
	Q_OBJECT
public:
	explicit TestSeries(QObject *parent = 0);
	
private slots:
	void mapFromGlobal();
	void mapFromGlobal_data();

	void mapToGlobal();
	void mapToGlobal_data();
};

#endif // TESTSERIES_H
