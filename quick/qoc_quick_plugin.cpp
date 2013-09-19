#include "qoc_quick_plugin.h"
#include "qoc_quick_abstract_chart.h"
#include "qoc_quick_bar_chart.h"
#include "qoc_quick_data_item.h"
#include "qoc_quick_data_series.h"
#include "qoc_quick_view.h"

#include <qoc_axis.h>
#include <qoc_bar_item.h>

#include <QDebug>

QocQuickPlugin::QocQuickPlugin(QObject *parent) :
	QQmlExtensionPlugin(parent)
{
}

void QocQuickPlugin::registerTypes(const char *uri)
{
	Q_ASSERT_X(uri == QLatin1String("QocQuick"), "register", uri);

//	qmlRegisterInterface<QocQuickAbstractChart>("AbstractChart");
//	qmlRegisterType<QocQuickBarChart>("qoc.barchart", 1, 0, "BarChart");
//	qmlRegisterType<QocQuickDataItem>("qoc.dataitem", 1, 0, "DataItem");
//	qmlRegisterType<QocQuickDataSeries>("qoc.dataseries", 1, 0, "DataSeries");
//	qmlRegisterType<QocQuickView>("qoc.chartview", 1, 0, "ChartView");

	qDebug() << qmlRegisterType<QocQuickAbstractChart>(uri, 1, 0, "AbstractChart");
	qDebug() << qmlRegisterType<QocQuickBarChart>(uri, 1, 0, "BarChart");
	qDebug() << qmlRegisterType<QocQuickDataItem>(uri, 1, 0, "DataItem");
	qDebug() << qmlRegisterType<QocQuickDataSeries>(uri, 1, 0, "DataSeries");
	qDebug() << qmlRegisterType<QocQuickView>(uri, 1, 0, "ChartView");

	qDebug() << qmlRegisterInterface<QocAbstractChartItem>("AbstractItem");
	qDebug() << qmlRegisterType<QocAxis>(uri, 1, 0, "Axis");

	qDebug() << qmlRegisterInterface<QocAbstractValueItem>("AbstractValueItem");
	qDebug() << qmlRegisterType<QocBarItem>(uri, 1, 0, "BarItem");

//	qmlRegisterType<>(uri, 1, 0, "");
}
