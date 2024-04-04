#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(m3mpm::Controller *c, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller_(c) {
    QLocale curLocale(QLocale("ru_RU"));
    QLocale::setDefault(curLocale);

    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(digits_numbers()));

    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(math_operations_div()));
    connect(ui->pushButton_multi, SIGNAL(clicked()), this, SLOT(math_operations_multi()));
    connect(ui->pushButton_exp, SIGNAL(clicked()), this, SLOT(math_operations_exp()));
    connect(ui->pushButton_munis, SIGNAL(clicked()), this, SLOT(math_operations_minus()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations_plus()));
    connect(ui->pushButton_e, SIGNAL(clicked()), this, SLOT(math_operations_e()));

    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(functions()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(functions()));
    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(functions()));
    connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(functions()));
    connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(functions()));
    connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(functions()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(functions()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(functions()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(functions()));
    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(functions()));

    connect(ui->pushButton_openBracket, SIGNAL(clicked()), this, SLOT(brackets()));
    connect(ui->pushButton_closeBracket, SIGNAL(clicked()), this, SLOT(brackets()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Return) ui->pushButton_getResult->click();
    if (event->key() == Qt::Key_Escape) ui->pushButton_clear->click();
}

void MainWindow::digits_numbers() {
    QPushButton *button = (QPushButton *)sender();
    QString str = ui->lineEdit->text();
    ui->lineEdit->setText(str + button->text());
}

void MainWindow::on_pushButton_erase_clicked() {
    QString str = ui->lineEdit->text();
    str = str.left(str.count() - 1);
    ui->lineEdit->setText(str);
}

void MainWindow::on_pushButton_dot_clicked() {
    QPushButton *button = (QPushButton *)sender();
    QString str = ui->lineEdit->text();
    int len = str.length();
    if (len == 0) {
        ui->lineEdit->setText("0" + button->text());
    } else {
        ui->lineEdit->setText(str + button->text());
    }
}

void MainWindow::math_operations_div() {
    QPushButton *button = (QPushButton *)sender();
    QString str = ui->lineEdit->text();
    int len = str.length();
    if (len == 0) {
        ui->lineEdit->setText("0" + button->text());
    } else if (str[len - 1] == '*') {
        str = str.left(str.count() - 1);
        ui->lineEdit->setText(str + button->text());
    } else if (str[len - 1] == '/') {
        ui->lineEdit->setText((str));
    } else if (str[len - 1] == '-') {
        ui->lineEdit->setText((str));
    } else if (str[len - 1] == '+') {
        ui->lineEdit->setText((str));
    } else if (str[len - 1] == '^') {
        str = str.left(str.count() - 1);
        ui->lineEdit->setText(str + button->text());
    } else {
        ui->lineEdit->setText(str + button->text());
    }
}

void MainWindow::math_operations_multi() {
    QPushButton *button = (QPushButton *)sender();
    QString str = ui->lineEdit->text();
    int len = str.length();
    if (len == 0) {
        ui->lineEdit->setText("0" + button->text());
    } else if (str[len - 1] == '/') {
        str = str.left(str.count() - 1);
        ui->lineEdit->setText(str + button->text());
    } else if (str[len - 1] == '*') {
        ui->lineEdit->setText(str);
    } else if (str[len - 1] == '-') {
        ui->lineEdit->setText(str);
    } else if (str[len - 1] == '+') {
        ui->lineEdit->setText(str);
    } else if (str[len - 1] == '^') {
        str = str.left(str.count() - 1);
        ui->lineEdit->setText(str + button->text());
    } else {
        ui->lineEdit->setText(str + button->text());
    }
}

void MainWindow::math_operations_exp() {
    QPushButton *button = (QPushButton *)sender();
    QString str = ui->lineEdit->text();
    int len = str.length();
    if (len == 0) {
        ui->lineEdit->setText("0" + button->text());
    } else if (len > 2 && ((str[len - 2] == '*' || str[len - 2] == '/') &&
                           (str[len - 1] == '+' || str[len - 1] == '-'))) {
        ui->lineEdit->setText(str);
    } else if (str[len - 1] == '-') {
        str = str.left(str.count() - 1);
        ui->lineEdit->setText(str + button->text());
    } else if (str[len - 1] == '+') {
        str = str.left(str.count() - 1);
        ui->lineEdit->setText(str + button->text());
    } else if (str[len - 1] == '/') {
        str = str.left(str.count() - 1);
        ui->lineEdit->setText(str + button->text());
    } else if (str[len - 1] == '*') {
        str = str.left(str.count() - 1);
        ui->lineEdit->setText(str + button->text());
    } else if (str[len - 1] == '^') {
        ui->lineEdit->setText(str);
    } else {
        ui->lineEdit->setText(str + button->text());
    }
}

void MainWindow::math_operations_plus() {
    QPushButton *button = (QPushButton *)sender();
    QString str = ui->lineEdit->text();
    int len = str.length();
    if (len == 0) {
        ui->lineEdit->setText(str + button->text());
    } else if (str[len - 1] == '-') {
        str = str.left(str.count() - 1);
        ui->lineEdit->setText(str + button->text());
    } else if (str[len - 1] == '+') {
        ui->lineEdit->setText(str);
    } else {
        ui->lineEdit->setText(str + button->text());
    }
}

void MainWindow::math_operations_minus() {
    QPushButton *button = (QPushButton *)sender();
    QString str = ui->lineEdit->text();
    int len = str.length();
    if (len == 0) {
        ui->lineEdit->setText((str + button->text()));
    } else if (str[len - 1] == '+') {
        str = str.left(str.count() - 1);
        ui->lineEdit->setText((str + button->text()));
    } else if (str[len - 1] == '-') {
        ui->lineEdit->setText((str));
    } else {
        ui->lineEdit->setText((str + button->text()));
    }
}

void MainWindow::math_operations_e() {
    QPushButton *button = (QPushButton *)sender();
    QString str = ui->lineEdit->text();
    int len = str.length();
    if (len == 0) {
        ui->lineEdit->setText(str);
    } else if (str[len - 1] >= '0' && str[len - 1] <= '9') {
        ui->lineEdit->setText((str + button->text()));
    }
}

void MainWindow::functions() {
    QPushButton *button = (QPushButton *)sender();
    QString str = ui->lineEdit->text();
    ui->lineEdit->setText((str + button->text() + "("));
}

void MainWindow::brackets() {
    QPushButton *button = (QPushButton *)sender();
    QString str = ui->lineEdit->text();
    ui->lineEdit->setText((str + button->text()));
}

void MainWindow::on_pushButton_clear_clicked() {
    ui->lineEdit->setText("");
    ui->lineEdit->clear();
    ui->doubleSpinBox_x->setValue(0);
}

void MainWindow::on_pushButton_getResult_clicked() {
    QString str = ui->lineEdit->text().toLower();
    if (str.isEmpty()) {
        ui->lineEdit->setText(str);
    } else {
        double input_x = ui->doubleSpinBox_x->value();
        std::string input_string = str.toStdString();
        controller_->SetString(input_string);
        controller_->SetX(input_x);
        try {
            controller_->CheckInputStr();
            controller_->CreatePolishNotation();
            controller_->MakeCalculation();
            if (isnan(controller_->GetResult())) {
                ui->lineEdit->setText("Error");
            } else {
                ui->lineEdit->setText(QString::number(controller_->GetResult(), 'l', 2));
            }
        } catch (m3mpm::MyException &ex) {
            ui->lineEdit->setText(QString::fromStdString(ex.GetErorr()));
        } catch (const std::exception &e) {
            ui->lineEdit->setText(QString::fromStdString(e.what()));
        }
    }
}

void MainWindow::on_pushButton_graph_clicked() {
    QString str = ui->lineEdit->text();
    if (str.isEmpty()) {
        ui->lineEdit->setText(str);
    } else {
        ui->spinBox_startX->setValue(-10);
        ui->spinBox_endX->setValue(10);
        ui->spinBox_startY->setValue(-10);
        ui->spinBox_endY->setValue(10);
        ui->Graph->clearGraphs();
        ui->Graph->replot();
        ui->stackedWidget->setCurrentIndex(1);
    }
}

void MainWindow::on_pushButton_comeBackToCalc1_clicked() {
    ui->lineEdit->setText("");
    ui->lineEdit->clear();
    ui->doubleSpinBox_x->setValue(0);
    ui->Graph->clearGraphs();
    ui->Graph->replot();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_clearGraph_clicked() {
    ui->spinBox_startX->setValue(-10);
    ui->spinBox_endX->setValue(10);
    ui->spinBox_startY->setValue(-10);
    ui->spinBox_endY->setValue(10);
    ui->Graph->clearGraphs();
    ui->Graph->replot();
}

void MainWindow::on_pushButton_buildGraph_clicked() {
    QString str = ui->lineEdit->text().toLower();
    if (str.contains('x')) {
        std::string input_string = str.toStdString();
        controller_->SetString(input_string);
        try {
            controller_->CheckInputStr();
            controller_->CreatePolishNotation();

            double start_x = (double)ui->spinBox_startX->value();
            double end_x = (double)ui->spinBox_endX->value();
            double start_y = (double)ui->spinBox_startY->value();
            double end_y = (double)ui->spinBox_endY->value();

            if (start_x < end_x && start_y < end_y) {
                double result = 0.0;
                double step = fabs(start_x - end_x) / 10000;

                ui->Graph->xAxis->setRange(start_x - 10, end_x + 10);
                ui->Graph->yAxis->setRange(start_y - 10, end_y + 10);

                QVector<double> x, y;
                for (double X = start_x; X <= end_x; X += step) {
                    controller_->SetX(X);
                    controller_->MakeCalculation();
                    if (!isnan(controller_->GetResult())) {
                        result = controller_->GetResult();
                        if (result >= start_y && result <= end_y) {
                            x.push_back(X);
                            y.push_back(result);
                        }
                    }
                }
                ui->Graph->addGraph();

                ui->Graph->graph(0)->setLineStyle(QCPGraph::lsNone);
                ui->Graph->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 2));

                ui->Graph->graph(0)->addData(x, y);
                ui->Graph->replot();

                ui->Graph->setInteraction(QCP::iRangeDrag, 1);
                ui->Graph->setInteraction(QCP::iRangeZoom, 1);
                x.clear();
                y.clear();
            } else {
                ui->stackedWidget->setCurrentIndex(0);
                ui->lineEdit->setText("Input error: start x > end x or start y > end y");
            }
        } catch (m3mpm::MyException &ex) {
            ui->stackedWidget->setCurrentIndex(0);
            ui->lineEdit->setText(QString::fromStdString(ex.GetErorr()));
        } catch (const std::exception &e) {
            ui->stackedWidget->setCurrentIndex(0);
            std::cerr << e.what() << '\n';
        }
    } else {
        ui->stackedWidget->setCurrentIndex(0);
        ui->lineEdit->setText(str);
    }
}

void MainWindow::on_pushButton_creditCalc_clicked() {
    ui->stackedWidget->setCurrentIndex(2);
    ui->radioButton_ann->setChecked(1);
}

void MainWindow::on_pushButton_comeBackToCalc2_clicked() {
    on_pushButton_creditClear_clicked();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_creditClear_clicked() {
    ui->doubleSpinBox_sumCredit->setValue(0);
    ui->spinBox_periodCredit->setValue(0);
    ui->doubleSpinBox_procentCredit->setValue(0);

    ui->radioButton_ann->setChecked(1);
    ui->radioButton_diff->setChecked(0);

    ui->label_monthPay1->setText("Ежемесячный платеж, руб");
    ui->label_monthPayValue1->setText("0");
    ui->label_monthPay2->setText("");
    ui->label_monthPayValue2->setText("");

    ui->label_overPayCredit->setText("0");
    ui->label_allPayCredit->setText("0");
    // удаляет таблицу
    ui->tableWidget_credit->setColumnCount(0);
    ui->tableWidget_credit->setRowCount(0);
}

void MainWindow::on_pushButton_creditGetResult_clicked() {
    double input_sum = ui->doubleSpinBox_sumCredit->value();
    int input_period = ui->spinBox_periodCredit->value();
    double input_procent = ui->doubleSpinBox_procentCredit->value();

    if (input_sum != 0.0 && input_period != 0 && input_procent != 0.0) {
        ui->tableWidget_credit->setColumnCount(4);
        ui->tableWidget_credit->setRowCount(input_period);
        ui->tableWidget_credit->setHorizontalHeaderLabels(QStringList() << "Сумма платежа, руб"
                                                                        << "Платеж по основному долгу, руб"
                                                                        << "Платеж по процентам, руб"
                                                                        << "Остаток долга, руб");

        int pay_method = 0;
        if (ui->radioButton_ann->isChecked()) {
            pay_method = 1;
        } else if (ui->radioButton_diff->isChecked()) {
            pay_method = 2;
        }

        QTableWidgetItem *itm;

        if (pay_method == 1) {
            controller_->SetCreditData(input_sum, input_period, input_procent, pay_method);
            controller_->CreditCalculation();
            std::vector<std::vector<double>> table_data = controller_->GetCreditTableData();

            for (int i = 0; i < input_period; i++) {
                itm = new QTableWidgetItem(QString::number(table_data[i][0], 'l', 2));
                ui->tableWidget_credit->setItem(i, 0, itm);
                itm = new QTableWidgetItem(QString::number(table_data[i][1], 'l', 2));
                ui->tableWidget_credit->setItem(i, 1, itm);
                itm = new QTableWidgetItem(QString::number(table_data[i][2], 'l', 2));
                ui->tableWidget_credit->setItem(i, 2, itm);
                itm = new QTableWidgetItem(QString::number(table_data[i][3], 'l', 2));
                ui->tableWidget_credit->setItem(i, 3, itm);
            }

            ui->label_monthPay1->setText("Ежемесячный платеж, руб");
            ui->label_monthPay2->setText("");
            ui->label_monthPayValue2->setText("");

            ui->label_monthPayValue1->setText(QString::number(controller_->GetCreditFixMonthPay(), 'l', 2));
            ui->label_overPayCredit->setText(QString::number(controller_->GetCreditOverPay(), 'l', 2));
            ui->label_allPayCredit->setText(QString::number(controller_->GetCreditAllPay(), 'l', 2));
        } else if (pay_method == 2) {
            controller_->SetCreditData(input_sum, input_period, input_procent, pay_method);
            controller_->CreditCalculation();
            std::vector<std::vector<double>> table_data = controller_->GetCreditTableData();

            for (int i = 0; i < input_period; i++) {
                itm = new QTableWidgetItem(QString::number(table_data[i][0], 'l', 2));
                ui->tableWidget_credit->setItem(i, 0, itm);
                itm = new QTableWidgetItem(QString::number(table_data[i][1], 'l', 2));
                ui->tableWidget_credit->setItem(i, 1, itm);
                itm = new QTableWidgetItem(QString::number(table_data[i][2], 'l', 2));
                ui->tableWidget_credit->setItem(i, 2, itm);
                itm = new QTableWidgetItem(QString::number(table_data[i][3], 'l', 2));
                ui->tableWidget_credit->setItem(i, 3, itm);
            }

            ui->label_monthPay1->setText("Первый платеж, руб");
            ui->label_monthPayValue1->setText(QString::number(controller_->GetCreditMonthPay1(), 'l', 2));

            ui->label_monthPay2->setText("Последний платеж, руб");
            ui->label_monthPayValue2->setText(QString::number(controller_->GetCreditMonthPayLast(), 'l', 2));
            ui->label_overPayCredit->setText(QString::number(controller_->GetCreditOverPay(), 'l', 2));
            ui->label_allPayCredit->setText(QString::number(controller_->GetCreditAllPay(), 'l', 2));
        }

    } else {
        ui->doubleSpinBox_sumCredit->setValue(input_sum);
        ui->spinBox_periodCredit->setValue(input_period);
        ui->doubleSpinBox_procentCredit->setValue(input_procent);
    }
}

void MainWindow::on_pushButton_depositCalc_clicked() {
    on_pushButton_clearDeposit_clicked();
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_comeBackToCalc3_clicked() {
    on_pushButton_clearDeposit_clicked();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_clearDeposit_clicked() {
    setDefaultDepositData();
    setHeaderLabelsDepositTables();
    setCurrentDateInDateEdit();
}

void MainWindow::setDefaultDepositData() {
    ui->doubleSpinBox_sumDeposit->setValue(0);
    ui->spinBox_periodDeposit->setValue(0);
    ui->doubleSpinBox_procentDeposit->setValue(0);
    ui->doubleSpinBox_procentNalog->setValue(0);
    ui->doubleSpinBox_procentNalogCb->setValue(0);

    ui->comboBox_periodPayment->setCurrentIndex(0);

    ui->checkBox_capitalization->setChecked(0);

    ui->label_profitDeposit->setText("0");
    ui->label_nalogPayDeposit->setText("0");
    ui->label_sumAccountInEndDeposit->setText("0");

    ui->tableWidget_popolnitDeposit->setColumnCount(0);
    ui->tableWidget_popolnitDeposit->setRowCount(0);
    ui->tableWidget_snyatDeposit->setColumnCount(0);
    ui->tableWidget_snyatDeposit->setRowCount(0);
}

void MainWindow::setCurrentDateInDateEdit() { ui->dateEdit_start->setDate(QDate().currentDate()); }

void MainWindow::setHeaderLabelsDepositTables() {
    ui->tableWidget_popolnitDeposit->setColumnCount(2);
    ui->tableWidget_snyatDeposit->setColumnCount(2);
    QStringList labelsAdd;
    labelsAdd << "Дата"
              << "Сумма пополнения";
    QStringList labelsSub;
    labelsSub << "Дата"
              << "Сумма снятия";
    ui->tableWidget_popolnitDeposit->setHorizontalHeaderLabels(labelsAdd);
    ui->tableWidget_snyatDeposit->setHorizontalHeaderLabels(labelsSub);
}

QVector<QPair<QString, QString>> MainWindow::GetDataFromTable(QTableWidget *table) {
    QVector<QPair<QString, QString>> res;
    for (int i = 0; i < table->rowCount(); i++) {
        res.push_back({table->item(i, 0)->text(), table->item(i, 1)->text()});
    }
    return res;
}

void MainWindow::InsertRowToTable(QTableWidget *table) {
    int i = table->rowCount();
    table->insertRow(i);
    QTableWidgetItem *item = new QTableWidgetItem();
    item->setData(Qt::DisplayRole, QDate().currentDate());
    table->setItem(i, 0, item);
    table->setItem(i, 1, new QTableWidgetItem("0"));
}

void MainWindow::DeleteRowFromTable(QTableWidget *table) {
    int i = table->rowCount();
    if (i == 1) {
        table->removeRow(0);
    } else if (i > 1) {
        table->removeRow(i - 1);
    }
}

void MainWindow::on_pushButton_popolnitDeposit_clicked() {
    InsertRowToTable(ui->tableWidget_popolnitDeposit);
}

void MainWindow::on_pushButton_snyatDeposit_clicked() { InsertRowToTable(ui->tableWidget_snyatDeposit); }

void MainWindow::on_pushButton_getResultDeposit_clicked() {
    double input_sum = ui->doubleSpinBox_sumDeposit->value();
    int input_period = ui->spinBox_periodDeposit->value();
    double input_procent = ui->doubleSpinBox_procentDeposit->value();
    double input_procentNalog = ui->doubleSpinBox_procentNalog->value();
    double input_procentNalogCb = ui->doubleSpinBox_procentNalogCb->value();
    int capitaliz = 0;
    if (ui->checkBox_capitalization->isChecked()) {
        capitaliz = 1;
    }
    QDate date_start = QDate(ui->dateEdit_start->date().year(), ui->dateEdit_start->date().month(),
                             ui->dateEdit_start->date().day());

    int period_payment = ui->comboBox_periodPayment->currentIndex();

    QVector<QPair<QString, QString>> poplnenie = GetDataFromTable(ui->tableWidget_popolnitDeposit);
    QVector<QPair<QString, QString>> snyatie = GetDataFromTable(ui->tableWidget_snyatDeposit);

    if (input_sum != 0.0 && input_period != 0 && input_procent != 0.0 && input_procentNalogCb != 0.0) {
        controller_->SetDepositData(input_sum, input_period, input_procent, input_procentNalog,
                                    input_procentNalogCb, date_start, period_payment, capitaliz, poplnenie,
                                    snyatie);
        controller_->DepositCalculation();

        ui->label_profitDeposit->setText(QString::number(controller_->GetDepositProfit(), 'l', 2));
        ui->label_nalogPayDeposit->setText(QString::number(controller_->GetDepositSumNalog(), 'l', 2));
        ui->label_sumAccountInEndDeposit->setText(QString::number(controller_->GetDepositSum(), 'l', 2));
    } else {
        ui->doubleSpinBox_sumDeposit->setValue(input_sum);
        ui->spinBox_periodDeposit->setValue(input_period);
        ui->doubleSpinBox_procentDeposit->setValue(input_procent);
        ui->doubleSpinBox_procentNalog->setValue(input_procentNalog);
        ui->doubleSpinBox_procentNalogCb->setValue(input_procentNalogCb);
    }
}

void MainWindow::on_pushButton_popolnitDeposit_2_clicked() {
    DeleteRowFromTable(ui->tableWidget_popolnitDeposit);
}

void MainWindow::on_pushButton_snyatDeposit_2_clicked() { DeleteRowFromTable(ui->tableWidget_snyatDeposit); }
