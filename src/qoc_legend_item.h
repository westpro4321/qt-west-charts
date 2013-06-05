#ifndef QOC_LEGEND_ITEM_H
#define QOC_LEGEND_ITEM_H

#include <QRectF>


class QocAbstractChartItem;
class QocLegend;
class QPainter;

class QocLegendItem
{
public:
	QocLegendItem(QocLegend *l);

	virtual void draw(QPainter *painter, const QRectF &rect);

	QocAbstractChartItem *item;
	QocLegend *legend;
	QRectF rect;
};

#endif // QOC_LEGEND_ITEM_H
