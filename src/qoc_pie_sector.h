#ifndef QOCPIESECTOR_H
#define QOCPIESECTOR_H

#include "qoc_abstract_chart_item.h"


class QocPieSector : public QocAbstractChartItem
{
public:
	QocPieSector();

	virtual void draw(QPainter *painter, const QRectF &rect = QRectF());

	int startAngle() const;
	void setStartAngle(int start);

	int spanAngle() const;
	void setSpanAngle(int span);

private:
	int m_startAngle;
	int m_spanAngle;
};

#endif // QOCPIESECTOR_H
