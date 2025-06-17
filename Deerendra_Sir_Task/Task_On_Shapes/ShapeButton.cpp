#include "ShapeButton.h"

ShapeButton::ShapeButton(ShapeType shape, QWidget *parent)
    : QPushButton(parent), m_shape(shape)
{
    cout<<"ShapeButton Constructor Called"<<endl;
    setFixedSize(80, 80);
}

ShapeButton::~ShapeButton()
{
    cout<<"ShapeButton Destructor Called"<<endl;
}


void ShapeButton::paintEvent(QPaintEvent *event)
{
    cout<<"ShapeButtonWidget PaintEvent Function Called"<<endl;
    QPushButton::paintEvent(event);

    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::gray);

    switch (m_shape)
    {

    case Shape_Rectangle:
        painter.drawRect(20, 20, width() - 40, height() - 40);
        break;
    case Shape_Circle:
        painter.drawEllipse(20, 20, width() - 40, height() - 40);
        break;

    case Shape_Triangle:
    {
        QRect rect = this->rect().adjusted(20, 20, -20, -20);
        QPoint top(rect.center().x(), rect.top());
        QPoint left(rect.bottomLeft());
        QPoint right(rect.bottomRight());

        QPolygon triangle;
        triangle << top << left << right;
        painter.drawPolygon(triangle);
        break;
    }
    case Shape_Square:
    {
        QRect rect = this->rect().adjusted(20, 20, -20, -20);
        int side = qMin(rect.width(), rect.height());
        int x = rect.center().x() - side / 2;
        int y = rect.center().y() - side / 2;
        QRect squareRect(x, y, side, side);
        painter.drawRect(squareRect);
        break;
    }

    }
}
