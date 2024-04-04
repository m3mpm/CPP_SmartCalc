#include "model.h"

namespace m3mpm {
Calculator::Calculator() {}
Calculator::~Calculator() {}

void Calculator::SetString(std::string input_str) { str_ = input_str; }
void Calculator::SetX(double input_x) { x_ = input_x; }

double Calculator::GetResult() { return result_; }
std::string Calculator::GetError() { return str_error_; }
double Calculator::GetX() { return x_; }

void Calculator::CheckInputStr() {
    CheckLengthInputStr();
    CheckNumberBrackets();
    CheckCorrectSymbols();
    CheckFunctionName();
    CheckBrackets();
    CheckDots();
    CheckExpFormat();
    CheckExpSize();
    CheckX();
    CheckPlusMinus();
    CheckMultiDivExpo();
    CheckMod();
    CheckFunctions();
}

void Calculator::CheckLengthInputStr() {
    if (str_.length() > 255) {
        str_error_ = "Length error: Input str is over 255 symbols";
        throw m3mpm::MyException(str_error_);
    }
}

void Calculator::CheckNumberBrackets() {
    int num_open = 0;
    int num_close = 0;
    char open = '(';
    char close = ')';
    for (size_t i = 0; i < str_.length(); i++) {
        if (str_[i] == open) num_open++;
        if (str_[i] == close) num_close++;
    }
    if (num_open != num_close) {
        str_error_ = "Number of brackers error: Incorrect input";
        throw m3mpm::MyException(str_error_);
    }
}

void Calculator::CheckCorrectSymbols() {
    for (size_t i = 0; i < str_.length(); i++) {
        if (kstr_correct_symbols_.find(str_[i]) == std::string::npos) {
            str_error_ = "Sybmols error: Incorrect input";
            throw m3mpm::MyException(str_error_);
        }
    }
}

void Calculator::CheckFunctionName() {
    bool res = true;
    size_t i = 0;
    while (i < str_.length() && res) {
        if (isalpha(str_[i]) && str_[i] != 'e' && str_[i] != 'x') {
            res = false;
            std::string tmp;
            while (isalpha(str_[i])) {
                tmp.push_back(str_[i]);
                i++;
            }
            if (tmp.compare("cos") == 0) {
                res = true;
            } else if (tmp.compare("sin") == 0) {
                res = true;
            } else if (tmp.compare("tan") == 0) {
                res = true;
            } else if (tmp.compare("acos") == 0) {
                res = true;
            } else if (tmp.compare("asin") == 0) {
                res = true;
            } else if (tmp.compare("atan") == 0) {
                res = true;
            } else if (tmp.compare("sqrt") == 0) {
                res = true;
            } else if (tmp.compare("ln") == 0) {
                res = true;
            } else if (tmp.compare("log") == 0) {
                res = true;
            } else if (tmp.compare("mod") == 0) {
                res = true;
            }
            tmp.clear();
        } else {
            i++;
        }
    }
    if (res == false) {
        str_error_ = "Fuchtion's name error: Incorrect input";
        throw m3mpm::MyException(str_error_);
    }
}

void Calculator::CheckBrackets() {
    std::regex rgx("^\\)|\\($|[0-9]\\(|\\)[0-9a-ln-zA-Z]|\\)\\(|\\(\\)|[a-wy-zA-Z]\\)");
    std::smatch m;
    std::regex_search(str_, m, rgx);
    if (!m.empty()) {
        str_error_ = "Brackets error: Incorrect input";
        throw m3mpm::MyException(str_error_);
    }
}

void Calculator::CheckDots() {
    std::regex rgx(
        "^\\.|\\.$|[a-zA-Z]\\.|\\.[a-zA-Z]|\\)\\.\\(|\\(\\.|\\.\\)|[0-9]\\.{2,}|"
        "[0-9]+\\.+[0-9]+\\.+|\\.+[0-9]+\\.+|[0-9]+\\.[^0-9]|[^0-9]\\.[0-9]");
    std::smatch m;
    std::regex_search(str_, m, rgx);
    if (!m.empty()) {
        str_error_ = "Dots error: Incorrect input";
        throw m3mpm::MyException(str_error_);
    }
}

void Calculator::CheckExpFormat() {
    std::regex rgx(
        "^e|e$|[^0-9]e|[0-9]+\\.[0-9]+\\.[0-9]e|e[\\(\\)\\*\\/"
        "\\^\\.]|e[a-zA-Z]|e[\\+?\\-][^0-9]"
        "e[\\+\\-][0-9]+\\.[0-9]+|e[0-9]+\\.[0-9]+");

    std::smatch m;
    std::regex_search(str_, m, rgx);
    if (!m.empty()) {
        str_error_ = "exp error: Incorrect input";
        throw m3mpm::MyException(str_error_);
    }
}

void Calculator::CheckExpSize() {
    const std::string s = str_;
    std::regex words_regex(
        "[0-9]+\\.[0-9]+e[+\\-][0-9]+|[0-9]+e[+\\-][0-9]+|"
        "[0-9]+\\.[0-9]+e[0-9]+|[0-9]+e[0-9]+");

    auto words_begin = std::sregex_iterator(s.begin(), s.end(), words_regex);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();

        try {
            double tmp = stod(match_str);
            if (tmp) {
                str_error_ = "exp size: Correct input";
            }
        } catch (const std::exception &e) {
            str_error_ = "exp size error: Incorrect input";
            throw m3mpm::MyException(str_error_);
        }
    }
}

void Calculator::CheckX() {
    std::regex rgx(
        "\\)x\\(|\\)x|x\\(|[a-ce-zA-Z]x|x[a-ln-zA-Z]|"
        "x(mOd)|(mOd)x|[0-9]x|x[0-9]|[0-9]+\\.x|x\\.[0-9]+");
    std::smatch m;
    std::regex_search(str_, m, rgx);
    if (!m.empty()) {
        str_error_ = "x error: Incorrect input";
        throw m3mpm::MyException(str_error_);
    }
}

void Calculator::CheckPlusMinus() {
    std::regex rgx(
        "[+\\-]\\)|[+\\-]$|[+\\-]\\*|[+\\-]\\^|[+\\-]\\/"
        "|\\+\\-|\\-\\+|\\+\\+|\\-\\-");
    std::smatch m;
    std::regex_search(str_, m, rgx);
    if (!m.empty()) {
        str_error_ = "Symbol + or - error: Incorrect input";
        throw m3mpm::MyException(str_error_);
    }
}

void Calculator::CheckMultiDivExpo() {
    std::regex rgx(
        "^[*\\^\\/]|[*\\^\\/]$|\\([*\\^\\/]|[*\\^\\/]\\)|"
        "[*\\^\\/]\\*|[*\\^\\/]\\/|[*\\^\\/]\\^");
    std::smatch m;
    std::regex_search(str_, m, rgx);
    if (!m.empty()) {
        str_error_ = "Symbol (*/^) error: Incorrect input";
        throw m3mpm::MyException(str_error_);
    }
}

void Calculator::CheckMod() {
    std::regex rgx(
        "^(mod)|(mod)$|\\((mod)|(mod)\\)|\\.(mod)|(mod)\\.|[a-wy-zA-Z](mod)|(mod)"
        "[a-wy-zA-Z]|[*\\^\\/](mod)|(mod)[*\\^\\/]");
    std::smatch m;
    std::regex_search(str_, m, rgx);
    if (!m.empty()) {
        str_error_ = "mod() error: Incorrect input";
        throw m3mpm::MyException(str_error_);
    }
}

void Calculator::CheckFunctions() {
    CheckAcos();
    CheckAsin();
    CheckAtan();
    CheckCos();
    CheckSin();
    CheckTan();
    CheckSqrt();
    CheckLog();
    CheckLn();
}

void Calculator::CheckAcos() {
    std::regex rgx(
        "(acos)$|\\)(acos)|(acos)\\)|\\.(acos)|(acos)\\.|[a-z](acos)|(acos)"
        "[a-wy-z]|(acos)[*\\^\\/]|[0-9](acos)");
    std::smatch m;
    std::regex_search(str_, m, rgx);
    if (!m.empty()) {
        str_error_ = "acos() error: Incorrect input";
        throw m3mpm::MyException(str_error_);
    }
}

void Calculator::CheckAsin() {
    std::regex rgx(
        "(asin)$|\\)(asin)|(asin)\\)|\\.(asin)|(asin)\\.|[a-z](asin)|(asin)"
        "[a-wy-z]|(asin)[*\\^\\/]|[0-9](asin)");
    std::smatch m;
    std::regex_search(str_, m, rgx);
    if (!m.empty()) {
        str_error_ = "asin() error: Incorrect input";
        throw m3mpm::MyException(str_error_);
    }
}

void Calculator::CheckAtan() {
    std::regex rgx(
        "(atan)$|\\)(atan)|(atan)\\)|\\.(atan)|(atan)\\.|[a-z](atan)|(atan)"
        "[a-wy-z]|(atan)[*\\^\\/]|[0-9](atan)");
    std::smatch m;
    std::regex_search(str_, m, rgx);
    if (!m.empty()) {
        str_error_ = "atan() error: Incorrect input";
        throw m3mpm::MyException(str_error_);
    }
}

void Calculator::CheckCos() {
    std::regex rgx(
        "(cos)$|\\)(cos)|(cos)\\)|\\.(cos)|(cos)\\.|[b-z](cos)|(cos)"
        "[a-wy-z]|(cos)[*\\^\\/]|[0-9](cos)");
    std::smatch m;
    std::regex_search(str_, m, rgx);
    if (!m.empty()) {
        str_error_ = "cos() error: Incorrect input";
        throw m3mpm::MyException(str_error_);
    }
}

void Calculator::CheckSin() {
    std::regex rgx(
        "(sin)$|\\)(sin)|(sin)\\)|\\.(sin)|(sin)\\.|[b-z](sin)|(sin)"
        "[a-wy-z]|(sin)[*\\^\\/]|[0-9](sin)");
    std::smatch m;
    std::regex_search(str_, m, rgx);
    if (!m.empty()) {
        str_error_ = "sin() error: Incorrect input";
        throw m3mpm::MyException(str_error_);
    }
}

void Calculator::CheckTan() {
    std::regex rgx(
        "(tan)$|\\)(tan)|(tan)\\)|\\.(tan)|(tan)\\.|[b-z](tan)|(tan)"
        "[a-wy-z]|(tan)[*\\^\\/]|[0-9](tan)");
    std::smatch m;
    std::regex_search(str_, m, rgx);
    if (!m.empty()) {
        str_error_ = "tan() error: Incorrect input";
        throw m3mpm::MyException(str_error_);
    }
}

void Calculator::CheckSqrt() {
    std::regex rgx(
        "(sqrt)$|\\)(sqrt)|(sqrt)\\)|\\.(sqrt)|(sqrt)\\.|[a-z](sqrt)|(sqrt)"
        "[a-wy-z]|(sqrt)[*\\^\\/]|[0-9](sqrt)");
    std::smatch m;
    std::regex_search(str_, m, rgx);
    if (!m.empty()) {
        str_error_ = "sqrt() error: Incorrect input";
        throw m3mpm::MyException(str_error_);
    }
}

void Calculator::CheckLog() {
    std::regex rgx(
        "(log)$|\\)(log)|(log)\\)|\\.(log)|(log)\\.|[a-z](log)|(log)"
        "[a-wy-z]|(log)[*\\^\\/]|[0-9](log)");
    std::smatch m;
    std::regex_search(str_, m, rgx);
    if (!m.empty()) {
        str_error_ = "log() error: Incorrect input";
        throw m3mpm::MyException(str_error_);
    }
}

void Calculator::CheckLn() {
    std::regex rgx(
        "(ln)$|\\)(ln)|(ln)\\)|\\.(ln)|(ln)\\.|[a-z](ln)|(ln)"
        "[a-wy-z]|(ln)[*\\^\\/]|[0-9](ln)");
    std::smatch m;
    std::regex_search(str_, m, rgx);
    if (!m.empty()) {
        str_error_ = "ln() error: Incorrect input";
        throw m3mpm::MyException(str_error_);
    }
}

void Calculator::RebuildString() {
    RenameFunctionsInString();
    RebuildUnaryPlusMinus();
}

void Calculator::RenameFunctionsInString() {
    RenameOneFuctionsInString("acos", "o");
    RenameOneFuctionsInString("asin", "i");
    RenameOneFuctionsInString("atan", "a");
    RenameOneFuctionsInString("cos", "c");
    RenameOneFuctionsInString("sin", "s");
    RenameOneFuctionsInString("tan", "t");
    RenameOneFuctionsInString("sqrt", "q");
    RenameOneFuctionsInString("ln", "n");
    RenameOneFuctionsInString("log", "g");
    RenameOneFuctionsInString("mod", "m");
}

void Calculator::RenameOneFuctionsInString(std::string fstr, std::string rstr) {
    size_t pos;
    while ((pos = str_.find(fstr)) != std::string::npos) {
        str_.replace(pos, fstr.length(), rstr);
    }
}

void Calculator::RebuildUnaryPlusMinus() {
    size_t i = 0;
    std::string u = "u";
    std::string p = "p";
    size_t l = 1;
    for (; i < str_.length();) {
        if (str_[i] == '-' || str_[i] == '+') {
            if (i == 0) {
                if (str_[i] == '-') {
                    str_.replace(i, l, u);
                    i++;
                } else if (str_[i] == '+') {
                    str_.replace(i, l, p);
                    i++;
                }
            } else if (str_[i - 1] == '(' || str_[i - 1] == 'o' || str_[i - 1] == 'i' || str_[i - 1] == 'a' ||
                       str_[i - 1] == 'c' || str_[i - 1] == 's' || str_[i - 1] == 't' || str_[i - 1] == 'q' ||
                       str_[i - 1] == 'n' || str_[i - 1] == 'g' || str_[i - 1] == 'm' || str_[i - 1] == '*' ||
                       str_[i - 1] == '/' || str_[i - 1] == '^') {
                if (str_[i] == '-') {
                    str_.replace(i, l, u);
                    i++;
                } else if (str_[i] == '+') {
                    str_.replace(i, l, p);
                    i++;
                }
            } else {
                i++;
            }
        } else {
            i++;
        }
    }
}

int Calculator::GetPriority(char ch) {
    int result = 0;
    if (ch == '(' || ch == ')') {
        result = 0;
    } else if (ch == '+' || ch == '-') {
        result = 1;
    } else if (ch == '*' || ch == '/' || ch == 'm') {
        result = 2;
    } else if (ch == 'c' || ch == 's' || ch == 't' || ch == 'o' || ch == 'i' || ch == 'a' || ch == 'q' ||
               ch == 'n' || ch == 'g') {
        result = 5;
    } else if (ch == '^') {
        result = 6;
    } else if (ch == 'u' || ch == 'p') {
        result = 7;
    }
    return result;
}

void Calculator::ProcessingStringIntoPolishNotation() {
    size_t str_len = str_.size();
    for (size_t i = 0; i < str_len; i++) {
        if (str_[i] >= '0' && str_[i] <= '9') {
            std::string tmp_str;
            while ((str_[i] >= '0' && str_[i] <= '9') || str_[i] == '.' || str_[i] == 'e') {
                if (str_[i] == 'e') {
                    tmp_str += str_[i];
                    i++;
                    if (str_[i] == '-' || str_[i] == '+') {
                        tmp_str += str_[i];
                        i++;
                    }
                } else {
                    tmp_str += str_[i];
                    i++;
                }
            }
            polish_.push_back(tmp_str);
            tmp_str.clear();
        }
        if (str_[i] == 'x') {
            polish_.push_back({str_[i]});
        }
        if (str_[i] == 'c' || str_[i] == 's' || str_[i] == 't' || str_[i] == 'o' || str_[i] == 'i' ||
            str_[i] == 'a' || str_[i] == 'q' || str_[i] == 'n' || str_[i] == 'g' || str_[i] == 'u' ||
            str_[i] == 'p') {
            save_operators_.push_back({str_[i]});
        }
        if (str_[i] == '(') {
            save_operators_.push_back({str_[i]});
        }
        if (str_[i] == ')') {
            while (save_operators_.back() != "(") {
                polish_.push_back(save_operators_.back());
                save_operators_.pop_back();
            }
            if (save_operators_.back() == "(") {
                save_operators_.pop_back();
            }
        }
        if (str_[i] == '+' || str_[i] == '-' || str_[i] == '*' || str_[i] == '/' || str_[i] == 'm') {
            if (!save_operators_.empty()) {
                int str_pr = GetPriority(str_[i]);
                int peek_op_pr = GetPriority(save_operators_.back()[0]);
                if (peek_op_pr >= str_pr) {
                    while (peek_op_pr >= str_pr && !save_operators_.empty()) {
                        polish_.push_back(save_operators_.back());
                        save_operators_.pop_back();
                        if (!save_operators_.empty()) {
                            peek_op_pr = GetPriority(save_operators_.back()[0]);
                        }
                    }
                }
            }
            save_operators_.push_back({str_[i]});
        }
        if (str_[i] == '^') {
            if (!save_operators_.empty()) {
                int str_pr = GetPriority(str_[i]);
                int peek_op_pr = GetPriority(save_operators_.back()[0]);
                if (peek_op_pr > str_pr || peek_op_pr == 5) {
                    while ((peek_op_pr > str_pr || peek_op_pr == 5) && !save_operators_.empty()) {
                        polish_.push_back(save_operators_.back());
                        save_operators_.pop_back();
                        if (!save_operators_.empty()) {
                            peek_op_pr = GetPriority(save_operators_.back()[0]);
                        }
                    }
                }
                if (peek_op_pr == str_pr) {
                    save_operators_.push_back({str_[i]});
                } else {
                    save_operators_.push_back({str_[i]});
                }
            } else {
                save_operators_.push_back({str_[i]});
            }
        }
    }
    while (!save_operators_.empty()) {
        polish_.push_back(save_operators_.back());
        save_operators_.pop_back();
    }
}

void Calculator::CreatePolishNotation() {
    RebuildString();
    ProcessingStringIntoPolishNotation();
}

double Calculator::GetNumber() {
    double num = numbers_.front();
    numbers_.pop_front();
    return num;
}

void Calculator::CalcUnaryMinus() {
    double num = GetNumber() * (-1);
    numbers_.push_front(num);
}

void Calculator::CalcUnaryPlus() {
    double num = GetNumber() * (1);
    numbers_.push_front(num);
}

void Calculator::CalcAdd() {
    double num2 = GetNumber();
    double num1 = GetNumber();
    numbers_.push_front(num1 + num2);
}

void Calculator::CalcSub() {
    double num2 = GetNumber();
    double num1 = GetNumber();
    numbers_.push_front(num1 - num2);
}

void Calculator::CalcMulti() {
    double num2 = GetNumber();
    double num1 = GetNumber();
    numbers_.push_front(num1 * num2);
}

void Calculator::CalcDiv() {
    double num2 = GetNumber();
    double num1 = GetNumber();
    numbers_.push_front(num1 / num2);
}

void Calculator::CalcMod() {
    double num2 = GetNumber();
    double num1 = GetNumber();
    numbers_.push_front(fmod(num1, num2));
}

void Calculator::CalcPow() {
    double num2 = GetNumber();
    double num1 = GetNumber();
    numbers_.push_front(pow(num1, num2));
}

void Calculator::CalcCos() {
    double num = GetNumber();
    numbers_.push_front(cos(num));
}

void Calculator::CalcSin() {
    double num = GetNumber();
    numbers_.push_front(sin(num));
}

void Calculator::CalcTan() {
    double num = GetNumber();
    numbers_.push_front(tan(num));
}

void Calculator::CalcAcos() {
    double num = GetNumber();
    numbers_.push_front(acos(num));
}

void Calculator::CalcAsin() {
    double num = GetNumber();
    numbers_.push_front(asin(num));
}

void Calculator::CalcAtan() {
    double num = GetNumber();
    numbers_.push_front(atan(num));
}

void Calculator::CalcSqrt() {
    double num = GetNumber();
    numbers_.push_front(sqrt(num));
}

void Calculator::CalcLog() {
    double num = GetNumber();
    numbers_.push_front(log10(num));
}

void Calculator::CalcLn() {
    double num = GetNumber();
    numbers_.push_front(log(num));
}

void Calculator::MakeCalculation() {
    for (auto it = polish_.cbegin(); it != polish_.cend(); ++it) {
        if (*it == "u" || *it == "p") {
            if (*it == "u") {
                CalcUnaryMinus();
            } else {
                CalcUnaryPlus();
            }
        } else if (*it == "+") {
            CalcAdd();
        } else if (*it == "-") {
            CalcSub();
        } else if (*it == "*") {
            CalcMulti();
        } else if (*it == "/") {
            CalcDiv();
        } else if (*it == "m") {
            CalcMod();
        } else if (*it == "^") {
            CalcPow();
        } else if (*it == "c") {
            CalcCos();
        } else if (*it == "s") {
            CalcSin();
        } else if (*it == "t") {
            CalcTan();
        } else if (*it == "o") {
            CalcAcos();
        } else if (*it == "i") {
            CalcAsin();
        } else if (*it == "a") {
            CalcAtan();
        } else if (*it == "q") {
            CalcSqrt();
        } else if (*it == "g") {
            CalcLog();
        } else if (*it == "n") {
            CalcLn();
        } else {
            if (*it == "x") {
                numbers_.push_front(x_);
            } else {
                numbers_.push_front(std::stod(*it));
            }
        }
    }
    if (!numbers_.empty()) {
        result_ = numbers_.front();
    }
}
}  // namespace m3mpm
