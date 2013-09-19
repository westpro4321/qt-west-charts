#ifndef QOC_AXIS_H
#define QOC_AXIS_H

#include "qoc_abstract_chart_item.h"

class QocAxis : public QocAbstractChartItem
{
	Q_OBJECT
	Q_PROPERTY(QPointF begin READ begin WRITE setBegin NOTIFY beginChanged)
	Q_PROPERTY(QPointF end READ end WRITE setEnd NOTIFY endChanged)
	Q_PROPERTY(qreal minValue READ minValue WRITE setMinValue NOTIFY minValueChanged)
	Q_PROPERTY(qreal maxValue READ maxValue WRITE setMaxValue NOTIFY maxValueChanged)
	Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)

public:
	explicit QocAxis(QObject *parent = 0);
	QocAxis(const QPointF &begin, const QPointF &end, QObject *parent = 0);
	
	void draw(QPainter *painter, const QRectF &rect = QRectF());
	QRectF boundingRect() const;

	QPointF begin() const;
	void setBegin(const QPointF &);

	QPointF end() const;
	void setEnd(const QPointF &);

	qreal minValue() const;
	void setMinValue(qreal v);

	qreal maxValue() const;
	void setMaxValue(qreal v);

	QColor color() const;
	void setColor(const QColor &c);


	QPointF valueToPos(qreal v);
	qreal unit();


signals:
	void beginChanged(const QPointF &);
	void endChanged(const QPointF &);
	void minValueChanged(qreal);
	void maxValueChanged(qreal);
	void colorChanged(const QColor &);

public slots:
	
public:
	QPointF m_begin;
	QPointF m_end;

	qreal m_min;
	qreal m_max;
};

#endif // QOC_AXIS_H
