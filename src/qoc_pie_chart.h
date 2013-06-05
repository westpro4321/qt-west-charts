#ifndef QOC_PIE_CHART_H
#define QOC_PIE_CHART_H

#include "qoc_data_series_owner.h"
#include "qoc_pie_sector.h"

#include <QObject>
#include <QPointF>
#include <QFont>


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

	double topMargin();
	void setTopMargin(double fraction);
	double bottomMargin();
	void setBottomMargin(double fraction);
	double leftMargin();
	void setLeftMargin(double fraction);
	double rightMargin();
	void setRightMargin(double fraction);

	void setMargins(double top, double bottom, double left, double right);

	QocPieSector *item(double x);
	virtual void repaint();

	int startAngle();

	QString title() const;
	void setTitle(const QString &title);
	QFont titleFont() const;
	void setTitleFont(const QFont &font);
	bool isTitleVisible() const;
	void setTitleVisible(bool b);
	int titleFlags() const;
	void setTitleFlags(int flags);

public slots:
	void setStartAngle(int start);


signals:
	
protected:
	virtual void drawBackground(QPainter *painter, const QRectF &rect = QRectF());
	virtual void drawItems(QPainter *painter, const QRectF &rect = QRectF());
	virtual void drawTitle(QPainter *painter, const QRectF &rect = QRectF());

protected:
	QList<QocPieSector *> m_items;
	bool m_antialiased;
	QBrush *m_backgroundBrush;
	double m_topMargin;
	double m_bottomMargin;
	double m_leftMargin;
	double m_rightMargin;
	QRectF m_printRect;
	int m_startAngle;

	QString m_title;
	QFont m_titleFont;
	bool m_titleVisible;
	int m_titleFlags;

private:
	QRectF getItemsRect(const QRectF &r);
};

#endif // QOC_PIE_CHART_H
