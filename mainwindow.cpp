#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cantileverdialog.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList Name;
    setWindowTitle("Cantilver calculator & data base");
    ui->tableWidget->setColumnCount(8);
    Name <<"Condition" <<"Q factor" <<"Frequency [Hz]"<<"Amplitude[V]"<<"Amplification"<<"Swing"<<"Swing(vaccum)"<<"Slew Rate";
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
void MainWindow::on_pushButtonDraw_clicked()
{
    QFile file(QFileDialog::getOpenFileName(this,tr("Open File"),"", tr("Text Files (*.txt)")));
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream stream(&file);
    QString text =stream.readAll();
    QMessageBox box;
    box.setText(text);
    box.exec();
    file.close();
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
    QString Sr;
    QString AmplitudeString;
    QString PeriodString;
    QString Condition;
    QString SwingStringV;
    QString SwingString;
    QString GainString;
    QString GodString;
    QString FrequencyString;

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
    SwingV = Swing*100;
    Period = 1/Frequency;
    SwingStringV = QString::number(SwingV);
    SwingString = QString::number(Swing);
    GainString = QString::number(Gain);
    GodString = QString::number(God);
    FrequencyString = QString::number(Frequency);
    PeriodString = QString::number(Period);
    AmplitudeString = QString::number(Amplitude);
    Sr = AmplitudeString +" / "+ PeriodString;


    ui -> tableWidget -> insertRow(ui ->tableWidget->rowCount());
    row = ui->tableWidget->rowCount() -1;
    ui -> tableWidget -> setItem(row,CONDITION, new QTableWidgetItem(Condition));
    ui -> tableWidget -> setItem(row,GOD, new QTableWidgetItem(GodString));
    ui -> tableWidget -> setItem(row,FREQUENCY, new QTableWidgetItem(FrequencyString));
    ui -> tableWidget -> setItem(row,AMPLITUDE, new QTableWidgetItem(AmplitudeString));
    ui -> tableWidget -> setItem(row,GAIN, new QTableWidgetItem(GainString));
    ui -> tableWidget -> setItem(row,SWING, new QTableWidgetItem(SwingString));
    ui -> tableWidget -> setItem(row,SWINGV, new QTableWidgetItem(SwingStringV));
    ui -> tableWidget -> setItem(row,SR, new QTableWidgetItem(Sr));


    QString path = QFileDialog::getSaveFileName(this,QString(),"",QString("(*.txt);;All Files (*)"));
    if(path.isEmpty())
        return;
    else{
        QFile file(path);
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::information(this,"Error",file.errorString());
            return;
        }
        else{
            QTextStream out(&file);
            out <<"Condition: "+ Condition<<endl;
            out <<"Q Factor: "+ GodString<<endl;
            out <<"Frequency: "+ FrequencyString<<endl;
            out <<"Amplitude: "+ AmplitudeString<<endl;
            out <<"Gain: " + GainString<<endl;
            out <<"Swing: "+SwingString<<endl;
            out <<"Swing in vacuum: "+SwingStringV<<endl;
            out <<"Slew rate: "+Sr;
        }
    }

    ui->plot->addGraph();
    ui->plot->graph(0)->setPen(QPen(Qt::blue));
    QVector<double> x(4*Frequency), y(2*Frequency);
    for (int i=0; i<Frequency*2; ++i)
    {
      x[i] = i-Frequency/4;
      y[i] = Swing/(1+qPow(x[i]-Frequency, 2));
    }
    ui->plot->xAxis2->setVisible(true);
    ui->plot->xAxis2->setTickLabels(false);
    ui->plot->yAxis2->setVisible(true);
    ui->plot->yAxis2->setTickLabels(false);
    ui->plot->yAxis->setLabel("Swing");
    ui->plot->xAxis->setLabel("Frequency");
    ui->plot->graph(0)->setData(x, y);
    ui->plot->graph(0)->rescaleAxes();
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

}
void MainWindow::Cantilever()
{

}


