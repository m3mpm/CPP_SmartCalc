#ifndef SRC_CALCULATOR_EXCEPTION_H_
#define SRC_CALCULATOR_EXCEPTION_H_
#include <exception>
#include <string>

namespace m3mpm {
class MyException : public std::exception {
private:
    std::string str_error_;

public:
    explicit MyException(const std::string &str) : str_error_(str) {}
    ~MyException(){};
    std::string GetErorr() { return str_error_; }
};
}  // namespace m3mpm
#endif  // SRC_CALCULATOR_EXCEPTION_H_
