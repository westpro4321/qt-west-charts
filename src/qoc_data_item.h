#ifndef QOC_DATA_ITEM_H
#define QOC_DATA_ITEM_H

#include <QObject>
#include <QMap>
#include <QVariant>

#include "qoc_global.h"

class QOC_API QocDataItem : public QObject
{
	Q_OBJECT
public:
	explicit QocDataItem(QObject *parent = 0);
	
	void setData(const QVariant &data, Qoc::ItemDataRole role);
	QVariant data(Qoc::ItemDataRole role);
signals:
	void dataChanged(Qoc::ItemDataRole);
	
public slots:
	
protected:
	QMap<Qoc::ItemDataRole, QVariant> m_values;
};

#endif // QOC_DATA_ITEM_H
