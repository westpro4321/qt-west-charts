#include "qoc_quick_abstract_chart.h"

#include <qoc_abstract_chart.h>


QocQuickAbstractChart::QocQuickAbstractChart(QObject *parent) :
	QObject(parent)
{
}

QColor QocQuickAbstractChart::backgroundColor() const
{
	return m_chart->backgroundBrush().color();
}

void QocQuickAbstractChart::setBackgroundColor(const QColor &c)
{
	if ( c !=  m_chart->backgroundBrush().color() )
	{
		m_chart->setBackgroundBrush(QBrush(c));
		emit backgroundColorChanged(c);
	}
}

QColor QocQuickAbstractChart::foregroundColor() const
{
	return m_chart->foregroundBrush().color();
}

void QocQuickAbstractChart::setForegroundColor(const QColor &c)
{
	if ( c !=  m_chart->foregroundBrush().color() )
	{
		m_chart->setForegroundBrush(QBrush(c));
		emit foregroundColorChanged(c);
	}
}

QVariant QocQuickAbstractChart::model() const
{
	return m_chart->model();
}

void QocQuickAbstractChart::setModel(const QVariant &model)
{
	m_chart->setModel(model);
}

QRectF QocQuickAbstractChart::viewGeometry() const
{
	return m_chart->viewGeometry();
}

void QocQuickAbstractChart::setViewGeometry(const QRectF &r)
{
	if ( m_chart->viewGeometry() != r)
	{
		m_chart->setViewGeometry(r);
		emit viewGeometryChanged(r);
	}
}

void QocQuickAbstractChart::draw(QPainter *painter)
{
	m_chart->draw(painter);
}

