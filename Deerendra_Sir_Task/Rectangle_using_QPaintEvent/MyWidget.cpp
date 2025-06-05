#include "MyWidget.h"
#include <QPainter>

MyWidget::MyWidget(QWidget* parent)
    : QWidget(parent)
{
    cout<<"MyWidget Constructor Called"<<endl;
}

void MyWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.drawRect(200, 50, 150, 60);
}

MyWidget::~MyWidget()
{
    cout<<"MyWidget Destructor Called"<<endl;

}
