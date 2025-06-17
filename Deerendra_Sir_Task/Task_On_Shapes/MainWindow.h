#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ShapeSelectorWidget.h"
#include "ShapeOptionsWidget.h"
#include <QHBoxLayout>
#include <QMainWindow>
#include <QPushButton>
#include <QSpinBox>
#include <QColorDialog>
#include "DrawAreaWidget.h"
#include <iostream>
using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setupCentralWidget();
    void setupConnections();
    void applyDefaultDrawingOptions();
    void applyDefaultShapeOptions();


    DrawAreaWidget *m_drawArea;
    ShapeSelectorWidget *m_shapeSelector;
    ShapeOptionsWidget *m_shapeOptions;
    QSpinBox *m_penWidthBox;
};

#endif // MAINWINDOW_H
