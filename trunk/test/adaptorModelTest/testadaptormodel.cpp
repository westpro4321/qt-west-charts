#include "testadaptormodel.h"

#include <qoc_adaptor_model.h>
#include <qoc_data_series.h>


TestAdaptorModel::TestAdaptorModel(QObject *parent) :
	QObject(parent)
{
}

void TestAdaptorModel::insert()
{
	QFETCH(QVariant, model);

	QocAdaptorModel a;
	a.setModel(model);

	for(int i=0; i<3; ++i)
	{
		a.insert(i);
		QCOMPARE(a.size(), i+1);
	}
}

void TestAdaptorModel::insert_data()
{
	insertModels();
}

void TestAdaptorModel::modify()
{
	QFETCH(QVariant, model);

	QocAdaptorModel a;
	a.setModel(model);
	a.insert(0);

	for(qreal i=0; i<3; ++i)
	{
		a.setData(0, 0, QVariant(i), Qoc::XValueRole);
		QCOMPARE(a.data(0, 0, Qoc::XValueRole).toReal(), i);
	}

	for(int i=0; i<3; ++i)
	{
		a.setData(0, 0, QVariant::fromValue(QColor(static_cast<Qt::GlobalColor>(i+5))), Qoc::ColorRole);
		QCOMPARE(a.data(0, 0, Qoc::ColorRole).value<QColor>(), QColor(static_cast<Qt::GlobalColor>(i+5)));
	}

}

void TestAdaptorModel::modify_data()
{
	insertModels();
}

void TestAdaptorModel::remove()
{
	QFETCH(QVariant, model);

	QocAdaptorModel a;
	a.setModel(model);

	for(int i=0; i<3; ++i)
	{
		a.insert(i);
	}

	for(int i=2; i>= 0; --i)
	{
		QCOMPARE(a.size(), i+1);

		a.removeAt(i);
	}
	QCOMPARE(a.size(), 0);
}

void TestAdaptorModel::remove_data()
{
	insertModels();
}

void TestAdaptorModel::insertModels()
{
	QTest::addColumn<QVariant>("model");

	QTest::newRow("QocDataSeries") << QVariant::fromValue(new QocDataSeries(this));
}
