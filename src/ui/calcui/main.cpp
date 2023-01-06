#include "calcwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    /*
    Description:
        Entry point function for running SmartCalc application

    Args:
        (int) args    : Number of arguments provided with invoking executable file
        (char**) argv : Actual arguments provided with invoking executable file

    Returns:
        None (only runs SmartCalc application)
    */

    QApplication a(argc, argv);
    CalcWindow w;
    w.show();

    return a.exec();
}
