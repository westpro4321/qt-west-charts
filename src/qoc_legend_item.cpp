#include "qoc_legend_item.h"
#include "qoc_abstract_chart_item.h"

#include <QPainter>

QocLegendItem::QocLegendItem(QocLegend *l) :
	legend(l)
{
}

void QocLegendItem::draw(QPainter *painter, const QRectF &rect)
{
	painter->save();

	painter->setPen(item->pen());
	painter->setBrush(item->brush());
	//painter->drawRect();

	painter->restore();
}
