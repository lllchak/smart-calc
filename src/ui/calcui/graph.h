#ifndef GRAPH_H_
#define GRAPH_H_

#include "../../backend/calculation/calculation.h"
#include <QWidget>

namespace Ui { class Graph; }

class Graph : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Graph class constructor. Also connects graph drawing button with backend
     * 
     * @param parent Parent class value
     */
    Graph(QWidget* parent = nullptr);

    /**
     * @brief Graph class destructor. Cleans allocated memory and destroy Graph object
     */
    ~Graph();

    /**
     * @brief 
     * 
     */
    void scalling();
    void setscale();
    eflag plot(char* equation);
    void pgraph();

private slots:
    void cplot();

private:
    Ui::Graph* ui;
    double lx = -1000000;
    double rx =  1000000;
    double step = 0.0;
    char* prev_equation = NULL;
    std::pair<std::vector<double>, std::vector<double>> points;
};

#endif  // GRAPH_H_
