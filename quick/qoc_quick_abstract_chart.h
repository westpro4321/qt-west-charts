#ifndef QOC_QUICK_ABSTRACT_CHART_H
#define QOC_QUICK_ABSTRACT_CHART_H

#include <QObject>
#include <QString>
#include <QFont>
#include <QRectF>
#include <QBrush>
#include <QPen>
#include <QVariant>

#include "qoc_quick_global.h"

class QocAbstractChart;
class QPainter;

class QOC_QUICK_API QocQuickAbstractChart : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QVariant model READ model WRITE setModel NOTIFY modelChanged)
	Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor NOTIFY backgroundColorChanged)
	Q_PROPERTY(QColor foregroundColor READ foregroundColor WRITE setForegroundColor NOTIFY foregroundColorChanged)
	Q_PROPERTY(QRectF viewGeometry READ viewGeometry WRITE setViewGeometry NOTIFY viewGeometryChanged)
	Q_PROPERTY(QSizeF size READ size WRITE setSize NOTIFY sizeChanged)


public:
	explicit QocQuickAbstractChart(QObject *parent = 0);
	
	QColor backgroundColor() const;
	void setBackgroundColor(const QColor &c);
	QColor foregroundColor() const;
	void setForegroundColor(const QColor &c);
	QVariant model() const;
	virtual void setModel(const QVariant &model);

	QRectF viewGeometry() const;
	void setViewGeometry(const QRectF &r);

	QSizeF size() const;
	void setSize(const QSizeF &size);

	void draw(QPainter *painter, const QRectF &rect=QRectF());

signals:
	void modelChanged();
	void backgroundColorChanged(const QColor &);
	void foregroundColorChanged(const QColor &);
	void viewGeometryChanged(const QRectF &);
	void sizeChanged(const QSizeF &);

	void repaint();
	void update();

protected:
	QocAbstractChart *m_chart;
};

#endif // QOC_QUICK_ABSTRACT_CHART_H
