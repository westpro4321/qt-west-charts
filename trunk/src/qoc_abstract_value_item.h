#ifndef QOC_ABSTRACT_VALUE_ITEM_H
#define QOC_ABSTRACT_VALUE_ITEM_H

#include "qoc_abstract_chart_item.h"

#include <QList>

class QocAbstractValueItem : public QocAbstractChartItem
{
	Q_OBJECT
public:
	explicit QocAbstractValueItem(QObject *parent = 0);
	
	QList<qreal> coordinates() const;
	void setCoordinates(const QList<qreal> &co);
signals:
	
public slots:
	
protected:
	QList<qreal> m_coords;
};

#endif // QOC_ABSTRACT_VALUE_ITEM_H
