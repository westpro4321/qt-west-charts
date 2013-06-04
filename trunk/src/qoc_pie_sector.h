#ifndef QOCPIESECTOR_H
#define QOCPIESECTOR_H

#include "qoc_abstract_chart_item.h"

extern const int fullCircle;

class QocPieChart;

class QocPieSector : public QocAbstractChartItem
{
	Q_OBJECT
	Q_PROPERTY(uint offset READ offset WRITE setOffset)

public:
	QocPieSector(const QString &title = QString(), QObject *parent = 0);

	virtual void draw(QPainter *painter, const QRectF &rect = QRectF());

	int startAngle() const;
	int spanAngle() const;
	virtual QRectF boundingRect() const;

	uint offset();

public slots:
	void setStartAngle(int start);
	void setSpanAngle(int span);
	void setOffset(uint pix);

private:
	QRectF getRectWithOffset(const QRectF &rect);

private:
	QocPieChart *m_chart;
	int m_startAngle;
	int m_spanAngle;
	uint m_offset;
};

#endif // QOCPIESECTOR_H
