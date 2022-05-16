#include "drawing.h"


void Drawing::paintEvent(QPaintEvent *)
{
    QVector<double> vector_of_y;

   //QVector<QPointF> vector_of_points;

//   for (int i = left_limit; i <= right_limit; i++) {
//        QPointF coord;
//        coord.rx() = i;
//        coord.ry() = Func(i);
//        vector_of_points.push_back(coord);
//   }

   for (int i = left_limit; i <= right_limit; i++) {
       double y = Func(i);
       vector_of_y.push_back(y);
   }

  double maxY = *(std::max_element(vector_of_y.begin(), vector_of_y.end()));
  double minY = *(std::min_element(vector_of_y.begin(), vector_of_y.end()));

  int middleX = (left_limit + right_limit)/2;
  int middleY = (minY + maxY)/2;


  int w = width();
  int h = height();
  int margin = 10;

  int originX = w/2- middleX;
  int originY = h/2- middleY;


  QPainter painter(this);
  QPen pen_for_axes(QColorConstants::Black, 2);
  QPen pen_for_graph(QColorConstants::Red, 3);
  painter.setPen(pen_for_axes);

  QPoint originOfCoordinates(originX, originY);
  painter.translate(originOfCoordinates);

  int left_end_of_OX = middleX-w/2+margin;
  int right_end_of_OX = middleX+w/2-margin;
  int upper_end_of_OY = middleY-h/2+margin;
  int lower_end_of_OY = middleY+ h/2-margin;

  painter.drawLine(QPointF(left_end_of_OX, 0), QPointF(right_end_of_OX, 0));     //Координатные оси
  painter.drawLine(QPointF(0, upper_end_of_OY), QPointF(0, lower_end_of_OY));

  painter.setFont (QFont ( "Thimes", 8, QFont:: Normal) );  // Рисуем на осях шкалу со значениями
  painter.drawText(-25, 25, "0");

  for(int i = 50; i<right_end_of_OX; i+=50){
     painter.drawLine(QPoint(i, 5), QPoint(i, -5));
     painter.drawText(i-10, 20, QString::number(i));
  }

  for (int i = 0; i>left_end_of_OX; i-=50){
      painter.drawLine(QPoint(i, 5), QPoint(i, -5));
      if(i!=0){
      painter.drawText(i-10, 20, QString::number(i));
      }
  }

  for(int i = 0; i>upper_end_of_OY; i-=50){
     painter.drawLine(QPoint(-5, i), QPoint(5, i));
     if(i!=0){
         painter.drawText(-35, i+5, QString::number(-i));
      }
     }


  for (int i = 50; i<lower_end_of_OY; i+=50){
      painter.drawLine(QPoint(-5, i), QPoint(5, i));
      painter.drawText(-35, i+5, QString::number(-i));
  }



    QPointF previous_point(left_limit, Func(left_limit));
  for (int i = left_limit; i <= right_limit; i++) {
      QPointF current_point;
      current_point.rx() = i;
      current_point.ry() = Func(i);

      painter.setPen(pen_for_graph);
      painter.drawLine(previous_point, current_point);
      previous_point= current_point;

  }

}

void Drawing::mousePressEvent(QMouseEvent *event){
    int x = event->x();
}

