#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// добавил библиотеки
#include <qtablewidget.h>

#include <QByteArray>
#include <QDate>
#include <QKeyEvent>
#include <QPair>
#include <QString>
#include <QTableWidget>
#include <QVector>
#include <QtMath>
#include <iostream>

#include "./Controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(m3mpm::Controller *c, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    m3mpm::Controller *controller_;
    void InsertRowToTable(QTableWidget *table);
    void DeleteRowFromTable(QTableWidget *table);

    void setDefaultDepositData();
    void setCurrentDateInDateEdit();
    void setHeaderLabelsDepositTables();

    QVector<QPair<QString, QString>> GetDataFromTable(QTableWidget *table);

private slots:
    void digits_numbers();
    void on_pushButton_erase_clicked();
    void on_pushButton_dot_clicked();
    void math_operations_div();
    void math_operations_multi();
    void math_operations_exp();
    void math_operations_plus();
    void math_operations_minus();
    void math_operations_e();
    void functions();
    void brackets();
    void on_pushButton_clear_clicked();
    void on_pushButton_getResult_clicked();

    void on_pushButton_graph_clicked();
    void on_pushButton_comeBackToCalc1_clicked();
    void on_pushButton_clearGraph_clicked();
    void on_pushButton_buildGraph_clicked();

    void on_pushButton_creditCalc_clicked();
    void on_pushButton_creditGetResult_clicked();
    void on_pushButton_comeBackToCalc2_clicked();
    void on_pushButton_creditClear_clicked();

    void on_pushButton_depositCalc_clicked();
    void on_pushButton_clearDeposit_clicked();
    void on_pushButton_comeBackToCalc3_clicked();
    void on_pushButton_popolnitDeposit_clicked();
    void on_pushButton_snyatDeposit_clicked();
    void on_pushButton_getResultDeposit_clicked();
    void on_pushButton_popolnitDeposit_2_clicked();
    void on_pushButton_snyatDeposit_2_clicked();

protected:
    void keyPressEvent(QKeyEvent *event);
};
#endif  // MAINWINDOW_H
