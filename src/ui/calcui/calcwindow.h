#ifndef CALCWINDOW_H
#define CALCWINDOW_H

#include <QMainWindow>

extern "C" {
#include "../../backend/calculation/calculation.h"
}


QT_BEGIN_NAMESPACE
namespace Ui { class CalcWindow; }
QT_END_NAMESPACE

class CalcWindow : public QMainWindow
{
    Q_OBJECT

public:
    CalcWindow(QWidget *parent = nullptr);
    ~CalcWindow();

private slots:
    void psignal();
    void mmemory();
    void mbackspace();
    void scursor();
    void mequation();
    void cclear();
    void cequal();
//    void cgraph();

private:
    Ui::CalcWindow *ui;
    eflag flag = SUCCESS;
    bool contains_x = false;
    bool mbuf = false;
    QString buf = "";
};
#endif // CALCWINDOW_H
