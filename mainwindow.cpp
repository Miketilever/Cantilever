#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cantileverdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList Name;
    setWindowTitle("Cantilver calculator & data base");
    ui->tableWidget->setColumnCount(3);
    Name <<"Condition" <<"Q factor" <<"Frequency [kHz]";
    ui->tableWidget->setHorizontalHeaderLabels(Name);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonNormal_clicked()
{
    showNormal();
}

void MainWindow::on_pushButtonFull_clicked()
{
    showFullScreen();
}

void MainWindow::on_pushButtonMax_clicked()
{
    showMaximized();
}

void MainWindow::on_pushButtonExit_clicked()
{
    close();
}

void MainWindow::on_pushButtonAdd_clicked()
{
    int res,row;
    int God;
    double Frequency;
    QString Condition;
    CantileverDialog pd;
    pd.setWindowTitle("Cantilever Database");
    res = pd.exec();
    if (res == QDialog::Rejected)
        return;
    God = pd.God();
    Frequency = pd.Frequency();
    Condition =pd.Condition();
    ui -> tableWidget -> insertRow(ui ->tableWidget->rowCount());
    row = ui->tableWidget->rowCount() -1;
    ui -> tableWidget -> setItem(row,CONDITION, new QTableWidgetItem(Condition));
    ui -> tableWidget -> setItem(row,GOD, new QTableWidgetItem(QString::number(God)));
    ui -> tableWidget -> setItem(row, FREQUENCY,new QTableWidgetItem(QString::number(Frequency)));



}

void MainWindow::on_pushButtonSave_clicked()
{

}


