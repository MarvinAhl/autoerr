/*
 * Author: Marvin Ahlborn
 * 
 * This is a C++ Class capable of automatic propagation of uncertainty.
 * It is designed to work with measurements (value) and their
 * standard deviations (error). edouble can be used like double with
 * the supplied mathematical operations. Attention: The uncertainties will
 * only be accurate if there are no correlations between variables.
 * The Idea is taken from the similarly working automatic differentiation.
 */

#pragma once

#include <iostream>
#include <cmath>

namespace err {

class edouble
{
public:
    double value;
    double error;  // The uncertainty

    // Constructors
    edouble();
    edouble(double value);
    edouble(double value, double error);

    // Overloaded member operators that propagate the uncertainty
    edouble pow(const edouble& a);
    edouble sqrt();
    edouble exp();
    edouble log();
    edouble sin();
    edouble cos();
    edouble tan();

    // Overloaded non-member friend operators (friend is actually not necessary here)
    friend edouble operator+(const edouble& a, const edouble& b);
    friend edouble operator-(const edouble& a, const edouble& b);
    friend edouble operator*(const edouble& a, const edouble& b);
    friend edouble operator/(const edouble& a, const edouble& b);
    friend inline edouble pow(edouble a, edouble b);
    friend inline edouble sqrt(edouble a);
    friend inline edouble exp(edouble a);
    friend inline edouble log(edouble a);
    friend inline edouble sin(edouble a);
    friend inline edouble cos(edouble a);
    friend inline edouble tan(edouble a);

    friend std::ostream& operator<<(std::ostream& os, const edouble& a);

    // Conversion between relative and absolute errors
    double abs_to_rel();
    double abs_to_rel(const double& abs_error);
    double rel_to_abs(const double& rel_error);
    friend inline double abs_to_rel(const edouble& value, const double& abs_error);
    friend inline double rel_to_abs(const edouble& value, const double& rel_error);
};

// Overloaded non-member operators that propagate the uncertainty
edouble operator+(const edouble& a, const edouble& b);
edouble operator-(const edouble& a, const edouble& b);
edouble operator*(const edouble& a, const edouble& b);
edouble operator/(const edouble& a, const edouble& b);
inline edouble pow(edouble a, edouble b) { return a.pow(b); }
inline edouble sqrt(edouble a) { return a.sqrt(); }
inline edouble exp(edouble a) { return a.exp(); }
inline edouble log(edouble a) { return a.log(); }
inline edouble sin(edouble a) { return a.sin(); }
inline edouble cos(edouble a) { return a.cos(); }
inline edouble tan(edouble a) { return a.tan(); }

std::ostream& operator<<(std::ostream& os, const edouble& a);

// Conversion between relative and absolute errors
inline double abs_to_rel(const edouble& value, const double& abs_error) { return abs_error / value.value; }
inline double rel_to_abs(const edouble& value, const double& rel_error) { return rel_error * value.value; }

}  // End namespace err