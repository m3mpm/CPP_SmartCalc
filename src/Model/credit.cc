#include "credit.h"

namespace m3mpm {
void Credit::SetCreditData(double input_sum, int input_period, double input_procent,
                           int input_payment_method) {
    sum_ = input_sum;
    period_ = input_period;
    procent_ = input_procent;
    payment_method_ = input_payment_method;
}

void Credit::CreditCalculation() {
    double month_procent = (procent_ / 12) / 100;
    if (payment_method_ == 1) {
        if (!data_.empty()) {
            data_.clear();
        }

        fix_month_pay_ = sum_ * (month_procent + (month_procent / (pow(1 + month_procent, period_) - 1)));
        over_pay_ = 0.0;
        double left_dolg = sum_;

        for (int i = 0; i < period_; i++) {
            double over_payi = left_dolg * month_procent;
            double main_dolg_payi = fix_month_pay_ - over_payi;
            left_dolg -= main_dolg_payi;
            over_pay_ += over_payi;

            data_.push_back({fix_month_pay_, main_dolg_payi, over_payi, left_dolg});
        }
        all_pay_ = sum_ + over_pay_;
    } else if (payment_method_ == 2) {
        if (!data_.empty()) {
            data_.clear();
        }
        fix_month_pay_ = sum_ / period_;
        double over_pay1 = sum_ * month_procent;
        month_pay_1_ = fix_month_pay_ + over_pay1;

        over_pay_ = 0.0;
        double over_payi = 0.0;
        double left_dolg = sum_;

        for (int i = 0; i < period_; i++) {
            over_payi = left_dolg * month_procent;
            left_dolg -= fix_month_pay_;
            over_pay_ += over_payi;
            double month_payi = fix_month_pay_ + over_payi;

            data_.push_back({month_payi, fix_month_pay_, over_payi, left_dolg});
        }
        all_pay_ = sum_ + over_pay_;
        month_pay_last_ = fix_month_pay_ + over_payi;
    }
}

double Credit::GetCreditFixMonthPay() { return fix_month_pay_; }
double Credit::GetCreditOverPay() { return over_pay_; }
double Credit::GetCreditAllPay() { return all_pay_; }
double Credit::GetCreditMonthPay1() { return month_pay_1_; }
double Credit::GetCreditMonthPayLast() { return month_pay_last_; }
std::vector<std::vector<double>> Credit::GetCreditTableData() { return data_; };
}  // namespace m3mpm
