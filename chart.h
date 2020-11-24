#ifndef CHART_H
#define CHART_H

#include <QMainWindow>

namespace Ui {
class Chart;
}

class Chart : public QMainWindow
{
    Q_OBJECT

public:
    explicit Chart(QWidget *parent = nullptr);
    ~Chart();

private:
    Ui::Chart *ui;
};

#endif // CHART_H
