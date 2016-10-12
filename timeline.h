#ifndef TIMELINE_H
#define TIMELINE_H

#include <QWidget>
#include <QtGui>
#include <QtCore>

namespace Ui {
class TimeLine;
}

class TimeLine : public QWidget
{
    Q_OBJECT

public:
    explicit TimeLine(QWidget *parent = 0);
    ~TimeLine();
    int x;
    int y;
    int hx;

private:
    Ui::TimeLine *ui;

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent( QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    //void resizeEvent(QResizeEvent *);
};

#endif // TIMELINE_H
