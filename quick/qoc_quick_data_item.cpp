#include "qoc_quick_data_item.h"

QocQuickDataItem::QocQuickDataItem(QObject *parent) :
	QocDataItem(parent)
{
	connect(this, SIGNAL(dataChanged(Qoc::ItemDataRole)), this, SLOT(onDataChanged(Qoc::ItemDataRole)));
}

qreal QocQuickDataItem::x() const
{
	return m_values.value(Qoc::XValueRole).toReal();
}

void QocQuickDataItem::setX(qreal x)
{
	m_values.insert(Qoc::XValueRole, x);
}

qreal QocQuickDataItem::y() const
{
	return m_values.value(Qoc::YValueRole).toReal();
}

void QocQuickDataItem::setY(qreal y)
{
	m_values.insert(Qoc::YValueRole, y);
}

QColor QocQuickDataItem::color() const
{
	return m_values.value(Qoc::ColorRole).value<QColor>();
}

void QocQuickDataItem::setColor(const QColor &c)
{
	m_values.insert(Qoc::ColorRole, c);
}

void QocQuickDataItem::onDataChanged(Qoc::ItemDataRole role)
{
	switch ( role )
	{
		case Qoc::XValueRole:
			emit xChanged(m_values.value(role).toReal());
			break;

		case Qoc::YValueRole:
			emit yChanged(m_values.value(role).toReal());
			break;

		case Qoc::ColorRole:
			emit colorChanged(m_values.value(role).value<QColor>());
			break;
		default:
			break;
	}
}
