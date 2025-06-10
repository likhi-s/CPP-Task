#include "ShapeOptionsWidget.h"


ShapeOptionsWidget::ShapeOptionsWidget(QWidget *parent)
    : QWidget(parent)
{
    cout<<"ShapeOptionsWidget constructor Called"<<endl;
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setAlignment(Qt::AlignTop);

    QVBoxLayout *penLayout = new QVBoxLayout();
    penLayout->addWidget(new QLabel("Pen Width:"));

    penWidthSpin = new QSpinBox();
    penWidthSpin->setRange(1, 10);
    penLayout->addWidget(penWidthSpin);
    mainLayout->addLayout(penLayout);

    QVBoxLayout *borderLayout = new QVBoxLayout();
    borderLayout->addWidget(new QLabel("Border Color:"));
    borderColorEdit = new QLineEdit();
    borderColorEdit->setPlaceholderText("e.g., red");
    borderLayout->addWidget(borderColorEdit);
    mainLayout->addLayout(borderLayout);

    QVBoxLayout *fillLayout = new QVBoxLayout();
    fillLayout->addWidget(new QLabel("Fill Color:"));
    fillColorEdit = new QLineEdit();
    fillColorEdit->setPlaceholderText("e.g., blue");
    fillLayout->addWidget(fillColorEdit);
    mainLayout->addLayout(fillLayout);

    connect(penWidthSpin, QOverload<int>::of(&QSpinBox::valueChanged),
            this, &ShapeOptionsWidget::penWidthChanged);

    connect(borderColorEdit, &QLineEdit::textChanged, this, [=](const QString &text)
            {
                QColor color(text);
                if (color.isValid()) emit borderColorChanged(color);
            });

    connect(fillColorEdit, &QLineEdit::textChanged, this, [=](const QString &text)
            {
                QColor color(text);
                if (color.isValid()) emit fillColorChanged(color);
            });
}

ShapeOptionsWidget::~ShapeOptionsWidget()
{
    cout<<"ShapeOptionsWidget Destructor Called"<<endl;

}
void ShapeOptionsWidget::setPenWidth(int width)
{
    cout<<"ShapeOptionsWidget setPenWidth function Called"<<endl;
    penWidthSpin->blockSignals(true);
    penWidthSpin->setValue(width);
    penWidthSpin->blockSignals(false);
}

void ShapeOptionsWidget::setBorderColor(const QColor &color)
{
    cout<<"ShapeOptionsWidget setBorderColor function Called"<<endl;
    borderColorEdit->blockSignals(true);
    borderColorEdit->setText(color.name());
    borderColorEdit->blockSignals(false);
}

void ShapeOptionsWidget::setFillColor(const QColor &color)
{
    cout<<"ShapeOptionsWidget setFillColor function Called"<<endl;
    fillColorEdit->blockSignals(true);
    fillColorEdit->setText(color.name());
    fillColorEdit->blockSignals(false);
}
