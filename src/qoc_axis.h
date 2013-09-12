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

	qreal minValue() const;
	void setMinValue(qreal v);

	qreal maxValue() const;
	void setMaxValue(qreal v);

	QPointF valueToPos(qreal v);

signals:
	void minValueChanged(qreal);
	void maxValueChanged(qreal);

public slots:
	
private:
	QPointF m_begin;
	QPointF m_end;

	qreal m_min;
	qreal m_max;
};

#endif // QOC_AXIS_H
