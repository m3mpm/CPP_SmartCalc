#include "controller.h"

namespace m3mpm {
void Controller::SetString(std::string input_str) { calc_model_->SetString(input_str); }
void Controller::SetX(double input_x) { calc_model_->SetX(input_x); }
std::string Controller::GetError() { return calc_model_->GetError(); }
double Controller::GetResult() { return calc_model_->GetResult(); }

void Controller::CheckInputStr() { calc_model_->CheckInputStr(); }
void Controller::CreatePolishNotation() { calc_model_->CreatePolishNotation(); }
void Controller::MakeCalculation() { calc_model_->MakeCalculation(); }

void Controller::SetCreditData(double input_sum, int input_period, double input_procent, int pay_method) {
    credit_model_->SetCreditData(input_sum, input_period, input_procent, pay_method);
};

void Controller::CreditCalculation() { credit_model_->CreditCalculation(); }

double Controller::GetCreditFixMonthPay() { return credit_model_->GetCreditFixMonthPay(); };
double Controller::GetCreditOverPay() { return credit_model_->GetCreditOverPay(); };
double Controller::GetCreditAllPay() { return credit_model_->GetCreditAllPay(); };

double Controller::GetCreditMonthPay1() { return credit_model_->GetCreditMonthPay1(); }

double Controller::GetCreditMonthPayLast() { return credit_model_->GetCreditMonthPayLast(); }

std::vector<std::vector<double>> Controller::GetCreditTableData() {
    return credit_model_->GetCreditTableData();
};

void Controller::SetDepositData(double input_sum, int input_period, double input_procent,
                                double input_procentNalog, double input_procentNalogCb, QDate date_start,
                                int period_payment, int capitaliz, QVector<QPair<QString, QString>> poplnenie,
                                QVector<QPair<QString, QString>> snyatie) {
    deposit_model_->SetDepositData(input_sum, input_period, input_procent, input_procentNalog,
                                   input_procentNalogCb, date_start, period_payment, capitaliz, poplnenie,
                                   snyatie);
}

void Controller::DepositCalculation() { deposit_model_->DepositCalculation(); }
double Controller::GetDepositProfit() { return deposit_model_->GetDepositProfit(); }
double Controller::GetDepositSumNalog() { return deposit_model_->GetDepositSumNalog(); }
double Controller::GetDepositSum() { return deposit_model_->GetDepositSum(); }
}  // namespace m3mpm
