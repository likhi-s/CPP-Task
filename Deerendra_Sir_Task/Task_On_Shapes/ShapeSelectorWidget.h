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

};

#endif // SHAPESELECTORWIDGET_H
