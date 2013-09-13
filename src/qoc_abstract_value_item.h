#ifndef QOC_ABSTRACT_VALUE_ITEM_H
#define QOC_ABSTRACT_VALUE_ITEM_H

#include "qoc_abstract_chart_item.h"

#include <QList>

class QocAbstractValueItem : public QocAbstractChartItem
{
	Q_OBJECT
	Q_PROPERTY(qreal value READ value WRITE setValue NOTIFY valueChanged)
public:
	explicit QocAbstractValueItem(QObject *parent = 0);
	
	QList<qreal> coordinates() const;
	void setCoordinates(const QList<qreal> &co);

	qreal value() const;
	void setValue(qreal val);
signals:
	void valueChanged(qreal val);
public slots:
	
protected:
	QList<qreal> m_coords;
	qreal m_value;
};

#endif // QOC_ABSTRACT_VALUE_ITEM_H
