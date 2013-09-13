#ifndef QOC_QUICK_VIEW_H
#define QOC_QUICK_VIEW_H

#include <QQuickPaintedItem>

#include "qoc_quick_global.h"

class QOC_QUICK_API QocQuickView : public QQuickPaintedItem
{
	Q_OBJECT
public:
	explicit QocQuickView(QQuickItem *parent = 0);
	
signals:
	
public slots:
	
};

#endif // QOC_QUICK_VIEW_H
