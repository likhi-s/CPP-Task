#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QLineEdit>
#include <QLabel>
#include <QColor>
#include <iostream>
using namespace std;

class QSpinBox;
class QLineEdit;
class ShapeOptionsWidget : public QWidget
{
    Q_OBJECT

public:
    ShapeOptionsWidget(QWidget *parent = nullptr);
    ~ShapeOptionsWidget();

    void setPenWidth(int width);
    void setBorderColor(const QColor &color);
    void setFillColor(const QColor &color);


signals:
    void penWidthChanged(int);
    void borderColorChanged(const QColor &);
    void fillColorChanged(const QColor &);

private:
    QSpinBox *penWidthSpin;
    QLineEdit *borderColorEdit;
    QLineEdit *fillColorEdit;
};
