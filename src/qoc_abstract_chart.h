#ifndef QOC_ABSTRACT_CHART_H
#define QOC_ABSTRACT_CHART_H


#include <QObject>
#include <QString>
#include <QFont>
#include <QRectF>
#include <QBrush>
#include <QPen>
#include <QVariant>

#include "qoc_global.h"

class QocAbstractChartItem;
class QocAdaptorModel;

class QOC_API QocAbstractChart : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QVariant model READ model WRITE setModel NOTIFY modelChanged)	
	Q_ENUMS(Layer)
public:
	enum Layer {
		LowLayer,
		ChartLayer,
		HighLayer
	};

	explicit QocAbstractChart(QObject *parent = 0);
	QocAbstractChart(const QSizeF &size, QObject *parent = 0);

	void draw(QPainter *painter, const QRectF &rect = QRectF());

//	virtual QList<QocAbstractChartItem *> items() = 0;

	bool isAntialiased();
	void setAntialiased(bool b);

	QBrush backgroundBrush() const;
	void setBackgroundBrush(const QBrush &brush);

	QBrush foregroundBrush() const;
	void setForegroundBrush(const QBrush &brush);

	QPen selectionPen() const;
	void setSelectionPen(const QPen &pen);

	QVariant model() const;
	virtual void setModel(const QVariant &model);

//	double topMargin();
//	void setTopMargin(double fraction);
//	double bottomMargin();
//	void setBottomMargin(double fraction);
//	double leftMargin();
//	void setLeftMargin(double fraction);
//	double rightMargin();
//	void setRightMargin(double fraction);
//	void setMargins(double top, double bottom, double left, double right);

	QString title() const;
	void setTitle(const QString &title);
	QFont titleFont() const;
	void setTitleFont(const QFont &font);
	bool isTitleVisible() const;
	void setTitleVisible(bool b);
	int titleFlags() const;
	void setTitleFlags(int flags);

	QPointF mapFromGlobal(QPointF p);
	QPointF mapToGlobal(QPointF p);

	void addItem(Layer layer, QocAbstractChartItem *item);
	void removeItem(Layer layer, QocAbstractChartItem *item);
	void removeItem(QocAbstractChartItem *item);

	qreal xScale() const;
	qreal yScale() const;

	QList<QocAbstractChartItem *> items(Layer l);

signals:
	void modelChanged();
	void repaint();
	void update();
	
public slots:

protected:
	virtual void drawBackground(QPainter *painter, const QRectF &rect);
	virtual void drawLowLayer(QPainter *painter, const QRectF &rect) = 0;
	virtual void drawChartLayer(QPainter *painter, const QRectF &rect) = 0;
	virtual void drawHighLayer(QPainter *painter, const QRectF &rect) = 0;
	virtual void drawForeground(QPainter *painter, const QRectF &rect);

protected:
	bool m_antialiased;

	QPen m_selectionPen;
	QBrush m_backgroundBrush;
	QBrush m_foregroundBrush;

//	double m_topMargin;
//	double m_bottomMargin;
//	double m_leftMargin;
//	double m_rightMargin;

	QString m_title;
	QFont m_titleFont;
	bool m_titleVisible;
	int m_titleFlags;
	
	QRectF m_viewGeometry;
	QSizeF m_chartSize;

	QocAdaptorModel *m_adaptorModel;
	QMap<Layer, QList<QocAbstractChartItem *> > m_itemsMap;
};

#endif // QOC_ABSTRACT_CHART_H
