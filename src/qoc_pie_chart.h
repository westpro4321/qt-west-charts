#ifndef QOC_PIE_CHART_H
#define QOC_PIE_CHART_H

#include "qoc_data_series_owner.h"
#include "qoc_pie_sector.h"

#include <QObject>
#include <QPoint>

class QocPieChart : public QObject, QocDataSeriesOwner<QPoint>
{
	Q_OBJECT
public:
	explicit QocPieChart(QObject *parent = 0);
	
	virtual void draw(QPainter *painter, const QRectF &rect = QRectF());
	virtual void setSeries(QocDataSeries<QPoint> *ds);


signals:
	
public slots:
	
protected:
	QList<QocPieSector *> m_items;
};

#endif // QOC_PIE_CHART_H
