#ifndef SHAPESELECTORWIDGET_H
#define SHAPESELECTORWIDGET_H

#include <QWidget>
#include "ShapeButton.h"
#include <iostream>
using namespace std;

class ShapeSelectorWidget : public QWidget
{
    Q_OBJECT
public:
    ShapeSelectorWidget(QWidget *parent = nullptr);
    ~ShapeSelectorWidget();

signals:
    void shapeSelected(ShapeType shape);
private:
    void setupUI();
    void setupConnections();

    ShapeButton *m_rectBtn;
    ShapeButton *m_circleBtn;
    ShapeButton *m_triangleBtn;
    ShapeButton *m_squareBtn;


};

#endif // SHAPESELECTORWIDGET_H
