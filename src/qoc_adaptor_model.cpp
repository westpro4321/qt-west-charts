#include "qoc_adaptor_model.h"
#include "qoc_data_series.h"

#include <QAbstractItemModel>
#include <QAbstractListModel>
#include <QtGlobal>

QocAdaptorModel::QocAdaptorModel(QObject *parent) :
	QObject(parent),
	m_model("")
{
}

void QocAdaptorModel::setModel(const QVariant &model)
{
	//if ( m_model.isValid() || ! (m_model == model) )
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

QVariant QocAdaptorModel::data(int seriesIndex, Qoc::ItemDataRole role)
{
	QVariant retVal;
	if ( ! m_model.isNull() )
	{
		if ( QocDataSeries *model = qvariant_cast<QocDataSeries *>(m_model) )
		{
			retVal = model->data(seriesIndex, role);
		}
		else
		{
			qFatal("Unknown model type");
		}
	}
	return retVal;
}

int QocAdaptorModel::size(int index) const
{
	if ( m_modelType == Series )
	{
		const QocDataSeries *series = qvariant_cast<QocDataSeries *>(m_model);
		return series->size();
	}

	return 0;
}

int QocAdaptorModel::seriesCount() const
{
	if ( ! m_model.isNull() )
	{
		if ( QocDataSeries *model = qvariant_cast<QocDataSeries *>(m_model) )
		{
			return 1;
		}
		else
		{
			qFatal("Unknown model type");
			return 0;
		}
	}
	return 0;
}
