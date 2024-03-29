#ifndef QOC_BAR_CHART_H
#define QOC_BAR_CHART_H

#include "qoc_abstract_chart.h"

class QocAxis;

class QOC_API QocBarChart : public QocAbstractChart
{
	Q_OBJECT
	Q_PROPERTY(qreal radius READ radius WRITE setRadius NOTIFY radiusChanged)
	Q_PROPERTY(QocAxis* verticalAxis READ verticalAxis)
	Q_PROPERTY(QocAxis* horizontalAxis READ horizontalAxis)
	Q_PROPERTY(qreal radius READ radius WRITE setRadius NOTIFY radiusChanged)

public:
	explicit QocBarChart(QObject *parent = 0);
	QocBarChart(const QSizeF &size, QObject *parent = 0);

	virtual void setModel(const QVariant &model);

	qreal radius() const;
	void setRadius(qreal r);

	QocAxis *verticalAxis();
	QocAxis *horizontalAxis();

signals:
	void radiusChanged(qreal);
	
public slots:
	
protected:
	virtual void drawLowLayer(QPainter *painter, const QRectF &rect);
	virtual void drawChartLayer(QPainter *painter, const QRectF &rect);
	virtual void drawHighLayer(QPainter *painter, const QRectF &rect);

	void setupAxes();

private slots:
	virtual void onItemValueChanged(qreal val);
private:
	qreal m_radius;
	QocAxis *m_vAxis;
	QocAxis *m_hAxis;

friend class QocBarItem;
};

#endif // QOC_BAR_CHART_H
