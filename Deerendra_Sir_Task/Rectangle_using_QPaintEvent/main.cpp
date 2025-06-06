// #include "MyWidget.h"

// #include <QApplication>

// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);
//     MyWidget w;
//     w.show();
//     return a.exec();
// }
    #include <QApplication>
    #include <QWidget>
    #include <QMainWindow>
    #include <QDockWidget>
  //  #include <QQuickWidget>

    int main( int argc, char *argv[] )

    Unknown macro: {     QApplication app( argc, argv );     app.setQuitOnLastWindowClosed(true);     auto mainWindow = new QMainWindow();     mainWindow->setAttribute(Qt}
        )");

        auto quickWidget = new QQuickWidget(bg);
        quickWidget->setSource(QUrl::fromUserInput("data:text/plain," + qmlContent));
        quickWidget->show();

        // create the widget container from bg widget's window handle

        // and add that as the main widget for the dockWidget.

        auto container = QWidget::createWindowContainer(bg->windowHandle());
        container->setObjectName("container");
        dockWidget->setWidget(container);

        return app.exec();
    }
