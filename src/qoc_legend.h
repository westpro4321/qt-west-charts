#ifndef QOC_LEGEND_H
#define QOC_LEGEND_H

#include <QObject>
#include <QFont>
#include <QSize>


class QocPieChart;
class QocAbstractChartItem;


class QocLegend : public QObject
{
	Q_OBJECT
public:
	explicit QocLegend(QObject *parent = 0);
	
	virtual void draw(QPainter *painter, const QRectF &rect);

	QFont font() const;
	void setFont(const QFont &font);

	QSize colorSize() const;
	void setColorSize(QSize size);

	void setChart(QocPieChart *);
signals:
	
public slots:
	
private:
	QFont m_font;
	QSize m_size;
	QocPieChart *m_chart;
};

#endif // QOC_LEGEND_H
