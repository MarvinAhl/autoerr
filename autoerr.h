#pragma once

#include <iostream>
#include <cmath>

class edouble
{
private:
    double value;
    double error;  // The uncertainty

public:
    // Constructors
    edouble();
    edouble(double value);
    edouble(double value, double error);

    // Overloaded member operators that propagate the uncertainty.
    edouble pow(edouble a);
    edouble sqrt();
    edouble exp();
    edouble log();
    edouble sin();
    edouble cos();
    edouble tan();

    // Overloaded non-member friend operators
    friend edouble operator+(edouble a, edouble b);
    friend edouble operator-(edouble a, edouble b);
    friend edouble operator*(edouble a, edouble b);
    friend edouble operator/(edouble a, edouble b);
    friend inline edouble pow(edouble a, edouble b);
    friend inline edouble sqrt(edouble a);
    friend inline edouble exp(edouble a);
    friend inline edouble log(edouble a);
    friend inline edouble sin(edouble a);
    friend inline edouble cos(edouble a);
    friend inline edouble tan(edouble a);

    friend std::ostream& operator<<(std::ostream& os, edouble a);
};

// Overloaded non-member operators that propagate the uncertainty.
edouble operator+(edouble a, edouble b);
edouble operator-(edouble a, edouble b);
edouble operator*(edouble a, edouble b);
edouble operator/(edouble a, edouble b);
inline edouble pow(edouble a, edouble b);
inline edouble sqrt(edouble a);
inline edouble exp(edouble a);
inline edouble log(edouble a);
inline edouble sin(edouble a);
inline edouble cos(edouble a);
inline edouble tan(edouble a);

std::ostream& operator<<(std::ostream& os, edouble a);