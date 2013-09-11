#ifndef QOC_ADAPTOR_MODEL_H
#define QOC_ADAPTOR_MODEL_H

#include <QObject>
#include <QVariant>

#include "qoc_global.h"


class QOC_API QocAdaptorModel : public QObject
{
	Q_OBJECT
public:
	explicit QocAdaptorModel(QObject *parent = 0);

	void setModel(const QVariant &model);
	QVariant model() const;

	int size(int index = 0);

signals:
	void modelChanged();

public slots:
	
private:
	enum ModelType {
		Series,
		SeriesList,
		AbstractListModel,
		AbstractItemModel
	};

private:
	ModelType m_modelType;
	QVariant m_model;
};

#endif // QOC_ADAPTOR_MODEL_H