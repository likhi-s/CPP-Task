#include "ShapeSelectorWidget.h"
#include <QVBoxLayout>

ShapeSelectorWidget::ShapeSelectorWidget(QWidget *parent)
    : QWidget(parent)
{
    cout << "ShapeSelectorWidget Constructor Called" << endl;
    setupUI();
    setupConnections();
}

ShapeSelectorWidget::~ShapeSelectorWidget()
{
    cout<<"ShapeSelectorWidget Destructor Called"<<endl;

}
void ShapeSelectorWidget::setupUI()
{
    cout << "ShapeSelectorWidget setupUI fun Called" << endl;

    QVBoxLayout *layout = new QVBoxLayout(this);

    m_rectBtn = new ShapeButton(Shape_Rectangle);
    m_circleBtn = new ShapeButton(Shape_Circle);
    m_triangleBtn = new ShapeButton(Shape_Triangle);
    m_squareBtn = new ShapeButton(Shape_Square);

    layout->addWidget(m_rectBtn);
    layout->addWidget(m_circleBtn);
    layout->addWidget(m_triangleBtn);
    layout->addWidget(m_squareBtn);
}
void ShapeSelectorWidget::setupConnections()
{
    cout << "ShapeSelectorWidget setupConnections fun Called" << endl;

    connect(m_rectBtn, &QPushButton::clicked, this, [=]() {
        emit shapeSelected(Shape_Rectangle);
    });

    connect(m_circleBtn, &QPushButton::clicked, this, [=]() {
        emit shapeSelected(Shape_Circle);
    });

    connect(m_triangleBtn, &QPushButton::clicked, this, [=]() {
        emit shapeSelected(Shape_Triangle);
    });

    connect(m_squareBtn, &QPushButton::clicked, this, [=]() {
        emit shapeSelected(Shape_Square);
    });
}
