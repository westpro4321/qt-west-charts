#ifndef QOC_DATA_SERIES_H
#define QOC_DATA_SERIES_H

#include <QObject>
#include <QList>

#include "qoc_global.h"

class QocDataItem;


class QOC_API QocDataSeries : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
	Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)


public:
	explicit QocDataSeries(QObject *parent = 0);
	
	QString title() const;
	void setTitle(const QString &);

	QColor color() const;
	void setColor(const QColor &);

signals:
	void dataChanged();
	void dataInserted();
	void dataRemoved();
	void sorted();

	void titleChanged(const QString &);
	void colorChanged(const QColor &);

public slots:
	
private:
	QString m_title;
	QColor m_color;
	QList<QocDataItem *> m_items;
};

#endif // QOC_DATA_SERIES_H
