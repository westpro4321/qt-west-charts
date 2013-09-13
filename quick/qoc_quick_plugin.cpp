#include "qoc_quick_plugin.h"
#include "qoc_quick_abstract_chart.h"
#include "qoc_quick_bar_chart.h"
#include "qoc_quick_data_item.h"
#include "qoc_quick_data_series.h"
#include "qoc_quick_view.h"


QocQuickPlugin::QocQuickPlugin(QObject *parent) :
	QQmlExtensionPlugin(parent)
{
}

void QocQuickPlugin::registerTypes(const char *uri)
{
//	qmlRegisterType<QocQuickAbstractChart>(uri, 1, 0, "AbstractChart");
	qmlRegisterType<QocQuickBarChart>(uri, 1, 0, "BarChart");
	qmlRegisterType<QocQuickDataItem>(uri, 1, 0, "DataItem");
	qmlRegisterType<QocQuickDataSeries>(uri, 1, 0, "DataSeries");
	qmlRegisterType<QocQuickView>(uri, 1, 0, "ChartView");

//	qmlRegisterType<>(uri, 1, 0, "");
}
