#ifndef SRC_CALCULATOR_CONTROLLER_H_
#define SRC_CALCULATOR_CONTROLLER_H_

#include "../Model/credit.h"
#include "../Model/deposit.h"
#include "../Model/model.h"

namespace m3mpm {
class Controller {
private:
    m3mpm::Calculator *calc_model_;
    m3mpm::Credit *credit_model_;
    m3mpm::Deposit *deposit_model_;

public:
    Controller(Calculator *m, Credit *c, Deposit *d) : calc_model_(m), credit_model_(c), deposit_model_(d) {}
    ~Controller() {}

    void SetString(std::string);
    void SetX(double);
    std::string GetError();
    double GetResult();

    void CheckInputStr();
    void CreatePolishNotation();
    void MakeCalculation();

    void SetCreditData(double input_sum, int input_period, double input_procent, int pay_method);
    void CreditCalculation();
    double GetCreditFixMonthPay();
    double GetCreditOverPay();
    double GetCreditAllPay();
    double GetCreditMonthPay1();
    double GetCreditMonthPayLast();
    std::vector<std::vector<double>> GetCreditTableData();

    void SetDepositData(double input_sum, int input_period, double input_procent, double input_procentNalog,
                        double input_procentNalogCb, QDate date_start, int period_payment, int capitaliz,
                        QVector<QPair<QString, QString>> poplnenie, QVector<QPair<QString, QString>> snyatie);

    void DepositCalculation();
    double GetDepositProfit();
    double GetDepositSumNalog();
    double GetDepositSum();
};
}  // namespace m3mpm
#endif  // SRC_CALCULATOR_CONTROLLER_H_
