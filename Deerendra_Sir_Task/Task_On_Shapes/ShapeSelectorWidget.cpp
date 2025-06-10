#include "ShapeSelectorWidget.h"
#include <QVBoxLayout>

ShapeSelectorWidget::ShapeSelectorWidget(QWidget *parent)
    : QWidget(parent)
{
    cout<<"ShapeSelectorWidget Constructor Called"<<endl;
    QVBoxLayout *layout = new QVBoxLayout(this);

    ShapeButton *rectBtn = new ShapeButton(Shape_Rectangle);
    ShapeButton *circleBtn = new ShapeButton(Shape_Circle);
    ShapeButton *triangleBtn = new ShapeButton(Shape_Triangle);
    ShapeButton *squareBtn = new ShapeButton(Shape_Square);

    layout->addWidget(rectBtn);
    layout->addWidget(circleBtn);
    layout->addWidget(triangleBtn);
    layout->addWidget(squareBtn);


    connect(rectBtn, &QPushButton::clicked, [=]() { emit shapeSelected(Shape_Rectangle); });
    connect(circleBtn, &QPushButton::clicked, [=]() { emit shapeSelected(Shape_Circle); });
    connect(triangleBtn, &QPushButton::clicked, [=]() { emit shapeSelected(Shape_Triangle); });
    connect(squareBtn, &QPushButton::clicked, [=]() { emit shapeSelected(Shape_Square); });

}

ShapeSelectorWidget::~ShapeSelectorWidget()
{
    cout<<"ShapeSelectorWidget Destructor Called"<<endl;

}
