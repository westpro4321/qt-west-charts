#ifndef QOC_ABSTRACT_CHART_H
#define QOC_ABSTRACT_CHART_H


#include <QObject>
#include <QString>
#include <QFont>
#include <QRectF>

class QocAbstractChartItem;

class QocAbstractChart : public QObject
{
	Q_OBJECT
public:
	explicit QocAbstractChart(QObject *parent = 0);
	
	virtual void draw(QPainter *painter, const QRectF &rect = QRectF()) = 0;
//	virtual QList<QocAbstractChartItem *> items() = 0;

	bool isAntialiased();
	void setAntialiased(bool b);

	QBrush background() const;
	void setBackground(QBrush *brush);

	QPen selectionPen() const;
	void setSelectionPen(QPen *pen);

	double topMargin();
	void setTopMargin(double fraction);
	double bottomMargin();
	void setBottomMargin(double fraction);
	double leftMargin();
	void setLeftMargin(double fraction);
	double rightMargin();
	void setRightMargin(double fraction);
	void setMargins(double top, double bottom, double left, double right);

	QString title() const;
	void setTitle(const QString &title);
	QFont titleFont() const;
	void setTitleFont(const QFont &font);
	bool isTitleVisible() const;
	void setTitleVisible(bool b);
	int titleFlags() const;
	void setTitleFlags(int flags);


signals:
	
public slots:

protected:
	bool m_antialiased;

	QPen *m_selectionPen;
	QBrush *m_backgroundBrush;

	double m_topMargin;
	double m_bottomMargin;
	double m_leftMargin;
	double m_rightMargin;

	QString m_title;
	QFont m_titleFont;
	bool m_titleVisible;
	int m_titleFlags;
	
};

#endif // QOC_ABSTRACT_CHART_H
