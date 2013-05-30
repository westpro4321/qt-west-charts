#ifndef QOC_ABSTRACT_CHART_H
#define QOC_ABSTRACT_CHART_H

#include <QObject>
#include <QRectF>
#include <QList>

class QPainter;

class QocDataSeries;
class QocAbstractChartItem;

class QocAbstractChart : public QObject
{
	Q_OBJECT
public:
	explicit QocAbstractChart(QObject *parent = 0);
	
	virtual void draw(QPainter *painter, const QRectF &rect = QRectF()) = 0;

	virtual void setSeries(QocDataSeries *ds);

	virtual void addItem(QocAbstractChartItem *item);
	virtual bool removeItem(QocAbstractChartItem *item);



signals:
	
public slots:
	
protected:
	QocDataSeries *m_series;
	QList<QocAbstractChartItem *> m_items;
};

#endif // QOC_ABSTRACT_CHART_H
