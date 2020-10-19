#include "cantileverdialog.h"
#include "ui_cantileverdialog.h"

CantileverDialog::CantileverDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CantileverDialog)
{
    ui->setupUi(this);
}

CantileverDialog::~CantileverDialog()
{
    delete ui;
}

void CantileverDialog::on_buttonBox_accepted()
{
    accept();
}

void CantileverDialog::on_buttonBox_rejected()
{
    reject();
}

QString CantileverDialog::Condition() const
{
    return ui->ConditionBox->text();
}

int CantileverDialog::God() const
{
    return ui->QBox->value();
}

double CantileverDialog::Frequency()const
{
    return ui->FrequencyBox->value();
}

int CantileverDialog::Amplitude() const
{
    return ui->AmplitudeBox->value();
}

int CantileverDialog::Gain1() const
{
    return ui ->GainBox1->value();
}

int CantileverDialog::Gain2() const
{
    return ui ->GainBox2->value();
}

int CantileverDialog::Gain3() const
{
    return ui ->GainBox2->value();
}
