#ifndef TESTADAPTORMODEL_H
#define TESTADAPTORMODEL_H

#include <QObject>
#include <QtTest/QtTest>

class TestAdaptorModel : public QObject
{
	Q_OBJECT
public:
	explicit TestAdaptorModel(QObject *parent = 0);
	
signals:
	
private slots:
	void insert();
	void insert_data();

	void modify();
	void modify_data();

	void remove();
	void remove_data();

private:
	void insertModels();
	
};

#endif // TESTADAPTORMODEL_H
