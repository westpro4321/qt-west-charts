#include "testseries.h"

#include <qoc_bar_chart.h>

TestSeries::TestSeries(QObject *parent) :
	QObject(parent)
{
}

void TestSeries::mapFromGlobal()
{
	QFETCH(qreal, localX);
	QFETCH(qreal, localY);
	QFETCH(qreal, globalX);
	QFETCH(qreal, globalY);

	QocBarChart c(QSizeF(200, 150));
	c.setViewGeometry(QRectF(0, 0, 640, 480));

	QEXPECT_FAIL("intentional fail", "This test should have failed.", Continue);
	QCOMPARE(QPointF(localX, localY), c.mapFromGlobal(QPointF(globalX, globalY)));
}

void TestSeries::mapFromGlobal_data()
{
	QTest::addColumn<qreal>("localX");
	QTest::addColumn<qreal>("localY");
	QTest::addColumn<qreal>("globalX");
	QTest::addColumn<qreal>("globalY");

	QTest::newRow("top left") << 0.0 << 0.0 << 0.0 << 0.0;
	QTest::newRow("bottom right") << 200.0 << 150.0 << 640.0 << 480.0;
	QTest::newRow("center") << 100.0 << 75.0 << 320.0 << 240.0;
	QTest::newRow("top border") << 50.0 << 0.0 << 160.0 << 0.0;
	QTest::newRow("left border") << 0.0 << 50.0 << 0.0 << 160.0;
	QTest::newRow("intentional fail") << 100.0 << 75.0 << 319.9 << 239.9;
}

void TestSeries::mapToGlobal()
{
	QFETCH(qreal, localX);
	QFETCH(qreal, localY);
	QFETCH(qreal, globalX);
	QFETCH(qreal, globalY);

	QocBarChart c(QSizeF(200, 150));
	c.setViewGeometry(QRectF(0, 0, 640, 480));

	QEXPECT_FAIL("intentional fail", "This test should have failed.", Continue);
	QCOMPARE(QPointF(globalX, globalY), c.mapToGlobal(QPointF(localX, localY)));
}

void TestSeries::mapToGlobal_data()
{
	mapFromGlobal_data();
}
