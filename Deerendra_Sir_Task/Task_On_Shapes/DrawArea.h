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
    void setShape(Shape shape);
    void setPenWidth(int penWidth);
    void setBorderColor(const QColor &borderColor);
    void setFillColor(const QColor &fillColor);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Shape m_currentShape;
    int m_penWidth;
    QColor m_borderColor;
    QColor m_fillColor;
};

#endif // DRAWAREA_H
