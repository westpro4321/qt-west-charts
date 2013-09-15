#include "qoc_data_series.h"
#include "qoc_data_item.h"

//template <Qoc::ItemDataRole role>
//bool lessThan(const QocDataItem *a, const QocDataItem *b)
//{
//	return a->data(role) < b->data(role);
//}


QocDataSeries::QocDataSeries(QObject *parent) :
	QObject(parent)
{
}

QString QocDataSeries::title() const
{
	return m_title;
}

void QocDataSeries::setTitle(const QString &s)
{
	if ( m_title != s )
	{
		m_title = s;
		emit titleChanged(s);
	}
}

QColor QocDataSeries::color() const
{
	return m_color;
}

void QocDataSeries::setColor(const QColor &c)
{
	if ( m_color != c )
	{
		m_color = c;
		emit colorChanged(c);
	}
}

void QocDataSeries::append(QocDataItem *item)
{
	m_items.append(item);
	emit dataInserted(m_items.size()-1);
}

void QocDataSeries::insert(int index, QocDataItem *item)
{
	m_items.insert(index, item);
	emit dataInserted(index);
}

void QocDataSeries::removeAt(int index)
{
	//TODO:
	m_items.removeAt(index);
	emit dataRemoved(index);
}

QVariant QocDataSeries::data(int index, Qoc::ItemDataRole role) const
{
//	QVariant retVal;
//	if ( index >=0 && index < m_items.size() )
//	{
//		retVal = m_items.at(index)->data(role);
//	}
//	return retVal;

	return m_items.at(index)->data(role);
}

void QocDataSeries::setData(int index, const QVariant &data, Qoc::ItemDataRole role)
{
	m_items[index]->setData(data, role);
}

int QocDataSeries::size() const
{
	return m_items.size();
}

void QocDataSeries::onItemDataChanged(Qoc::ItemDataRole role)
{
	QocDataItem *item = qobject_cast<QocDataItem *>(sender());
	Q_ASSERT(item);

	emit dataChanged(m_items.indexOf(item), role);
}

//void QocDataSeries::sort(Qoc::ItemDataRole role, Qt::SortOrder)
//{
//	qSort(m_items.begin(), m_items.end(), lessThan<role>);
//}
