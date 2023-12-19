#ifndef MYGRAPH_H
#define MYGRAPH_H

#include <QDialog>
#include <QObject>
#include <QLineSeries>
#include <QtCharts>
#include <QChartView>

namespace Ui {
class myGraph;
}

class myGraph : public QDialog
{
    Q_OBJECT

public:
    explicit myGraph(QWidget *parent = nullptr);
    ~myGraph();

    void AddDataToGrahp(QVector<double> x, QVector<double> y);
    void ClearGraph(QChart* chart);
    void UpdateGraph(QChart* chart);


signals:

private:

    QLineSeries* ptrGraph;

    Ui::myGraph *ui;
};

#endif // MYGRAPH_H
