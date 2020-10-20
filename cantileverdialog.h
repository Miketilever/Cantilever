#ifndef CANTILEVERDIALOG_H
#define CANTILEVERDIALOG_H

#include <QDialog>

namespace Ui {
class CantileverDialog;
}

class CantileverDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CantileverDialog(QWidget *parent = nullptr);
    ~CantileverDialog();

    QString Condition() const;
    int God() const;
    int Amplitude() const;
    int Gain1 () const;
    int Gain2 () const;
    int Gain3 () const;
    double Frequency()const;
    double Gain () const;
    double Swing () const;
    double SwingV () const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::CantileverDialog *ui;
};

#endif // CANTILEVERDIALOG_H
