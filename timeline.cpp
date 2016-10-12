#include "timeline.h"
#include "ui_timeline.h"
#include <QColor>

TimeLine::TimeLine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimeLine)
{
    ui->setupUi(this);
    x=-100;
    hx = 50; //utilize constructor to intialze values once
}

TimeLine::~TimeLine()
{
    delete ui;
}

void TimeLine::paintEvent(QPaintEvent *e){//use this
   QPainter painter(this);

   QPen keyFramePen(QColor(102, 102, 102));
   QPen keyFrameSectionPen(QColor(166, 166, 166));
   QPen newpen(QColor(0, 153, 255));

   keyFramePen.setWidth(1);
   keyFrameSectionPen.setWidth(1);

   //int i;
   int maxHeight = this->height();
   int maxWidth = this->width();

   painter.fillRect(0,0, maxWidth, maxHeight, QColor(77, 77, 77) ); //background

   int i=-100;
   for(int mx=x; mx<maxWidth; mx+=5 ){ // line
      QPoint p1;
      p1.setX(mx);
      p1.setY(0);
      QPoint p2;
      p2.setX(mx);
      p2.setY(maxHeight);

      qDebug() << i;
      if( ( i % 25 ) == 0 ) {
        painter.setPen(keyFrameSectionPen);
      } else {
        painter.setPen(keyFramePen);
      }
      painter.drawLine(p1,p2);

      i+=5;
   }

   //point movement example
   QPoint p1;
   p1.setX(hx);
   p1.setY(0);
   QPoint p2;
   p2.setX(hx);
   p2.setY(maxHeight);
   painter.setPen(newpen);
   painter.drawLine(p1,p2);

   //painter.fillRect(x,y,10,10 , QColor(0, 153, 255));

}

void TimeLine::mousePressEvent(QMouseEvent *event){
    if (event->button()==Qt::RightButton){
        //qDebug() << event->pos();
        hx = event->localPos().x();
        repaint();
    }
}


void TimeLine::mouseMoveEvent(QMouseEvent *event){

    if(event->buttons() & Qt::LeftButton)
    {
        //qDebug() << event->localPos().x();
        hx = event->localPos().x();
        this->repaint();
    }

    if(event->buttons() & Qt::MiddleButton)
    {
        //qDebug() << event->localPos().x();
        x = event->localPos().x();
        this->repaint();
    }


}

