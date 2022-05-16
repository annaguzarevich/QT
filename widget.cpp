#include "widget.h"

Widget::Widget(int left_limit, int right_limit, double (*myFunc)(int), QWidget *parent)
    : QWidget(parent)
{
  drawing = new Drawing(left_limit, right_limit, myFunc, this);
  info = new Info(left_limit, right_limit, myFunc, this);


  QVBoxLayout *mainLayout = new QVBoxLayout();
  //mainLayout->setSpacing(15);
  mainLayout->addWidget(drawing, 1);
  mainLayout->addWidget(info);

  setLayout(mainLayout);
}


Widget::~Widget()
{
}






