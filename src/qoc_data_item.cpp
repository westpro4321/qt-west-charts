#include "qoc_data_item.h"

QocDataItem::QocDataItem(QObject *parent) :
	QObject(parent)
{
}

void QocDataItem::setData(const QVariant &data, Qoc::ItemDataRole role)
{
	if ( m_values.value(role) != data )
	{
		m_values.insert(role, data);
		emit dataChanged(role);
	}
}

QVariant QocDataItem::data(Qoc::ItemDataRole role)
{
	return m_values.value(role);
}
