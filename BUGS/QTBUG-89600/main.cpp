#include <QApplication>
#include <QLCDNumber>
#include <QPushButton>
#include <QSlider>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("QLCDNumber Display Overloads");

    auto *layout = new QVBoxLayout(&window);

    QLCDNumber *lcd = new QLCDNumber;
    lcd->setDigitCount(8);

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 100);

    QLineEdit *lineEdit = new QLineEdit("HELLO");

    QPushButton *btn = new QPushButton("Display 3.14");

    layout->addWidget(lcd);
    layout->addWidget(slider);
    layout->addWidget(lineEdit);
    layout->addWidget(btn);

    QObject::connect(slider, &QSlider::valueChanged, [lcd](int value) {
        qDebug() << "Calling display(int): value =" << value;
        lcd->display(value);
    });

    QObject::connect(lineEdit, &QLineEdit::textChanged, [lcd](const QString &text) {
        qDebug() << "Calling display(QString): text =" << text;
        lcd->display(text);
    });

    QObject::connect(btn, &QPushButton::clicked, [lcd]() {
        double val = 3.142;
        qDebug() << "Calling display(double): value =" << val;
        lcd->display(val);
    });

    window.show();
    return app.exec();
}
