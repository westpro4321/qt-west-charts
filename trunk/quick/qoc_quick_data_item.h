#ifndef QOC_QUICK_DATA_ITEM_H
#define QOC_QUICK_DATA_ITEM_H

#include <qoc_data_item.h>

#include "qoc_quick_global.h"

#include <QColor>

class QOC_QUICK_API QocQuickDataItem : public QocDataItem
{
	Q_OBJECT
	Q_PROPERTY(qreal x READ x WRITE setX NOTIFY xChanged)
	Q_PROPERTY(qreal y READ y WRITE setY NOTIFY yChanged)
	Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)

public:
	explicit QocQuickDataItem(QObject *parent = 0);
	
	qreal x() const;
	void setX(qreal x);
	qreal y() const;
	void setY(qreal y);
	QColor color() const;
	void setColor(const QColor &c);

signals:
	void xChanged(qreal);
	void yChanged(qreal);
	void colorChanged(const QColor &);
	
public slots:

private slots:
	void onDataChanged(Qoc::ItemDataRole role);
	
};

#endif // QOC_QUICK_DATA_ITEM_H
