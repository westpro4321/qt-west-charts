#include "qoc_abstract_value_item.h"

QocAbstractValueItem::QocAbstractValueItem(QObject *parent) :
	QocAbstractChartItem(parent)
{
}

QList<qreal> QocAbstractValueItem::coordinates() const
{
	return m_coords;
}

void QocAbstractValueItem::setCoordinates(const QList<qreal> &co)
{
	m_coords = co;
}
