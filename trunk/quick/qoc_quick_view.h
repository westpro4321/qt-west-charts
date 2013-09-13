#ifndef QOC_QUICK_VIEW_H
#define QOC_QUICK_VIEW_H

#include <QQuickPaintedItem>

#include "qoc_quick_global.h"

class QocQuickAbstractChart;

class QOC_QUICK_API QocQuickView : public QQuickPaintedItem
{
	Q_OBJECT
	Q_PROPERTY(QocQuickAbstractChart* chart READ chart WRITE setChart NOTIFY chartChanged)
	Q_CLASSINFO("DefaultProperty", "chart")

public:
	explicit QocQuickView(QQuickItem *parent = 0);
	
	QocQuickAbstractChart *chart() const;
	void setChart(QocQuickAbstractChart *chart);

	void paint(QPainter *painter);
signals:
	void chartChanged();
public slots:
	
protected:
	void geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry);
private:
	QocQuickAbstractChart *m_chart;
};

#endif // QOC_QUICK_VIEW_H
