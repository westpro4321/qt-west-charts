#include "qoc_adaptor_model.h"
#include "qoc_data_series.h"
#include "qoc_data_item.h"

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

void QocAdaptorModel::insert(int index)
{
	if ( ! m_model.isNull() )
	{
		if ( QocDataSeries *model = qvariant_cast<QocDataSeries *>(m_model) )
		{
			model->insert(index, new QocDataItem(model));
		}
		else
		{
			qFatal("Unknown model type");
		}
	}
}

void QocAdaptorModel::removeAt(int index)
{
	if ( ! m_model.isNull() )
	{
		if ( QocDataSeries *model = qvariant_cast<QocDataSeries *>(m_model) )
		{
			model->removeAt(index);
		}
		else
		{
			qFatal("Unknown model type");
		}
	}
}

QVariant QocAdaptorModel::data(int seriesIndex, int itemIndex, Qoc::ItemDataRole role)
{
	QVariant retVal;
	if ( ! m_model.isNull() )
	{
		if ( QocDataSeries *model = qvariant_cast<QocDataSeries *>(m_model) )
		{
			retVal = model->data(itemIndex, role);
		}
		else
		{
			qFatal("Unknown model type");
		}
	}
	return retVal;
}

void QocAdaptorModel::setData(int seriesIndex, int itemIndex, const QVariant &value, Qoc::ItemDataRole role)
{
	if ( ! m_model.isNull() )
	{
		if ( QocDataSeries *model = qvariant_cast<QocDataSeries *>(m_model) )
		{
			model->setData(itemIndex, value, role);
		}
		else
		{
			qFatal("Unknown model type");
		}
	}
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
