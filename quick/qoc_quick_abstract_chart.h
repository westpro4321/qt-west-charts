#ifndef QOC_QUICK_ABSTRACT_CHART_H
#define QOC_QUICK_ABSTRACT_CHART_H

#include <qoc_abstract_chart.h>

#include "qoc_quick_global.h"

class QOC_QUICK_API QocQuickAbstractChart : public QocAbstractChart
{
	Q_OBJECT
	Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor NOTIFY backgroundColorChanged)
	Q_PROPERTY(QColor foregroundColor READ foregroundColor WRITE setForegroundColor NOTIFY foregroundColorChanged)

public:
	explicit QocQuickAbstractChart(QObject *parent = 0);
	
	QColor backgroundColor() const;
	void setBackgroundColor(const QColor &c);
	QColor foregroundColor() const;
	void setForegroundColor(const QColor &c);

signals:
	void backgroundColorChanged(const QColor &);
	void foregroundColorChanged(const QColor &);

public slots:
	
};

#endif // QOC_QUICK_ABSTRACT_CHART_H
