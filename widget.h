#ifndef WIDGET_H
#define WIDGET_H

#include <QVBoxLayout>
#include "drawing.h"
#include "info.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(int left_limit, int right_limit, double (*myFunc)(int), QWidget *parent = nullptr);
    ~Widget();

protected slots:

private:
    Drawing * drawing;
    Info* info;


};
#endif // WIDGET_H
