#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qoc_pie_chart.h"

#include <QDebug>
#include <QPropertyAnimation>


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

//	connect(ui->sectorStart, SIGNAL(clicked()), this, SLOT(sectorStartClicked()));
//	connect(ui->chartStart, SIGNAL(clicked()), this, SLOT(chartStartClicked()));

}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::sectorStartClicked()
{
//	QPropertyAnimation *pa = new QPropertyAnimation(ui->testWidget->pieChart.item(ui->sectorNumber->value()),
//													"offset");
//	pa->setDuration(ui->sectorDuration->value());
//	pa->setStartValue(static_cast<uint>(ui->testWidget->pieChart.item(ui->sectorNumber->value())->offset()));
//	pa->setEndValue(static_cast<uint>(ui->offset->value()));
//	pa->start(/*QAbstractAnimation::DeleteWhenStopped*/);

//	qDebug() << Q_FUNC_INFO << pa->targetObject() << pa->propertyName();
}

void MainWindow::chartStartClicked()
{
//	QPropertyAnimation *pa = new QPropertyAnimation(&(ui->testWidget->pieChart), "startAngle");
//	pa->setDuration(ui->chartDuration->value());
//	//pa->setStartValue(static_cast<uint>(ui->testWidget->pieChart.item(ui->sectorNumber->value())->offset()));
//	pa->setEndValue(static_cast<uint>(ui->startAngle->value()*16));
//	pa->start(/*QAbstractAnimation::DeleteWhenStopped*/);

//	qDebug() << Q_FUNC_INFO << pa->targetObject() << pa->propertyName();
}
