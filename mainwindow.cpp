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
    ui->tableWidget->setColumnCount(8);
    Name <<"Condition" <<"Q factor" <<"Frequency [kHz]"<<"Amplitude"<<"Amplification"<<"Swing"<<"Swing(vaccum)"<<"Slew Rate";
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
    double Frequency, Period;
    int Amplitude;
    double Gain;
    double Swing;
    double SwingV;
    double Sr;
    QString Condition;
    CantileverDialog pd;
    pd.setWindowTitle("Cantilever Database");
    res = pd.exec();
    if (res == QDialog::Rejected)
        return;
    God = pd.God();
    Frequency = pd.Frequency();
    Condition =pd.Condition();
    Amplitude = pd.Amplitude();
    Gain = pd.Gain1()*pd.Gain2()*pd.Gain3();
    Swing = pd.Amplitude()/Gain/10;
    SwingV = Swing/2;
    Period = 1/Frequency;
    Sr = Amplitude/Period/4;
    ui -> tableWidget -> insertRow(ui ->tableWidget->rowCount());
    row = ui->tableWidget->rowCount() -1;
    ui -> tableWidget -> setItem(row,CONDITION, new QTableWidgetItem(Condition));
    ui -> tableWidget -> setItem(row,GOD, new QTableWidgetItem(QString::number(God)));
    ui -> tableWidget -> setItem(row,FREQUENCY, new QTableWidgetItem(QString::number(Frequency)));
    ui -> tableWidget -> setItem(row,AMPLITUDE, new QTableWidgetItem(QString::number(Amplitude)));
    ui -> tableWidget -> setItem(row,GAIN, new QTableWidgetItem(QString::number(Gain)));
    ui -> tableWidget -> setItem(row,SWING, new QTableWidgetItem(QString::number(Swing)));
    ui -> tableWidget -> setItem(row,SWINGV, new QTableWidgetItem(QString::number(SwingV)));
    ui -> tableWidget -> setItem(row,SR, new QTableWidgetItem(QString::number(Sr)));
}

void MainWindow::on_pushButtonSave_clicked()
{

}


