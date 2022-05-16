#ifndef INFO_H
#define INFO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include <QString>
//#include <QTextEdit>

class Info : public QWidget
{
    Q_OBJECT

public:
    explicit Info(int left_limit, int right_limit, double (*myFunc)(int), QWidget *parent = nullptr);

signals:

protected slots:
    void NewText();
    void NewValue();

private:
   int left_limit;
   int right_limit;
   double (*Func)(int);
   QLineEdit* valueX;
   QLineEdit* valueY;
};

#endif // INFO_H
