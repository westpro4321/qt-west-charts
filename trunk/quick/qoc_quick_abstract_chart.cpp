#include "qoc_quick_abstract_chart.h"

QocQuickAbstractChart::QocQuickAbstractChart(QObject *parent) :
	QocAbstractChart(parent)
{
}

QColor QocQuickAbstractChart::backgroundColor() const
{
	return m_backgroundBrush.color();
}

void QocQuickAbstractChart::setBackgroundColor(const QColor &c)
{
	if ( c != m_backgroundBrush.color() )
	{
		m_backgroundBrush = QBrush(c);
		emit backgroundColorChanged(c);
	}
}

QColor QocQuickAbstractChart::foregroundColor() const
{
	return m_foregroundBrush.color();
}

void QocQuickAbstractChart::setForegroundColor(const QColor &c)
{
	if ( c != m_foregroundBrush.color() )
	{
		m_foregroundBrush = QBrush(c);
		emit foregroundColorChanged(c);
	}
}

