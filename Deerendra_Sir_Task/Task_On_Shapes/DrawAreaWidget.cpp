#include "DrawAreaWidget.h"


DrawAreaWidget::DrawAreaWidget(QWidget *parent)
    : QWidget(parent), m_currentShape(None), m_penWidth(2),
    m_borderColor(Qt::black), m_fillColor(Qt::white)
{
    cout<<"DrawAreaWidget Constructor Called"<<endl;
}

DrawAreaWidget::~DrawAreaWidget()
{
    cout<<"DrawAreaWidget Destructor Called"<<endl;

}

void DrawAreaWidget::setShape(Shape shape)
{
    cout<<"SetShape Function Called"<<endl;
    m_currentShape = shape;
    update();
}

void DrawAreaWidget::setPenWidth(int penWidth)
{
    cout<<"setPenWidth Function Called"<<endl;

    m_penWidth = penWidth;
    update();
}

void DrawAreaWidget::setBorderColor(const QColor &borderColor)
{
    cout<<"setBorderColor Function Called"<<endl;

    m_borderColor = borderColor;
    update();
}

void DrawAreaWidget::setFillColor(const QColor &fillColor)
{
    cout<<"setFillColor Function Called"<<endl;

    m_fillColor = fillColor;
    update();
}

void DrawAreaWidget::paintEvent(QPaintEvent *)
{
    cout<<"DrawAreaWidget PaintEvent Function Called"<<endl;
    QPainter painter(this);
    painter.setPen(QPen(m_borderColor, m_penWidth));
    painter.setBrush(m_fillColor);

    QRect rect = this->rect();
    if (m_currentShape == Rectangle)
    {
        painter.drawRect(rect);
    }
    else if (m_currentShape == Circle)
    {
        painter.drawEllipse(rect);
    }
    else if (m_currentShape == Triangle)
    {
        QPoint top(rect.center().x(), rect.top());
        QPoint left(rect.bottomLeft());
        QPoint right(rect.bottomRight());

        QPolygon triangle;
        triangle << top << left << right;

        painter.drawPolygon(triangle);
    }
    else if(m_currentShape == Square)
    {
        int side = qMin(rect.width(), rect.height());
        int x = rect.center().x() - side / 2;
        int y = rect.center().y() - side / 2;
        QRect squareRect(x, y, side, side);

        painter.drawRect(squareRect);
    }

}
