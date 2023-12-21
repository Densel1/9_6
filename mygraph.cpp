#include "mygraph.h"
#include "ui_mygraph.h"

myGraph::myGraph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myGraph)
{
    ui->setupUi(this);

    ptrGraph = new QLineSeries(this);
}

myGraph::~myGraph()
{
    delete ui;
}


void myGraph::AddDataToGrahp(QVector<double> x, QVector<double> y)
{

    //Зададим размер графика, т.е. количество точек.
    uint32_t size = 0;
    //Необходимо, чтобы х и у были равны.
    if(x.size() >= y.size()){
        size = y.size();
    }
    else{
        size = x.size();
    }

    //Добавление точе в серию осуществляется при помощи метода append.
    for(int j = 0; j<size; j++){
        ptrGraph->append(x[j],y[j]);
    }
}
/*!
 * \brief Метод очищает данные на графике
 * \param chart - указатель на график
 */
void myGraph::ClearGraph(QChart *chart)
{
    //Необходимо очистить все графики
        //Очищаем серии
        ptrGraph->clear();
        //Удаляем серии из графика
        chart->removeSeries(ptrGraph);
}

/*!
 * \brief Метод добавляет серии к графику
 * \param chart - указатель на график
 */
void myGraph::UpdateGraph(QChart *chart)
{

        chart->addSeries(ptrGraph);

}
