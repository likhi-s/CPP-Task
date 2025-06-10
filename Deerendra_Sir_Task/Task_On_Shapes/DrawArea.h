#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QWidget>
#include <QColor>
#include <QPainter>
#include <QPainterPath>
#include <iostream>
using namespace std;

class DrawArea : public QWidget
{
    Q_OBJECT

public:
    enum Shape {None,Rectangle, Circle,Triangle,Square };

    DrawArea(QWidget *parent = nullptr);
    ~DrawArea();
    void setShape(Shape s);
    void setPenWidth(int w);
    void setBorderColor(const QColor &c);
    void setFillColor(const QColor &c);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Shape currentShape;
    int penWidth;
    QColor borderColor;
    QColor fillColor;
};

#endif // DRAWAREA_H
