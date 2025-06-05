#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <iostream>
using namespace std;
#include <QWidget>

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();
protected:
    void paintEvent(QPaintEvent* event) override;
};
#endif // MYWIDGET_H
