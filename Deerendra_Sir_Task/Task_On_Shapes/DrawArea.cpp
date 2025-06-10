#include "DrawArea.h"


DrawArea::DrawArea(QWidget *parent)
    : QWidget(parent), currentShape(None), penWidth(2),
    borderColor(Qt::black), fillColor(Qt::white)
{
    cout<<"DrawArea Constructor Called"<<endl;
}

DrawArea::~DrawArea()
{
    cout<<"DrawArea Destructor Called"<<endl;

}

void DrawArea::setShape(Shape s)
{
    cout<<"SetShape Function Called"<<endl;
    currentShape = s;
    update();
}

void DrawArea::setPenWidth(int w)
{
    cout<<"setPenWidth Function Called"<<endl;

    penWidth = w;
    update();
}

void DrawArea::setBorderColor(const QColor &c)
{
    cout<<"setBorderColor Function Called"<<endl;

    borderColor = c;
    update();
}

void DrawArea::setFillColor(const QColor &c)
{
    cout<<"setFillColor Function Called"<<endl;

    fillColor = c;
    update();
}

void DrawArea::paintEvent(QPaintEvent *)
{
    cout<<"DrawArea PaintEvent Function Called"<<endl;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(borderColor, penWidth));
    painter.setBrush(fillColor);

    QRect rect = this->rect().adjusted(50, 50, -50, -50);
    if (currentShape == Rectangle)
        painter.drawRect(rect);
    else if (currentShape == Circle)
        painter.drawEllipse(rect);
    else if (currentShape == Triangle)
    {
        QPoint top(rect.center().x(), rect.top());
        QPoint left(rect.bottomLeft());
        QPoint right(rect.bottomRight());

        QPolygon triangle;
        triangle << top << left << right;

        painter.drawPolygon(triangle);
    }
    else if(currentShape == Square)
    {
        int side = qMin(rect.width(), rect.height());
        int x = rect.center().x() - side / 2;
        int y = rect.center().y() - side / 2;
        QRect squareRect(x, y, side, side);

        painter.drawRect(squareRect);
    }

}
