#ifndef QOC_BAR_ITEM_H
#define QOC_BAR_ITEM_H

#include "qoc_abstract_value_item.h"

class QOC_API QocBarItem : public QocAbstractValueItem
{
	Q_OBJECT
	Q_PROPERTY(qreal height READ height WRITE setHeight NOTIFY heightChanged)
public:
	explicit QocBarItem(QObject *parent = 0);
	
	qreal height() const;
	void setHeight(qreal h);

	virtual void draw(QPainter *painter, const QRectF &rect = QRectF());
	virtual QRectF boundingRect() const;

signals:
	void heightChanged(qreal);
public slots:
	
protected:
	qreal m_height;
};

#endif // QOC_BAR_ITEM_H
