#ifndef SRC_CALCULATOR_MODEL_H_
#define SRC_CALCULATOR_MODEL_H_
#include <cmath>
#include <exception>
#include <iostream>
#include <limits>
#include <list>
#include <regex>
#include <string>

#include "myexception.h"

namespace m3mpm {
class Calculator {
public:
    Calculator();
    ~Calculator();

    void SetString(std::string);
    void SetX(double);
    double GetResult();
    std::string GetError();
    double GetX();

    void CheckInputStr();
    void CreatePolishNotation();
    void MakeCalculation();

private:
    const std::string kstr_correct_symbols_ = "0123456789+-*/^().xcosintaqrlgmde";

    std::string str_;
    std::string str_error_;
    double x_ = 0;
    double result_ = 0;

    std::list<std::string> save_operators_;
    std::list<std::string> polish_;
    std::list<double> numbers_;

    void CheckLengthInputStr();
    void CheckNumberBrackets();
    void CheckCorrectSymbols();
    void CheckFunctionName();
    void CheckBrackets();
    void CheckDots();
    void CheckExpFormat();
    void CheckExpSize();
    void CheckX();
    void CheckPlusMinus();
    void CheckMultiDivExpo();
    void CheckMod();
    void CheckFunctions();
    void CheckAcos();
    void CheckAsin();
    void CheckAtan();
    void CheckCos();
    void CheckSin();
    void CheckTan();
    void CheckSqrt();
    void CheckLog();
    void CheckLn();

    void RebuildString();
    void RenameFunctionsInString();
    void RenameOneFuctionsInString(std::string fstr, std::string rstr);
    void RebuildUnaryPlusMinus();
    int GetPriority(char ch);

    void ProcessingStringIntoPolishNotation();

    double GetNumber();
    void CalcUnaryMinus();
    void CalcUnaryPlus();
    void CalcAdd();
    void CalcSub();
    void CalcMulti();
    void CalcDiv();
    void CalcMod();
    void CalcPow();
    void CalcCos();
    void CalcSin();
    void CalcTan();
    void CalcAcos();
    void CalcAsin();
    void CalcAtan();
    void CalcSqrt();
    void CalcLog();
    void CalcLn();
};
}  // namespace m3mpm
#endif  // SRC_CALCULATOR_MODEL_H_
