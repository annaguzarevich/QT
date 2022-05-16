#include "info.h"

Info::Info(int left_limit, int right_limit, double (*myFunc)(int), QWidget *parent)
    : left_limit(left_limit), right_limit(right_limit), Func(myFunc), QWidget(parent)
{
   valueX = new QLineEdit(this);
   valueY = new QLineEdit(this);
   valueY->setReadOnly(true);

   QLabel* labelX = new QLabel("x", this);
   QLabel* labelY = new QLabel("y", this);
   std::string str;
   connect(valueX, SIGNAL(textEdited(const QString &)), SLOT(NewText()));
   connect(valueX, SIGNAL(returnPressed()), SLOT(NewValue()));


   QFormLayout *innerLayout = new QFormLayout();
   innerLayout->addRow(labelX, valueX);
   innerLayout->addRow(labelY, valueY);

   setLayout(innerLayout);
}

void Info::NewText(){
    valueY->clear();
}

void Info::NewValue(){
    int x = (valueX->text()).toInt();
    if((x>=left_limit)&&(x<=right_limit)){
        double y = Func(x);
        valueY->setText(QString::number(-y));
    }
    else {
        valueY->setText("The value does not belong to the set.");
    }
}

void Info::setTextOnValueY(QString str){
    valueY->setText(str);
}

