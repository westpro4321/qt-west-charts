#ifndef QOC_DATA_SERIES_H
#define QOC_DATA_SERIES_H

#include <QObject>
#include <QList>
#include <QVariant>
#include <QColor>

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

	void append(QocDataItem *item);
	void insert(int index, QocDataItem *item);
	void removeAt(int index);

	QVariant data(int index, Qoc::ItemDataRole role) const;
	void setData(int index, const QVariant &data, Qoc::ItemDataRole role);

	int size() const;
	//void sort(Qoc::ItemDataRole role, Qt::SortOrder);

signals:
	void dataChanged(int, Qoc::ItemDataRole);
	void dataInserted(int);
	void dataRemoved(int);
//	void sorted(Qt::SortOrder);

	void titleChanged(const QString &);
	void colorChanged(const QColor &);

public slots:
	
private slots:
	void onItemDataChanged(Qoc::ItemDataRole role);

protected:
	QString m_title;
	QColor m_color;
	QList<QocDataItem *> m_items;
};

Q_DECLARE_METATYPE(QocDataSeries *)

#endif // QOC_DATA_SERIES_H
