#ifndef QOC_PIE_CHART_H
#define QOC_PIE_CHART_H

#include "qoc_data_series_owner.h"
#include "qoc_pie_sector.h"

#include <QObject>
#include <QPointF>

class QocPieChart : public QObject, QocDataSeriesOwner<QPointF>
{
	Q_OBJECT
	Q_PROPERTY(int startAngle READ startAngle WRITE setStartAngle)

public:
	explicit QocPieChart(QObject *parent = 0);
	
	virtual void draw(QPainter *painter, const QRectF &rect = QRectF());
	virtual void setSeries(QocDataSeries<QPointF> *ds);

	bool isAntialiased();
	void setAntialiased(bool b);

	QBrush background() const;
	void setBackground(QBrush *brush);

	double xMargin();
	void setXMargin(double fraction);
	double yMargin();
	void setYMargin(double fraction);
	void setMargins(double x, double y);

	QocPieSector *item(double x);
	virtual void repaint();

	int startAngle();

public slots:
	void setStartAngle(int start);


signals:
	
public slots:
	
protected:
	QList<QocPieSector *> m_items;
	bool m_antialiased;
	QBrush *m_backgroundBrush;
	double m_xMargin;
	double m_yMargin;
	QRectF m_printRect;
	int m_startAngle;

private:
	QRectF getPrintRect(const QRectF &r);
};

#endif // QOC_PIE_CHART_H
