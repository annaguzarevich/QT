#ifndef DRAWING_H
#define DRAWING_H

#include <QWidget>
#include <QColor>
#include <QLabel>
#include <QPainter>
#include <QFont>
#include <QMouseEvent>

class Drawing : public QWidget
{
    Q_OBJECT

public:
    explicit Drawing(int left_limit, int right_limit, double (*myFunc)(int), QWidget *parent = nullptr)
        : left_limit(left_limit), right_limit(right_limit), Func(myFunc), QWidget{parent}{};

    //void setColor(const QColor& color_) { color = color_; }
    //QColor getColor() {return color;}


protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);

protected slots:


private:
    int left_limit;       // Границы отрезка, на котором зададим функцию
    int right_limit;
    double (*Func)(int);  //Указатель на ф-ю, график которой будем изображать
    QVector<QLabel> vector_of_scale_marks; // Массив меток для шкалы осей
};

#endif // DRAWING_H
