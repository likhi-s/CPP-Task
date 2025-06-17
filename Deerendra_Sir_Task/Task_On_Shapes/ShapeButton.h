#ifndef SHAPEBUTTON_H
#define SHAPEBUTTON_H

#include <QPainter>
#include <QPushButton>
#include <iostream>
using namespace std;

enum ShapeType
{
    Shape_Rectangle=1,
    Shape_Circle,
    Shape_Triangle,
    Shape_Square
};

class ShapeButton : public QPushButton
{
    Q_OBJECT

public:
    ShapeButton(ShapeType shape, QWidget *parent = nullptr);
    ~ShapeButton();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    ShapeType m_shape;
};

#endif // SHAPEBUTTON_H
