#ifndef QOC_ABSTRACT_CHART_ITEM_H
#define QOC_ABSTRACT_CHART_ITEM_H

#include <QObject>
#include <QRectF>
#include <QString>
#include <QColor>
#include <QPen>
#include <QBrush>

#include "qoc_global.h"

class QocAbstractChart;

class QOC_API QocAbstractChartItem : public QObject
{
	Q_OBJECT
public:
	enum TitleAnchor{ TopAnchor, BottomAnchor, LeftAnchor, RightAnchor };

	QocAbstractChartItem(QObject *parent = 0);

	virtual void draw(QPainter *painter, const QRectF &rect = QRectF()) = 0;

	TitleAnchor titleAnchor() const;
	void setTitleAnchor(TitleAnchor ta);
	QString title() const;
	void setTitle(QString t);
	bool isTitleVisible();
	void setTitleVisible(bool b);

	virtual QRectF boundingRect() const = 0;

	quint64 z() const;
	void setZ(quint64 z);

	QColor color() const;
	void setColor(const QColor &c);

	bool isVisible() const;
	void setVisible(bool b);

	QPen pen() const;
	void setPen(const QPen &pen);

	QBrush brush() const;
	void setBrush(const QBrush &brush);

	bool isSelected() const;
	void setSelected(bool b);

	QPointF position() const;
	void setPosition(const QPointF &p);


protected:
	TitleAnchor m_titleAnchor;
	QString m_title;
	bool m_titleVisible;
	QRectF m_rect;
	quint64 m_z;
	QColor m_color;
	bool m_visible;
	QPen m_pen;
	QBrush m_brush;
	bool m_selected;
	QocAbstractChart *m_chart;
	QPointF m_pos;
};

#endif // QOC_ABSTRACT_CHART_ITEM_H
