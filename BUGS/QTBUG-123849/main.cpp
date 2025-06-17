#include <QApplication>
#include <QTableView>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTableView tableView;
    QStandardItemModel model(3, 3);
    tableView.setModel(&model);

    QHeaderView *horizontalHeader = tableView.horizontalHeader();
    QHeaderView *verticalHeader = tableView.verticalHeader();

    qDebug() << "QHeaderView default (manual):";
    QHeaderView testHeader(Qt::Horizontal);
    qDebug() << "  testHeader.highlightSections:" << testHeader.highlightSections();

    qDebug() << "QTableView's headers:";
    qDebug() << "  horizontalHeader.highlightSections:" << horizontalHeader->highlightSections();
    qDebug() << "  verticalHeader.highlightSections:" << verticalHeader->highlightSections();

    tableView.show();
    return app.exec();
}
