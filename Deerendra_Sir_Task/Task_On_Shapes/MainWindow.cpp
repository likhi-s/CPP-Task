#include "MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    std::cout << "MainWindow Constructor Called" << std::endl;

    setupCentralWidget();
    setupConnections();
}
void MainWindow::setupCentralWidget()
{
    cout<<"MainWindow setupCentralWidget function called "<<endl;
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    auto *mainLayout = new QHBoxLayout(central);

    m_shapeSelector = new ShapeSelectorWidget();
    m_shapeOptions = new ShapeOptionsWidget();
    m_drawArea = new DrawAreaWidget();
    m_drawArea->setFixedSize(350, 350);

    mainLayout->addWidget(m_shapeSelector, 0);
    mainLayout->addWidget(m_drawArea, 1);
    mainLayout->addWidget(m_shapeOptions, 0);
}
void MainWindow::applyDefaultDrawingOptions()
{
    int defaultPenWidth = 2;
    QColor defaultBorderColor = Qt::black;
    QColor defaultFillColor = Qt::white;

    m_drawArea->setPenWidth(defaultPenWidth);
    m_drawArea->setBorderColor(defaultBorderColor);
    m_drawArea->setFillColor(defaultFillColor);
}

void MainWindow::applyDefaultShapeOptions()
{
    int defaultPenWidth = 2;
    QColor defaultBorderColor = Qt::black;
    QColor defaultFillColor = Qt::white;

    m_shapeOptions->setPenWidth(defaultPenWidth);
    m_shapeOptions->setBorderColor(defaultBorderColor);
    m_shapeOptions->setFillColor(defaultFillColor);
}

void MainWindow::setupConnections()
{
    cout<<"MainWindow setupConnections function called "<<endl;
    connect(m_shapeSelector, &ShapeSelectorWidget::shapeSelected, this, [=](int type)
            {
                applyDefaultDrawingOptions();
                applyDefaultShapeOptions();

                m_drawArea->setShape(static_cast<DrawAreaWidget::Shape>(type));
            });

    connect(m_shapeOptions, &ShapeOptionsWidget::penWidthChanged, m_drawArea, &DrawAreaWidget::setPenWidth);
    connect(m_shapeOptions, &ShapeOptionsWidget::borderColorChanged, m_drawArea, &DrawAreaWidget::setBorderColor);
    connect(m_shapeOptions, &ShapeOptionsWidget::fillColorChanged, m_drawArea, &DrawAreaWidget::setFillColor);
}


MainWindow::~MainWindow()
{
    cout<<"MainWindow Destructor Called"<<endl;

}
