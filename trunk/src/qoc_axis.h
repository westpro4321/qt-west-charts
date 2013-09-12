#ifndef QOC_AXIS_H
#define QOC_AXIS_H

#include "qoc_abstract_chart_item.h"

class QocAxis : public QocAbstractChartItem
{
	Q_OBJECT
public:
	explicit QocAxis(QObject *parent = 0);
	QocAxis(const QPointF &begin, const QPointF &end, QObject *parent = 0);
	
	void draw(QPainter *painter, const QRectF &rect = QRectF());
	QRectF boundingRect() const;

signals:
	
public slots:
	
private:
	QPointF m_begin;
	QPointF m_end;
};

#endif // QOC_AXIS_H
