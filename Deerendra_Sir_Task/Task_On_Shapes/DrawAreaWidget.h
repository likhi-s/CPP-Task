#ifndef DRAWAREAWIDGET_H
#define DRAWAREAWIDGET_H

#include <QWidget>
#include <QColor>
#include <QPainter>
#include <QPainterPath>
#include <iostream>
using namespace std;

class DrawAreaWidget : public QWidget
{
    Q_OBJECT

public:
    enum Shape {None,Rectangle, Circle,Triangle,Square };

    DrawAreaWidget(QWidget *parent = nullptr);
    ~DrawAreaWidget();
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

#endif // DRAWAREAWIDGET_H
