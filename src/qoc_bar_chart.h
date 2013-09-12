#ifndef QOC_BAR_CHART_H
#define QOC_BAR_CHART_H

#include "qoc_abstract_chart.h"

class QocAxis;

class QOC_API QocBarChart : public QocAbstractChart
{
	Q_OBJECT
	Q_PROPERTY(uint radius READ radius WRITE setRadius NOTIFY radiusChanged)
public:
	explicit QocBarChart(QObject *parent = 0);
	QocBarChart(const QSizeF &size, QObject *parent = 0);

	virtual void setModel(const QVariant &model);

	uint radius() const;
	void setRadius(uint r);
signals:
	void radiusChanged(uint);
	
public slots:
	
protected:
	virtual void drawLowLayer(QPainter *painter, const QRectF &rect);
	virtual void drawChartLayer(QPainter *painter, const QRectF &rect);
	virtual void drawHighLayer(QPainter *painter, const QRectF &rect);

	void setupAxes();
private:
	uint m_radius;
	QocAxis *m_vAxis;
	QocAxis *m_hAxis;
};

#endif // QOC_BAR_CHART_H
