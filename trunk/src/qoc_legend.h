#ifndef QOC_LEGEND_H
#define QOC_LEGEND_H

#include <QObject>
#include <QFont>

class QocLegend : public QObject
{
	Q_OBJECT
public:
	explicit QocLegend(QObject *parent = 0);
	
	QFont font() const;
	void setFont(const QFont &font);
signals:
	
public slots:
	
private:
	QFont m_font;
};

#endif // QOC_LEGEND_H
