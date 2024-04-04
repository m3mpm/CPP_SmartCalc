#ifndef SRC_CALCULATOR_CREDIT_H_
#define SRC_CALCULATOR_CREDIT_H_
#include <cmath>
#include <iostream>
#include <vector>

namespace m3mpm {
class Credit {
private:
    double sum_ = 0;
    int period_ = 0;
    double procent_ = 0;
    int payment_method_ = 0;

    double fix_month_pay_ = 0;
    double over_pay_ = 0;
    double all_pay_ = 0;
    double month_pay_1_ = 0;
    double month_pay_last_ = 0;
    std::vector<std::vector<double>> data_;

public:
    Credit(){};
    ~Credit(){};

    void SetCreditData(double input_sum, int input_period, double input_procent, int input_payment_method);

    void CreditCalculation();

    double GetCreditFixMonthPay();
    double GetCreditOverPay();
    double GetCreditAllPay();
    double GetCreditMonthPay1();
    double GetCreditMonthPayLast();
    std::vector<std::vector<double>> GetCreditTableData();
};
}  // namespace m3mpm
#endif  // SRC_CALCULATOR_CREDIT_H_
