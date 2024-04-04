#ifndef SRC_CALCULATOR_DEPOSIT_H_
#define SRC_CALCULATOR_DEPOSIT_H_
#include <QDate>
#include <QPair>
#include <QString>
#include <QTableWidget>
#include <QVector>
#include <iostream>

namespace m3mpm {
class Deposit {
private:
    double sum_ = 0;
    int period_ = 0;
    double procent_ = 0;
    double procent_nalog_ = 0;
    double procent_nalog_cb_ = 0;

    QDate date_start_;
    int period_payment_ = 0;
    int capitaliz_ = 0;

    QVector<QPair<QString, QString>> poplnenie_;
    QVector<QPair<QString, QString>> snyatie_;

    double profit_ = 0;
    double sum_nalog_ = 0;

public:
    Deposit(){};
    ~Deposit(){};

    void SetDepositData(double input_sum, int input_period, double input_procent, double input_procentNalog,
                        double input_procentNalogCb, QDate date_start, int period_payment, int capitaliz,
                        QVector<QPair<QString, QString>> poplnenie, QVector<QPair<QString, QString>> snyatie);

    QDate GetNextDatePayment(QDate start, QDate end, int period);
    double GetSumFromTable(QVector<QPair<QString, QString>> &table, QDate date);
    double NalogCalculation(double profit_sum);

    void DepositCalculation();

    double GetDepositProfit();
    double GetDepositSumNalog();
    double GetDepositSum();
};
}  // namespace m3mpm
#endif  // SRC_CALCULATOR_DEPOSIT_H_
