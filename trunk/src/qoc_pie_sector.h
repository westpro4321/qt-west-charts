#ifndef QOC_PIE_SECTOR_H
#define QOC_PIE_SECTOR_H

#include "qoc_abstract_chart_item.h"

#include <QPointF>

extern const int g_fullCircle;

class QocPieChart;

class QocPieSector : public QocAbstractChartItem
{
	Q_OBJECT
	Q_PROPERTY(uint offset READ offset WRITE setOffset)
	Q_ENUMS(LabelMode)

public:
	enum LabelMode { TitleOnlyMode, PercentOnlyMode, TitlePercentMode };

	QocPieSector(const QString &title = QString(), QObject *parent = 0);

	virtual void draw(QPainter *painter, const QRectF &rect = QRectF());
	virtual void drawTitle(QPainter *painter, const QRectF &rect = QRectF());


	int startAngle() const;
	int spanAngle() const;
	virtual QRectF boundingRect() const;

	uint offset();

	LabelMode labelMode() const;
	void setLabelMode(LabelMode mode);

public slots:
	void setStartAngle(int start);
	void setSpanAngle(int span);
	void setOffset(uint pix);

private:
	QRectF getRectWithOffset(const QRectF &rect);
	QRectF getTitleRect(const QRectF &rect);
	double percentage();

private:
	QocPieChart *m_chart;
	int m_startAngle;
	int m_spanAngle;
	uint m_offset;
	LabelMode m_mode;
};

#endif // QOC_PIE_SECTOR_H
