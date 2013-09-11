#include "qoc_adaptor_model.h"
#include "qoc_data_series.h"

#include <QAbstractItemModel>
#include <QAbstractListModel>
#include <QtGlobal>

QocAdaptorModel::QocAdaptorModel(QObject *parent) :
	QObject(parent)
{
}

void QocAdaptorModel::setModel(const QVariant &model)
{
	if ( m_model != model )
	{
		m_model = model;
		if ( qvariant_cast<QocDataSeries *>(model) )
		{
			m_modelType = Series;
		}
//		else if ( qvariant_cast<const QList<QocDataSeries *> &>(model) )
//		{
//			m_modelType = SeriesList;
//		}
//		else if ( qvariant_cast<const QAbstractListModel *>(model) )
//		{
//			m_modelType = AbstractListModel;
//		}
//		else if ( qvariant_cast<const QAbstractItemModel *>(model) )
//		{
//			m_modelType = AbstractItemModel;
//		}
		else
		{
			qFatal("Unknown model type");
		}

		emit modelChanged();
	}
}

QVariant QocAdaptorModel::model() const
{
	return m_model;
}

int QocAdaptorModel::size(int index)
{
	if ( m_modelType == Series )
	{
		const QocDataSeries *series = qvariant_cast<QocDataSeries *>(m_model);
		return series->size();
	}

	return 0;
}
