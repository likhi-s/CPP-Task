#include "MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    cout<<"MainWindow Constructor Called"<<endl;
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    auto *mainLayout = new QHBoxLayout(central);

    auto *shapeSelector = new ShapeSelectorWidget();
    auto *shapeOptions = new ShapeOptionsWidget();
    drawArea = new DrawArea();
    mainLayout->addWidget(shapeSelector,0);
    mainLayout->addWidget(drawArea,1);
    mainLayout->addWidget(shapeOptions,0);

    drawArea->setFixedSize(350,350);

    connect(shapeSelector, &ShapeSelectorWidget::shapeSelected, this, [=](int type) {

        int defaultPenWidth = 2;
        QColor defaultBorderColor = Qt::black;
        QColor defaultFillColor = Qt::white;

        drawArea->setPenWidth(defaultPenWidth);
        drawArea->setBorderColor(defaultBorderColor);
        drawArea->setFillColor(defaultFillColor);

        shapeOptions->setPenWidth(defaultPenWidth);
        shapeOptions->setBorderColor(defaultBorderColor);
        shapeOptions->setFillColor(defaultFillColor);

        drawArea->setShape(static_cast<DrawArea::Shape>(type));
    });



    connect(shapeOptions, &ShapeOptionsWidget::penWidthChanged, drawArea, &DrawArea::setPenWidth);
    connect(shapeOptions, &ShapeOptionsWidget::borderColorChanged, drawArea, &DrawArea::setBorderColor);
    connect(shapeOptions, &ShapeOptionsWidget::fillColorChanged, drawArea, &DrawArea::setFillColor);
}


MainWindow::~MainWindow()
{
    cout<<"MainWindow Destructor Called"<<endl;

}
