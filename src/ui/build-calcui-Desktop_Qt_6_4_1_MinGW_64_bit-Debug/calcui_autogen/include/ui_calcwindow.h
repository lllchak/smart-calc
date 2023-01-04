/********************************************************************************
** Form generated from reading UI file 'calcwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCWINDOW_H
#define UI_CALCWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalcWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *ButtonMemoryAdd;
    QTabWidget *tabWidget;
    QWidget *arithm;
    QGridLayout *gridLayout_2;
    QPushButton *Button3;
    QPushButton *Button9;
    QPushButton *Button8;
    QPushButton *ButtonDot;
    QPushButton *ButtonOpenBracket;
    QPushButton *Button1;
    QPushButton *Button4;
    QPushButton *ButtonCloseBracket;
    QPushButton *ButtonDiv;
    QPushButton *ButtonX;
    QPushButton *Button6;
    QPushButton *ButtonEqual;
    QPushButton *ButtonMinus;
    QPushButton *ButtonMult;
    QPushButton *Button2;
    QPushButton *Button5;
    QPushButton *Button0;
    QPushButton *ButtonPow;
    QPushButton *ButtonPlus;
    QPushButton *Button7;
    QWidget *funcs;
    QGridLayout *gridLayout_3;
    QPushButton *ButtonAcos;
    QPushButton *ButtonSin;
    QPushButton *ButtonCos;
    QPushButton *ButtonAtan;
    QPushButton *ButtonAsin;
    QPushButton *ButtonTan;
    QPushButton *ButtonLog;
    QPushButton *ButtonLn;
    QPushButton *ButtonSqrt;
    QPushButton *ButtonMod;
    QPushButton *ButtonBackspace;
    QPushButton *ButtonClearAll;
    QLineEdit *InputDisplay;
    QPushButton *ButtonGraph;
    QPushButton *ButtonBack;
    QPushButton *ButtonMemoryRemove;
    QPushButton *ButtonMemoryGet;
    QPushButton *ButtonForward;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CalcWindow)
    {
        if (CalcWindow->objectName().isEmpty())
            CalcWindow->setObjectName("CalcWindow");
        CalcWindow->resize(350, 450);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CalcWindow->sizePolicy().hasHeightForWidth());
        CalcWindow->setSizePolicy(sizePolicy);
        CalcWindow->setMinimumSize(QSize(350, 450));
        CalcWindow->setMaximumSize(QSize(350, 450));
        CalcWindow->setAutoFillBackground(false);
        CalcWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"	background-color: white;\n"
"}"));
        centralwidget = new QWidget(CalcWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        ButtonMemoryAdd = new QPushButton(centralwidget);
        ButtonMemoryAdd->setObjectName("ButtonMemoryAdd");
        ButtonMemoryAdd->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout->addWidget(ButtonMemoryAdd, 2, 1, 1, 1);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(0, 0));
        tabWidget->setMaximumSize(QSize(16777215, 200));
        tabWidget->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));
        arithm = new QWidget();
        arithm->setObjectName("arithm");
        gridLayout_2 = new QGridLayout(arithm);
        gridLayout_2->setObjectName("gridLayout_2");
        Button3 = new QPushButton(arithm);
        Button3->setObjectName("Button3");
        Button3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout_2->addWidget(Button3, 2, 3, 1, 1);

        Button9 = new QPushButton(arithm);
        Button9->setObjectName("Button9");
        Button9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout_2->addWidget(Button9, 0, 3, 1, 1);

        Button8 = new QPushButton(arithm);
        Button8->setObjectName("Button8");
        Button8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout_2->addWidget(Button8, 0, 2, 1, 1);

        ButtonDot = new QPushButton(arithm);
        ButtonDot->setObjectName("ButtonDot");
        ButtonDot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout_2->addWidget(ButtonDot, 3, 2, 1, 1);

        ButtonOpenBracket = new QPushButton(arithm);
        ButtonOpenBracket->setObjectName("ButtonOpenBracket");
        ButtonOpenBracket->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout_2->addWidget(ButtonOpenBracket, 2, 0, 1, 1);

        Button1 = new QPushButton(arithm);
        Button1->setObjectName("Button1");
        Button1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout_2->addWidget(Button1, 2, 1, 1, 1);

        Button4 = new QPushButton(arithm);
        Button4->setObjectName("Button4");
        Button4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout_2->addWidget(Button4, 1, 1, 1, 1);

        ButtonCloseBracket = new QPushButton(arithm);
        ButtonCloseBracket->setObjectName("ButtonCloseBracket");
        ButtonCloseBracket->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout_2->addWidget(ButtonCloseBracket, 3, 0, 1, 1);

        ButtonDiv = new QPushButton(arithm);
        ButtonDiv->setObjectName("ButtonDiv");
        ButtonDiv->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout_2->addWidget(ButtonDiv, 0, 4, 1, 1);

        ButtonX = new QPushButton(arithm);
        ButtonX->setObjectName("ButtonX");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ButtonX->sizePolicy().hasHeightForWidth());
        ButtonX->setSizePolicy(sizePolicy2);
        ButtonX->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout_2->addWidget(ButtonX, 0, 0, 1, 1);

        Button6 = new QPushButton(arithm);
        Button6->setObjectName("Button6");
        Button6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout_2->addWidget(Button6, 1, 3, 1, 1);

        ButtonEqual = new QPushButton(arithm);
        ButtonEqual->setObjectName("ButtonEqual");
        ButtonEqual->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout_2->addWidget(ButtonEqual, 3, 3, 1, 1);

        ButtonMinus = new QPushButton(arithm);
        ButtonMinus->setObjectName("ButtonMinus");
        ButtonMinus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout_2->addWidget(ButtonMinus, 2, 4, 1, 1);

        ButtonMult = new QPushButton(arithm);
        ButtonMult->setObjectName("ButtonMult");
        ButtonMult->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout_2->addWidget(ButtonMult, 1, 4, 1, 1);

        Button2 = new QPushButton(arithm);
        Button2->setObjectName("Button2");
        Button2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout_2->addWidget(Button2, 2, 2, 1, 1);

        Button5 = new QPushButton(arithm);
        Button5->setObjectName("Button5");
        Button5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout_2->addWidget(Button5, 1, 2, 1, 1);

        Button0 = new QPushButton(arithm);
        Button0->setObjectName("Button0");
        Button0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout_2->addWidget(Button0, 3, 1, 1, 1);

        ButtonPow = new QPushButton(arithm);
        ButtonPow->setObjectName("ButtonPow");
        ButtonPow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout_2->addWidget(ButtonPow, 1, 0, 1, 1);

        ButtonPlus = new QPushButton(arithm);
        ButtonPlus->setObjectName("ButtonPlus");
        ButtonPlus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout_2->addWidget(ButtonPlus, 3, 4, 1, 1);

        Button7 = new QPushButton(arithm);
        Button7->setObjectName("Button7");
        Button7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout_2->addWidget(Button7, 0, 1, 1, 1);

        tabWidget->addTab(arithm, QString());
        funcs = new QWidget();
        funcs->setObjectName("funcs");
        gridLayout_3 = new QGridLayout(funcs);
        gridLayout_3->setObjectName("gridLayout_3");
        ButtonAcos = new QPushButton(funcs);
        ButtonAcos->setObjectName("ButtonAcos");
        ButtonAcos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: white;\n"
"	color: black;\n"
"}"));

        gridLayout_3->addWidget(ButtonAcos, 1, 0, 1, 1);

        ButtonSin = new QPushButton(funcs);
        ButtonSin->setObjectName("ButtonSin");
        ButtonSin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: white;\n"
"	color: black;\n"
"}"));

        gridLayout_3->addWidget(ButtonSin, 0, 0, 1, 1);

        ButtonCos = new QPushButton(funcs);
        ButtonCos->setObjectName("ButtonCos");
        ButtonCos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: white;\n"
"	color: black;\n"
"}"));

        gridLayout_3->addWidget(ButtonCos, 0, 1, 1, 1);

        ButtonAtan = new QPushButton(funcs);
        ButtonAtan->setObjectName("ButtonAtan");
        ButtonAtan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: white;\n"
"	color: black;\n"
"}"));

        gridLayout_3->addWidget(ButtonAtan, 1, 1, 1, 1);

        ButtonAsin = new QPushButton(funcs);
        ButtonAsin->setObjectName("ButtonAsin");
        ButtonAsin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: white;\n"
"	color: black;\n"
"}"));

        gridLayout_3->addWidget(ButtonAsin, 0, 3, 1, 1);

        ButtonTan = new QPushButton(funcs);
        ButtonTan->setObjectName("ButtonTan");
        ButtonTan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: white;\n"
"	color: black;\n"
"}"));

        gridLayout_3->addWidget(ButtonTan, 0, 2, 1, 1);

        ButtonLog = new QPushButton(funcs);
        ButtonLog->setObjectName("ButtonLog");
        ButtonLog->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: white;\n"
"	color: black;\n"
"}"));

        gridLayout_3->addWidget(ButtonLog, 1, 2, 1, 1);

        ButtonLn = new QPushButton(funcs);
        ButtonLn->setObjectName("ButtonLn");
        ButtonLn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: white;\n"
"	color: black;\n"
"}"));

        gridLayout_3->addWidget(ButtonLn, 1, 3, 1, 1);

        ButtonSqrt = new QPushButton(funcs);
        ButtonSqrt->setObjectName("ButtonSqrt");

        gridLayout_3->addWidget(ButtonSqrt, 2, 2, 1, 1);

        ButtonMod = new QPushButton(funcs);
        ButtonMod->setObjectName("ButtonMod");

        gridLayout_3->addWidget(ButtonMod, 2, 1, 1, 1);

        tabWidget->addTab(funcs, QString());

        gridLayout->addWidget(tabWidget, 3, 0, 1, 4);

        ButtonBackspace = new QPushButton(centralwidget);
        ButtonBackspace->setObjectName("ButtonBackspace");
        ButtonBackspace->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout->addWidget(ButtonBackspace, 1, 3, 1, 1);

        ButtonClearAll = new QPushButton(centralwidget);
        ButtonClearAll->setObjectName("ButtonClearAll");
        ButtonClearAll->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout->addWidget(ButtonClearAll, 2, 3, 1, 1);

        InputDisplay = new QLineEdit(centralwidget);
        InputDisplay->setObjectName("InputDisplay");
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(InputDisplay->sizePolicy().hasHeightForWidth());
        InputDisplay->setSizePolicy(sizePolicy3);
        InputDisplay->setMinimumSize(QSize(0, 60));
        InputDisplay->setMaximumSize(QSize(16777215, 100));
        InputDisplay->setBaseSize(QSize(0, 0));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(11);
        InputDisplay->setFont(font);
        InputDisplay->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: #615F5F;\n"
"	margin-bottom: 30px;\n"
"}"));
        InputDisplay->setFrame(true);
        InputDisplay->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(InputDisplay, 0, 0, 1, 4);

        ButtonGraph = new QPushButton(centralwidget);
        ButtonGraph->setObjectName("ButtonGraph");
        ButtonGraph->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout->addWidget(ButtonGraph, 1, 0, 1, 1);

        ButtonBack = new QPushButton(centralwidget);
        ButtonBack->setObjectName("ButtonBack");
        ButtonBack->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout->addWidget(ButtonBack, 1, 1, 1, 1);

        ButtonMemoryRemove = new QPushButton(centralwidget);
        ButtonMemoryRemove->setObjectName("ButtonMemoryRemove");
        ButtonMemoryRemove->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout->addWidget(ButtonMemoryRemove, 2, 0, 1, 1);

        ButtonMemoryGet = new QPushButton(centralwidget);
        ButtonMemoryGet->setObjectName("ButtonMemoryGet");
        ButtonMemoryGet->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout->addWidget(ButtonMemoryGet, 2, 2, 1, 1);

        ButtonForward = new QPushButton(centralwidget);
        ButtonForward->setObjectName("ButtonForward");
        ButtonForward->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #fff;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	background-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #D5D2D2;\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	color: white;\n"
"}"));

        gridLayout->addWidget(ButtonForward, 1, 2, 1, 1);

        CalcWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CalcWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 350, 21));
        CalcWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CalcWindow);
        statusbar->setObjectName("statusbar");
        CalcWindow->setStatusBar(statusbar);

        retranslateUi(CalcWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CalcWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CalcWindow)
    {
        CalcWindow->setWindowTitle(QCoreApplication::translate("CalcWindow", "CalcWindow", nullptr));
        ButtonMemoryAdd->setText(QCoreApplication::translate("CalcWindow", "M+", nullptr));
        Button3->setText(QCoreApplication::translate("CalcWindow", "3", nullptr));
        Button9->setText(QCoreApplication::translate("CalcWindow", "9", nullptr));
        Button8->setText(QCoreApplication::translate("CalcWindow", "8", nullptr));
        ButtonDot->setText(QCoreApplication::translate("CalcWindow", ".", nullptr));
        ButtonOpenBracket->setText(QCoreApplication::translate("CalcWindow", "(", nullptr));
        Button1->setText(QCoreApplication::translate("CalcWindow", "1", nullptr));
        Button4->setText(QCoreApplication::translate("CalcWindow", "4", nullptr));
        ButtonCloseBracket->setText(QCoreApplication::translate("CalcWindow", ")", nullptr));
        ButtonDiv->setText(QCoreApplication::translate("CalcWindow", "/", nullptr));
        ButtonX->setText(QCoreApplication::translate("CalcWindow", "x", nullptr));
        Button6->setText(QCoreApplication::translate("CalcWindow", "6", nullptr));
        ButtonEqual->setText(QCoreApplication::translate("CalcWindow", "=", nullptr));
        ButtonMinus->setText(QCoreApplication::translate("CalcWindow", "-", nullptr));
        ButtonMult->setText(QCoreApplication::translate("CalcWindow", "\303\227", nullptr));
        Button2->setText(QCoreApplication::translate("CalcWindow", "2", nullptr));
        Button5->setText(QCoreApplication::translate("CalcWindow", "5", nullptr));
        Button0->setText(QCoreApplication::translate("CalcWindow", "0", nullptr));
        ButtonPow->setText(QCoreApplication::translate("CalcWindow", "^", nullptr));
        ButtonPlus->setText(QCoreApplication::translate("CalcWindow", "+", nullptr));
        Button7->setText(QCoreApplication::translate("CalcWindow", "7", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(arithm), QCoreApplication::translate("CalcWindow", "+ -", nullptr));
        ButtonAcos->setText(QCoreApplication::translate("CalcWindow", "acos", nullptr));
        ButtonSin->setText(QCoreApplication::translate("CalcWindow", "sin", nullptr));
        ButtonCos->setText(QCoreApplication::translate("CalcWindow", "cos", nullptr));
        ButtonAtan->setText(QCoreApplication::translate("CalcWindow", "atan", nullptr));
        ButtonAsin->setText(QCoreApplication::translate("CalcWindow", "asin", nullptr));
        ButtonTan->setText(QCoreApplication::translate("CalcWindow", "tan", nullptr));
        ButtonLog->setText(QCoreApplication::translate("CalcWindow", "log", nullptr));
        ButtonLn->setText(QCoreApplication::translate("CalcWindow", "ln", nullptr));
        ButtonSqrt->setText(QCoreApplication::translate("CalcWindow", "sqrt", nullptr));
        ButtonMod->setText(QCoreApplication::translate("CalcWindow", "mod", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(funcs), QCoreApplication::translate("CalcWindow", "sin cos", nullptr));
        ButtonBackspace->setText(QCoreApplication::translate("CalcWindow", "Backspace", nullptr));
        ButtonClearAll->setText(QCoreApplication::translate("CalcWindow", "AC", nullptr));
        InputDisplay->setText(QString());
        InputDisplay->setPlaceholderText(QCoreApplication::translate("CalcWindow", "Type a math problem", nullptr));
        ButtonGraph->setText(QCoreApplication::translate("CalcWindow", "Graph", nullptr));
        ButtonBack->setText(QCoreApplication::translate("CalcWindow", "<-", nullptr));
        ButtonMemoryRemove->setText(QCoreApplication::translate("CalcWindow", "M-", nullptr));
        ButtonMemoryGet->setText(QCoreApplication::translate("CalcWindow", "M", nullptr));
        ButtonForward->setText(QCoreApplication::translate("CalcWindow", "->", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalcWindow: public Ui_CalcWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCWINDOW_H
