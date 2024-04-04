#include <cmath>

#include "Model/model.h"
#include "gtest/gtest.h"

#define EPS 1e-7

TEST(mathematics, test1) {
    m3mpm::Calculator m;
    m.SetString("1.23+2.23");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (1.23 + 2.23), EPS);
}

TEST(mathematics, test2) {
    m3mpm::Calculator m;
    m.SetString("1.4356789-2.245");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (1.4356789 - 2.245), EPS);
}

TEST(mathematics, test3) {
    m3mpm::Calculator m;
    m.SetString("100.456");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (100.456), EPS);
}

TEST(mathematics, test4) {
    m3mpm::Calculator m;
    m.SetString("(100.456)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (100.456), EPS);
}

TEST(mathematics, test5) {
    m3mpm::Calculator m;
    m.SetString("2.1/(1.5+1.678)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (2.1 / (1.5 + 1.678)), EPS);
}

TEST(mathematics, test6) {
    m3mpm::Calculator m;
    m.SetString("2.7856*(5.345-2.345)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (2.7856 * (5.345 - 2.345)), EPS);
}

TEST(mathematics, test7) {
    m3mpm::Calculator m;
    m.SetString("2.25*(5.67-x)");
    m.SetX(2.543);
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (2.25 * (5.67 - 2.543)), EPS);
}

TEST(mathematics, test8) {
    m3mpm::Calculator m;
    m.SetString("(2^2)+(2^2)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (pow(2, 2) + pow(2, 2)), EPS);
}

TEST(mathematics, test9) {
    m3mpm::Calculator m;
    m.SetString("((((10.987))))");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (10.987), EPS);
}

TEST(mathematics, test10) {
    m3mpm::Calculator m;
    m.SetString("sqrt9");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (sqrt(9)), EPS);
}

TEST(mathematics, test11) {
    m3mpm::Calculator m;
    m.SetString("log10");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (log10(10)), EPS);
}

TEST(mathematics, test12) {
    m3mpm::Calculator m;
    m.SetString("ln2.718281828459045");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (log(2.718281828459045)), EPS);
}

TEST(mathematics, test13) {
    m3mpm::Calculator m;
    m.SetString("5.25-10.01");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (5.25 - 10.01), EPS);
}

TEST(mathematics, test14) {
    m3mpm::Calculator m;
    m.SetString("3.01*3.02");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (3.01 * 3.02), EPS);
}

TEST(mathematics, test15) {
    m3mpm::Calculator m;
    m.SetString("9.45/3.26");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (9.45 / 3.26), EPS);
}

TEST(mathematics, test16) {
    m3mpm::Calculator m;
    m.SetString("0*3");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (0 * 3), EPS);
}

TEST(mathematics, test17) {
    m3mpm::Calculator m;
    m.SetString("9.45/3.26");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (9.45 / 3.26), EPS);
}

TEST(mathematics, test18) {
    m3mpm::Calculator m;
    m.SetString("-0");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (0), EPS);
}

TEST(mathematics, test19) {
    m3mpm::Calculator m;
    m.SetString("sin(2.14/2.1)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (sin(2.14 / 2.1)), EPS);
}

TEST(mathematics, test20) {
    m3mpm::Calculator m;
    m.SetString("sin(0)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (sin(0)), EPS);
}

TEST(mathematics, test21) {
    m3mpm::Calculator m;
    m.SetString("-sin(2.14/2.1)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (-sin(2.14 / 2.1)), EPS);
}

TEST(mathematics, test22) {
    m3mpm::Calculator m;
    m.SetString("cos(2.14)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (cos(2.14)), EPS);
}

TEST(mathematics, test23) {
    m3mpm::Calculator m;
    m.SetString("cos(0)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (cos(0)), EPS);
}

TEST(mathematics, test24) {
    m3mpm::Calculator m;
    m.SetString("cos(2.14/2.1)+(10.01)*(-1.1)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (cos(2.14 / 2.1) + (10.01) * (-1.1)), EPS);
}

TEST(mathematics, test25) {
    m3mpm::Calculator m;
    m.SetString("cos(2.14/2.1)+(10.01)*(-1.1)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (cos(2.14 / 2.1) + (10.01) * (-1.1)), EPS);
}

TEST(mathematics, test26) {
    m3mpm::Calculator m;
    m.SetString("tan(0)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (tan(0)), EPS);
}

TEST(mathematics, test27) {
    m3mpm::Calculator m;
    m.SetString("tan(2.14/4.01)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (tan(2.14 / 4.01)), EPS);
}

TEST(mathematics, test28) {
    m3mpm::Calculator m;
    m.SetString("-tan(2.14/4.01)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (-tan(2.14 / 4.01)), EPS);
}

TEST(mathematics, test29) {
    m3mpm::Calculator m;
    m.SetString("asin(-0.91)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (asin(-0.91)), EPS);
}

TEST(mathematics, test30) {
    m3mpm::Calculator m;
    m.SetString("acos(0)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (acos(0)), EPS);
}

TEST(mathematics, test31) {
    m3mpm::Calculator m;
    m.SetString("atan(-1.01)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (atan(-1.01)), EPS);
}

TEST(mathematics, test32) {
    m3mpm::Calculator m;
    m.SetString("2^2^2^2");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (pow(2, pow(2, pow(2, 2)))), EPS);
}

TEST(mathematics, test33) {
    m3mpm::Calculator m;
    m.SetString("4+4*5-23^3/6");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (4 + 4 * 5 - pow(23, 3) / 6), EPS);
}

TEST(mathematics, test34) {
    m3mpm::Calculator m;
    m.SetString("3.56*4-0.7865/45.67+6");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (3.56 * 4 - 0.7865 / 45.67 + 6), EPS);
}

TEST(mathematics, test35) {
    m3mpm::Calculator m;
    m.SetString("(4+4)*5-23^3/5");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), ((4 + 4) * 5 - pow(23, 3) / 5), EPS);
}

TEST(mathematics, test36) {
    m3mpm::Calculator m;
    m.SetString("3.56*((4-0.7865)/45.67+6)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (3.56 * ((4 - 0.7865) / 45.67 + 6)), EPS);
}

TEST(mathematics, test37) {
    m3mpm::Calculator m;
    m.SetString("(3+4)*(sin(0.245))");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), ((3 + 4) * (sin(0.245))), EPS);
}

TEST(mathematics, test38) {
    m3mpm::Calculator m;
    m.SetString("6/cos(35)+(6-76)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (6 / cos(35) + (6 - 76)), EPS);
}

TEST(mathematics, test39) {
    m3mpm::Calculator m;
    m.SetString("4+4*(-4)-23^3/6");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (4 + 4 * (-4) - pow(23, 3) / 6), EPS);
}

TEST(mathematics, test40) {
    m3mpm::Calculator m;
    m.SetString("-6+9.8^4");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (-6 + pow(9.8, 4)), EPS);
}

TEST(mathematics, test41) {
    m3mpm::Calculator m;
    m.SetString("4+4*(+4)-22^4/7");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (4 + 4 * (+4) - pow(22, 4) / 7), EPS);
}

TEST(mathematics, test42) {
    m3mpm::Calculator m;
    m.SetString("4.76-(-11+5)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (4.76 - (-11 + 5)), EPS);
}

TEST(mathematics, test43) {
    m3mpm::Calculator m;
    m.SetString("10mod5");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (fmod(10, 5)), EPS);
}

TEST(mathematics, test44) {
    m3mpm::Calculator m;
    m.SetString("-9.43mod-6.3");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), fmod(-9.43, -6.3), EPS);
}

TEST(mathematics, test45) {
    m3mpm::Calculator m;
    m.SetString("-10.35mod-0.56");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), fmod(-10.35, -0.56), EPS);
}

TEST(mathematics, test46) {
    m3mpm::Calculator m;
    m.SetString("sin(+5+1.4)+sin(-3)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (sin(+5 + 1.4) + sin(-3)), EPS);
}

TEST(mathematics, test47) {
    m3mpm::Calculator m;
    m.SetString("sin(cos(4)+5)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (sin(cos(4) + 5)), EPS);
}

TEST(mathematics, test48) {
    m3mpm::Calculator m;
    m.SetString("sin(2.5)^4*cos(1.7)^-2");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (pow(sin(2.5), 4) * pow(cos(1.7), -2)), EPS);
}

TEST(mathematics, test49) {
    m3mpm::Calculator m;
    m.SetString("acos(1)+asin(1)+atan(1)+cos(1)+sin(1)+tan(1)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (acos(1) + asin(1) + atan(1) + cos(1) + sin(1) + tan(1)), EPS);
}

TEST(mathematics, test50) {
    m3mpm::Calculator m;
    m.SetString("atan(4^7-acos(0.326))+8.98");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (atan(pow(4, 7) - cos(0.326)) + 8.98), EPS);
}

TEST(mathematics, test51) {
    m3mpm::Calculator m;
    m.SetString("log(47)/ln(54)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (log10(47) / log(54)), EPS);
}

TEST(mathematics, test52) {
    m3mpm::Calculator m;
    m.SetString("-67*-ln(0.321)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (-67 * -log(0.321)), EPS);
}

TEST(mathematics, test53) {
    m3mpm::Calculator m;
    m.SetString("10/log(100)*(102+5.86)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (10 / log10(100) * (102 + 5.86)), EPS);
}

TEST(mathematics, test54) {
    m3mpm::Calculator m;
    m.SetString("cos(sqrt(ln(300)))");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (cos(sqrt(log(300)))), EPS);
}

TEST(mathematics, test55) {
    m3mpm::Calculator m;
    m.SetString("sqrt(x*x+x)*cos(cos(x))*sin(x*4)*tan(x)");
    m.SetX(76.89);
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (-302.844933), EPS);
}

TEST(mathematics, test56) {
    m3mpm::Calculator m;
    m.SetString("1+1.23e2");
    m.SetX(76.89);
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (1 + 1.23e2), EPS);
}

TEST(mathematics, test57) {
    m3mpm::Calculator m;
    m.SetString("-1+1.23e+2");
    m.SetX(76.89);
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (-1 + 1.23e+2), EPS);
}

TEST(mathematics, test58) {
    m3mpm::Calculator m;
    m.SetString("-1-1.23e-2");
    m.SetX(76.89);
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (-1 - 1.23e-2), EPS);
}

TEST(mathematics, test59) {
    m3mpm::Calculator m;
    m.SetString("+178547853787-1.235784758475389e+2");
    m.SetX(76.89);
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_NEAR(m.GetResult(), (+178547853787 - 1.235784758475389e+2), EPS);
}

TEST(infnan, test1) {
    m3mpm::Calculator m;
    m.SetString("1/0");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_DOUBLE_EQ(m.GetResult(), (INFINITY));
}

TEST(infnan, test2) {
    m3mpm::Calculator m;
    m.SetString("2mod0");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_TRUE(std::isnan(m.GetResult()));
}

TEST(infnan, test3) {
    m3mpm::Calculator m;
    m.SetString("log(-10)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_TRUE(std::isnan(m.GetResult()));
}

TEST(infnan, test4) {
    m3mpm::Calculator m;
    m.SetString("ln(-10)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_TRUE(std::isnan(m.GetResult()));
}

TEST(infnan, test5) {
    m3mpm::Calculator m;
    m.SetString("sqrt(-10)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_TRUE(std::isnan(m.GetResult()));
}

TEST(infnan, test6) {
    m3mpm::Calculator m;
    m.SetString("0^(-1)");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_DOUBLE_EQ(m.GetResult(), (INFINITY));
}

TEST(infnan, test7) {
    m3mpm::Calculator m;
    m.SetString("ln0");
    m.CreatePolishNotation();
    m.MakeCalculation();
    ASSERT_DOUBLE_EQ(m.GetResult(), (-INFINITY));
}

// TEST(checking, test1) {
//     m3mpm::Calculator m;
//     std::string str{
//         "-3mod3-4.0^8.0+sin(+2)+(-2cos(2.0)*(asin(cos(17.6)+2.023))*1.69+9.0*(12*"
//         "3-tan(456.0/78.0)*7.0))*tan(ln(18.0)/43.134)+7.0^+0.2+8.0/"
//         "9mod9+sqrt(4)-3mod3-4.0^8.0+sin(+2)+(-2cos(2.0)*(asin(cos(17.6)+2.023))*"
//         "1.69+9.0*(12*3-tan(456.0/78.0)*7.0))*tan(ln(18.0)/43.134)+7.0^+0.2+8.0/"
//         "9mod9+sqrt(4)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Length error: Input str is over 255 symbols");
//     }
// }

// TEST(checking, test2) {
//     m3mpm::Calculator m;
//     std::string str{"1+cos(1+"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Number of brackers error: Incorrect input");
//     }
// }

// TEST(checking, test3) {
//     m3mpm::Calculator m;
//     std::string str{"1+tyn(0.2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Sybmols error: Incorrect input");
//     }
// }

// TEST(checking, test4) {
//     m3mpm::Calculator m;
//     std::string str{"cs(0.2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Fuchtion's name error: Incorrect input");
//     }
// }

// TEST(checking, test5) {
//     m3mpm::Calculator m;
//     std::string str{"sn(0.2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Fuchtion's name error: Incorrect input");
//     }
// }

// TEST(checking, test6) {
//     m3mpm::Calculator m;
//     std::string str{"tn(0.2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Fuchtion's name error: Incorrect input");
//     }
// }

// TEST(checking, test7) {
//     m3mpm::Calculator m;
//     std::string str{"acs(0.2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Fuchtion's name error: Incorrect input");
//     }
// }

// TEST(checking, test8) {
//     m3mpm::Calculator m;
//     std::string str{"asn(0.2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Fuchtion's name error: Incorrect input");
//     }
// }

// TEST(checking, test9) {
//     m3mpm::Calculator m;
//     std::string str{"atnn(0.2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Fuchtion's name error: Incorrect input");
//     }
// }

// TEST(checking, test10) {
//     m3mpm::Calculator m;
//     std::string str{"sqt(4)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Fuchtion's name error: Incorrect input");
//     }
// }

// TEST(checking, test11) {
//     m3mpm::Calculator m;
//     std::string str{"l(4)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Fuchtion's name error: Incorrect input");
//     }
// }

// TEST(checking, test12) {
//     m3mpm::Calculator m;
//     std::string str{"lg(4)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Fuchtion's name error: Incorrect input");
//     }
// }

// TEST(checking, test13) {
//     m3mpm::Calculator m;
//     std::string str{"5md4"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Fuchtion's name error: Incorrect input");
//     }
// }

// TEST(checking, test14) {
//     m3mpm::Calculator m;
//     std::string str{")+(1-2"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Brackets error: Incorrect input");
//     }
// }

// TEST(checking, test15) {
//     m3mpm::Calculator m;
//     std::string str{"+1-2*()"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Brackets error: Incorrect input");
//     }
// }

// TEST(checking, test16) {
//     m3mpm::Calculator m;
//     std::string str{"+1-2*(x+sin)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Brackets error: Incorrect input");
//     }
// }

// TEST(checking, test17) {
//     m3mpm::Calculator m;
//     std::string str{"+1-2*(x+sin(1))9.56"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Brackets error: Incorrect input");
//     }
// }

// TEST(checking, test18) {
//     m3mpm::Calculator m;
//     std::string str{".1+1-2*(x+sin(1))"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Dots error: Incorrect input");
//     }
// }

// TEST(checking, test19) {
//     m3mpm::Calculator m;
//     std::string str{"1+1-2*x+sin(1.)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Dots error: Incorrect input");
//     }
// }

// TEST(checking, test20) {
//     m3mpm::Calculator m;
//     std::string str{"1+1-2*x.+sin(1)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Dots error: Incorrect input");
//     }
// }

// TEST(checking, test21) {
//     m3mpm::Calculator m;
//     std::string str{"(1+1-2*x).(+sin(1))"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Dots error: Incorrect input");
//     }
// }

// TEST(checking, test22) {
//     m3mpm::Calculator m;
//     std::string str{"(1+1-2*x)+(+sin(1...3))"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Dots error: Incorrect input");
//     }
// }

// TEST(checking, test23) {
//     m3mpm::Calculator m;
//     std::string str{"(1+1-2*x)+(+sin(1.3.3))"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Dots error: Incorrect input");
//     }
// }

// TEST(checking, test24) {
//     m3mpm::Calculator m;
//     std::string str{"1+1.3e2.1"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "exp error: Incorrect input");
//     }
// }

// TEST(checking, test25) {
//     m3mpm::Calculator m;
//     std::string str{"1+1.3e(2+1)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "exp error: Incorrect input");
//     }
// }

// TEST(checking, test26) {
//     m3mpm::Calculator m;
//     std::string str{"1+1.3e/2"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "exp error: Incorrect input");
//     }
// }

// TEST(checking, test27) {
//     m3mpm::Calculator m;
//     std::string str{"1+1.3emod3"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "exp error: Incorrect input");
//     }
// }

// TEST(checking, test28) {
//     m3mpm::Calculator m;
//     std::string str{"1+39843902984083901248908423904890238485495849e+409"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "exp size error: Incorrect input");
//     }
// }

// TEST(checking, test29) {
//     m3mpm::Calculator m;
//     std::string str{"1+2x2+4"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "x error: Incorrect input");
//     }
// }

// TEST(checking, test30) {
//     m3mpm::Calculator m;
//     std::string str{"1+xsin(0.2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "x error: Incorrect input");
//     }
// }

// TEST(checking, test31) {
//     m3mpm::Calculator m;
//     std::string str{"1+sin(0.2)+"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Symbol + or - error: Incorrect input");
//     }
// }

// TEST(checking, test32) {
//     m3mpm::Calculator m;
//     std::string str{"(1+sin(0.2)-)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Symbol + or - error: Incorrect input");
//     }
// }

// TEST(checking, test33) {
//     m3mpm::Calculator m;
//     std::string str{"(1+sin(0.2)-*2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Symbol + or - error: Incorrect input");
//     }
// }

// TEST(checking, test34) {
//     m3mpm::Calculator m;
//     std::string str{"(1+sin(0.2)-+2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Symbol + or - error: Incorrect input");
//     }
// }

// TEST(checking, test35) {
//     m3mpm::Calculator m;
//     std::string str{"(1+sin(0.2)**2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Symbol (*/^) error: Incorrect input");
//     }
// }

// TEST(checking, test36) {
//     m3mpm::Calculator m;
//     std::string str{"(1+sin(0.2)*2/)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "Symbol (*/^) error: Incorrect input");
//     }
// }

// TEST(checking, test37) {
//     m3mpm::Calculator m;
//     std::string str{"mod5+2"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "mod() error: Incorrect input");
//     }
// }

// TEST(checking, test38) {
//     m3mpm::Calculator m;
//     std::string str{"5*mod3+2"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "mod() error: Incorrect input");
//     }
// }

// TEST(checking, test39) {
//     m3mpm::Calculator m;
//     std::string str{"5*(mod3+2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "mod() error: Incorrect input");
//     }
// }

// TEST(checking, test40) {
//     m3mpm::Calculator m;
//     std::string str{"5*(4mod+2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "mod() error: Incorrect input");
//     }
// }

// TEST(checking, test41) {
//     m3mpm::Calculator m;
//     std::string str{"5*acos"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "acos() error: Incorrect input");
//     }
// }

// TEST(checking, test42) {
//     m3mpm::Calculator m;
//     std::string str{"asin*1"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "asin() error: Incorrect input");
//     }
// }

// TEST(checking, test43) {
//     m3mpm::Calculator m;
//     std::string str{"5+atan*1"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "atan() error: Incorrect input");
//     }
// }

// TEST(checking, test44) {
//     m3mpm::Calculator m;
//     std::string str{"5*cos"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "cos() error: Incorrect input");
//     }
// }

// TEST(checking, test45) {
//     m3mpm::Calculator m;
//     std::string str{"(5+2)+cos(1)+sin"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "sin() error: Incorrect input");
//     }
// }

// TEST(checking, test46) {
//     m3mpm::Calculator m;
//     std::string str{"(5+2)+cos(1)+05tan(0.2)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "tan() error: Incorrect input");
//     }
// }

// TEST(checking, test47) {
//     m3mpm::Calculator m;
//     std::string str{"(5+2)+cos(1)+05sqrt(4)"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "sqrt() error: Incorrect input");
//     }
// }

// TEST(checking, test48) {
//     m3mpm::Calculator m;
//     std::string str{"(5+2)+cos(1)+log"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "log() error: Incorrect input");
//     }
// }

// TEST(checking, test49) {
//     m3mpm::Calculator m;
//     std::string str{"(5+2)+cos(1)+ln/5"};
//     m.SetString(str);
//     try {
//         m.CheckInputStr();
//     } catch (const std::exception& e) {
//         ASSERT_EQ(m.GetError(), "ln() error: Incorrect input");
//     }
// }

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
