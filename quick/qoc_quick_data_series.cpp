#include "qoc_quick_data_series.h"
#include "qoc_quick_data_item.h"


QocQuickDataSeries::QocQuickDataSeries(QObject *parent) :
	QocDataSeries(parent)
{
	connect(this, SIGNAL(dataInserted(int)), this, SIGNAL(itemsChanged()));
	connect(this, SIGNAL(dataChanged(int,Qoc::ItemDataRole)), this, SIGNAL(itemsChanged()));
	connect(this, SIGNAL(dataRemoved(int)), this, SIGNAL(itemsChanged()));
}

QQmlListProperty<QocQuickDataItem> QocQuickDataSeries::items()
{
	return QQmlListProperty<QocQuickDataItem>(this, 0,
											  &QocQuickDataSeries::append_item,
											  &QocQuickDataSeries::count_item,
											  &QocQuickDataSeries::at_item,
											  &QocQuickDataSeries::clear_item);
}

void QocQuickDataSeries::append_item(QQmlListProperty<QocQuickDataItem> *list, QocQuickDataItem *item)
{
	QocQuickDataSeries *s = qobject_cast<QocQuickDataSeries *>(list->object);
	if ( s && item )
	{
		item->setParent(s);
		s->m_items.append(item);
		s->itemsChanged();
	}
}

QocQuickDataItem *QocQuickDataSeries::at_item(QQmlListProperty<QocQuickDataItem> *list, int index)
{
	QocQuickDataSeries *s = qobject_cast<QocQuickDataSeries *>(list->object);
	if ( s )
	{
		return qobject_cast<QocQuickDataItem *>(s->m_items[index]);
	}

	return 0;
}

void QocQuickDataSeries::clear_item(QQmlListProperty<QocQuickDataItem> *list)
{
	QocQuickDataSeries *s = qobject_cast<QocQuickDataSeries *>(list->object);
	if ( s )
	{
		s->m_items.clear();
		s->itemsChanged();
	}
}

int QocQuickDataSeries::count_item(QQmlListProperty<QocQuickDataItem> *list)
{
	QocQuickDataSeries *s = qobject_cast<QocQuickDataSeries *>(list->object);
	if ( s )
	{
		return s->m_items.count();
	}
	return 0;
}
