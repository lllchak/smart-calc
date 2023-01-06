#ifndef GRAPH_H_
#define GRAPH_H_

#include <QWidget>

extern "C" {
#include "../../backend/calculation/calculation.h"
}

namespace Ui { class Graph; }

class Graph : public QWidget {
    Q_OBJECT

public:
    Graph(QWidget* parent = nullptr);
    ~Graph();

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
