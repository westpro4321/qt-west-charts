#ifndef QOC_QUICK_DATA_SERIES_H
#define QOC_QUICK_DATA_SERIES_H

#include <qoc_data_series.h>

#include "qoc_quick_global.h"

#include <QQmlListProperty>

class QocQuickDataItem;

class QOC_QUICK_API QocQuickDataSeries : public QocDataSeries
{
	Q_OBJECT
	Q_PROPERTY(QQmlListProperty<QocQuickDataItem> items READ items NOTIFY itemsChanged)
	Q_CLASSINFO("DefaultProperty", "items")
public:
	explicit QocQuickDataSeries(QObject *parent = 0);

	QQmlListProperty<QocQuickDataItem> items();
	
signals:
	void itemsChanged();
	
public slots:
	
private:
	static void append_item(QQmlListProperty<QocQuickDataItem> *list, QocQuickDataItem *item);
	static QocQuickDataItem *at_item(QQmlListProperty<QocQuickDataItem> *list, int index);
	static void clear_item(QQmlListProperty<QocQuickDataItem> *list);
	static int count_item(QQmlListProperty<QocQuickDataItem> *list);
};

Q_DECLARE_METATYPE(QocQuickDataSeries *)

#endif // QOC_QUICK_DATA_SERIES_H
