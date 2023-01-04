#include "calcwindow.h"
#include "./ui_calcwindow.h"

CalcWindow::CalcWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CalcWindow)
{
    ui->setupUi(this);

    // Util buttons
    connect(ui->ButtonGraph, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->ButtonBack, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->ButtonForward, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->ButtonBackspace, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->ButtonMemoryRemove, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->ButtonMemoryAdd, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->ButtonMemoryGet, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->ButtonClearAll, SIGNAL(clicked()), this, SLOT(psignal()));

    // Number buttons
    connect(ui->Button0, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->Button1, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->Button2, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->Button3, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->Button4, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->Button5, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->Button6, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->Button7, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->Button8, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->Button9, SIGNAL(clicked()), this, SLOT(psignal()));

    // X button
    connect(ui->ButtonX, SIGNAL(clicked()), this, SLOT(psignal()));

    // Brackets buttons
    connect(ui->ButtonOpenBracket, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->ButtonCloseBracket, SIGNAL(clicked()), this, SLOT(psignal()));

    // Operators buttons
    connect(ui->ButtonMinus, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->ButtonPlus, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->ButtonDiv, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->ButtonMult, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->ButtonPow, SIGNAL(clicked()), this, SLOT(psignal()));

    // Dot button
    connect(ui->ButtonDot, SIGNAL(clicked()), this, SLOT(psignal()));

    // Funcs buttons
    connect(ui->ButtonSin, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->ButtonCos, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->ButtonTan, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->ButtonAsin, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->ButtonAcos, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->ButtonAtan, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->ButtonLog, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->ButtonLn, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->ButtonMod, SIGNAL(clicked()), this, SLOT(psignal()));
    connect(ui->ButtonSqrt, SIGNAL(clicked()), this, SLOT(psignal()));

    // Equal button
    connect(ui->ButtonEqual, SIGNAL(clicked()), this, SLOT(psignal()));
}

CalcWindow::~CalcWindow()
{
    delete ui;
}

void CalcWindow::psignal() {
    QPushButton* button = (QPushButton*)sender();

    if (button->text() == "=") {
        cequal();
        return;
    }

    if (flag) {
        flag = false;
        if (ui->label->text() == "ERROR" || ui->label->text() == "nan") {
            cclear();
            mequation();
        }
    } else {
        mequation();
    }
}

void CalcWindow::mequation() {
    QPushButton* button = (QPushButton*)sender();
    QString input = button->text();

    if (!ui->label->text) {
        if (input == ".") ui->label->setText("0" + input);
        else ui->label->setText(input);
    } else ui->label->setText(ui->label->text() + input);
}

void CalcWindow::cclear() {
    ui->label->setText("");
}

void CalcWindow::cequal() {
    double ans = 0.0;
    QString input_experssion = ui->label->text();
    QByteArray sequence = input_experssion.toLocal8Bit();
    string infix = sequence.data();

    eflag flag = calculate(infix, 0, &ans);

    if (flag) ui->label->setText("ERROR");
    else {
        QString ansstr = QString::number(ans, 'g', 8);
        ui->label->setText(ansstr);
    }

    flag = true;
}

