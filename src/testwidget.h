#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>

class TestWidget : public QWidget
{
	Q_OBJECT
public:
	explicit TestWidget(QWidget *parent = 0);
	
signals:
	
public slots:
	
protected:
	virtual void paintEvent(QPaintEvent * event);
};

#endif // TESTWIDGET_H
