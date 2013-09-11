#ifndef QOC_PIE_CHART_H
#define QOC_PIE_CHART_H

#include "qoc_abstract_chart.h"
#include "qoc_data_series_owner.h"
#include "qoc_pie_sector.h"

#include <QObject>
#include <QPointF>
#include <QFont>

#include "qoc_global.h"

class QOC_API QocPieChart : public QocAbstractChart, QocDataSeriesOwner<QPointF>
{
	Q_OBJECT
	Q_PROPERTY(int startAngle READ startAngle WRITE setStartAngle)

public:
	explicit QocPieChart(QObject *parent = 0);
	
	virtual void draw(QPainter *painter, const QRectF &rect = QRectF());
	virtual QList<QocPieSector *> items();
	virtual void setSeries(QocDataSeries<QPointF> *ds);


	QocPieSector *item(double x);
	QocPieSector *itemAt(size_t i);

	virtual void repaint();

	int startAngle() const;
	QRectF printRect() const;
	QRectF itemsRect() const;


public slots:
	void setStartAngle(int start);


signals:
	
protected:
	virtual void drawBackground(QPainter *painter, const QRectF &rect = QRectF());
	virtual void drawItems(QPainter *painter, const QRectF &rect = QRectF());
	virtual void drawTitle(QPainter *painter, const QRectF &rect = QRectF());

protected:
	QList<QocPieSector *> m_items;
	QRectF m_printRect;
	QRectF m_itemsRect;
	int m_startAngle;

private:
	QRectF getItemsRect(const QRectF &r);
};

#endif // QOC_PIE_CHART_H
