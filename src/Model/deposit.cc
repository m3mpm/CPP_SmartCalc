#include "deposit.h"

namespace m3mpm {
void Deposit::SetDepositData(double input_sum, int input_period, double input_procent,
                             double input_procentNalog, double input_procentNalogCb, QDate date_start,
                             int period_payment, int capitaliz, QVector<QPair<QString, QString>> poplnenie,
                             QVector<QPair<QString, QString>> snyatie) {
    sum_ = input_sum;
    period_ = input_period;
    procent_ = input_procent;
    procent_nalog_ = input_procentNalog;
    procent_nalog_cb_ = input_procentNalogCb;
    date_start_ = date_start;
    period_payment_ = period_payment;
    capitaliz_ = capitaliz;
    poplnenie_ = poplnenie;
    snyatie_ = snyatie;
}

QDate Deposit::GetNextDatePayment(QDate start, QDate end, int period) {
    QDate res;
    if (period == 0) {
        res = start.addDays(1);
    } else if (period == 1) {
        res = start.addDays(7);
    } else if (period == 2) {
        res = start.addMonths(1);
    } else if (period == 3) {
        res = start.addMonths(6);
    } else if (period == 4) {
        res = start.addYears(1);
    } else {
        res = end;
    }
    if (res > end) {
        res = end;
    }
    return res;
}

double Deposit::GetSumFromTable(QVector<QPair<QString, QString>> &table, QDate date) {
    double res = 0;
    bool find = true;
    for (int i = 0; i < table.size() && find; i++) {
        QDate date_tmp = QDate::fromString(table[i].first, "yyyy-MM-dd");
        if (date == date_tmp) {
            res = table[i].second.toDouble();
            table.remove(i);
            find = false;
        }
    }
    return res;
}

double Deposit::NalogCalculation(double profit_sum) {
    double must_pay = 0;
    double sum_nalog_free = (1000000 * procent_nalog_cb_) / 100;
    double sum_nalog_pay = profit_sum - sum_nalog_free;
    if (sum_nalog_pay > 0) {
        must_pay = (sum_nalog_pay * procent_nalog_) / 100;
    }
    return must_pay;
}

void Deposit::DepositCalculation() {
    QDate date_finish = date_start_.addMonths(period_);
    QDate date_payment = GetNextDatePayment(date_start_, date_finish, period_payment_);

    double profit_sum = 0;
    double profit_capitaliz = 0;
    double profit_period = 0;
    double profit_year = 0;
    sum_nalog_ = 0;

    QDate date_tmp = date_start_;
    int year = date_start_.year();
    while (date_tmp < date_finish) {
        int days_in_year = date_tmp.daysInYear();
        double daily_profit = ((sum_ * procent_) / 100) / days_in_year;
        profit_sum += daily_profit;
        profit_capitaliz += daily_profit;
        profit_period += daily_profit;

        date_tmp = date_tmp.addDays(+1);

        int year_tmp = date_tmp.year();
        if (year != year_tmp && period_payment_ != 5) {
            sum_nalog_ += NalogCalculation(profit_year);
            profit_year = 0;
            year = year_tmp;
        }

        if (!snyatie_.isEmpty()) {
            double sub_sum = GetSumFromTable(snyatie_, date_tmp);
            sum_ -= sub_sum;
        }

        if (date_tmp == date_payment) {
            profit_year += profit_period;
            profit_period = 0;

            if (capitaliz_) {
                sum_ += profit_capitaliz;
                profit_capitaliz = 0;
            }
            date_payment = GetNextDatePayment(date_tmp, date_finish, period_payment_);
        }

        if (!poplnenie_.isEmpty()) {
            double add_sum = GetSumFromTable(poplnenie_, date_tmp);
            sum_ += add_sum;
        }
    }

    if (period_payment_ == 5) {
        sum_nalog_ += NalogCalculation(profit_sum);
    } else {
        sum_nalog_ += NalogCalculation(profit_year);
    }
    profit_ = profit_sum;
}

double Deposit::GetDepositProfit() { return profit_; }
double Deposit::GetDepositSumNalog() { return sum_nalog_; }
double Deposit::GetDepositSum() { return sum_; }
}  // namespace m3mpm
