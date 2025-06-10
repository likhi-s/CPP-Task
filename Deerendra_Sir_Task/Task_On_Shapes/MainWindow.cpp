#include "MainWindow.h"


/*MainWindow::MainWindow(QWidget *parent)
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

    drawArea->setFixedSize(200,200);
    drawArea->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

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
}*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    QHBoxLayout *mainLayout = new QHBoxLayout(central);

    auto *sidePanelLayout = new QVBoxLayout();  // 👈 for vertical alignment
    auto *shapeSelector = new ShapeSelectorWidget();
    auto *shapeOptions = new ShapeOptionsWidget();
    drawArea = new DrawArea();

    // Reduce space and align top
    sidePanelLayout->setSpacing(10);
    sidePanelLayout->setContentsMargins(5, 5, 5, 5);
    sidePanelLayout->addWidget(shapeSelector);
    sidePanelLayout->addWidget(shapeOptions);
    sidePanelLayout->addStretch();  // push widgets to the top

    QWidget *sidePanel = new QWidget();
    sidePanel->setLayout(sidePanelLayout);
    sidePanel->setFixedWidth(250);  // optional width for side panel

    mainLayout->addWidget(sidePanel);      // left side panel
    mainLayout->addWidget(drawArea, 1);    // drawing area stretches

    // Connections
    connect(shapeSelector, &ShapeSelectorWidget::shapeSelected, [=](int type){
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
