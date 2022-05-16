#include "widget.h"

#include <QApplication>
#include<QtMath>

double Func(int x){

    //double y = -0.001*(qSin(x-30) + qPow((x-30), 2))-40;
    double y = -30*qSin(0.1*x);
    //double y = x*x+x;
    return -y;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int left_limit = -400;
    int right_limit = -55;
    double (*fcnPtr)(int) = Func;
    Widget w(left_limit, right_limit, fcnPtr);
    w.resize(800, 700);
    w.show();
    return a.exec();
}
