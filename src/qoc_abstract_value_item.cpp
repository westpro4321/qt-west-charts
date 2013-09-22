#include "qoc_abstract_value_item.h"

#include <QDebug>


QocAbstractValueItem::QocAbstractValueItem(QObject *parent) :
	QocAbstractChartItem(parent),
	m_value(0)
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

qreal QocAbstractValueItem::value() const
{
	return m_value;
}

void QocAbstractValueItem::setValue(qreal val)
{
	qDebug() << Q_FUNC_INFO << m_value << val;
	if ( m_value != val )
	{
		m_value = val;
		emit valueChanged(val);
	}
}
