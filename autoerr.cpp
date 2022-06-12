#include "autoerr.h"

// Utility
inline double sqr(double a)
{
    return a * a;
}

edouble::edouble()
{
    this->value = 0.;
    this->error = 0.;
}

edouble::edouble(double value)
{
    this->value = value;
    this->error = 0.;
}

edouble::edouble(double value, double error)
{
    this->value = value;
    this->error = error;
}

edouble edouble::pow(edouble a)
{
    double value = std::pow(this->value, a.value);
    double error = std::abs(value) * std::sqrt(sqr(a.value * this->error / this->value) + sqr(std::log(this->value) * a.error));
    return edouble(value, error);
}

edouble edouble::sqrt()
{
    double value = std::sqrt(this->value);
    double error = std::abs(this->error / 2 / value);
    return edouble(value, error);
}

edouble edouble::exp()
{
    double value = std::exp(this->value);
    double error = std::abs(value * this->error);
    return edouble(value, error);
}

edouble edouble::log()
{
    double value = std::log(this->value);
    double error = std::abs(this->error / this->value);
    return edouble(value, error);
}

edouble edouble::sin()
{
    double value = std::sin(this->value);
    double error = std::abs(std::cos(this->value) * this->error);
    return edouble(value, error);
}

edouble edouble::cos()
{
    double value = std::cos(this->value);
    double error = std::abs(std::sin(this->value) * this->error);
    return edouble(value, error);
}

edouble edouble::tan()
{
    return this->sin() / this->cos();
}

edouble operator+(edouble a, edouble b)
{
    double value = a.value + b.value;
    double error = std::sqrt(sqr(a.error) + sqr(b.error));
    return edouble(value, error);
}

edouble operator-(edouble a, edouble b)
{
    double value = a.value - b.value;
    double error = std::sqrt(sqr(a.error) + sqr(b.error));
    return edouble(value, error);
}

edouble operator*(edouble a, edouble b)
{
    double value = a.value * b.value;
    double error = std::sqrt(sqr(b.value * a.error) + sqr(a.value * b.error));
    return edouble(value, error);
}

edouble operator/(edouble a, edouble b)
{
    double value = a.value / b.value;
    double error = std::sqrt(sqr(a.error / b.value) + sqr(a.value * b.error / sqr(b.value)));
    return edouble(value, error);
}

inline edouble pow(edouble a, edouble b)
{
    return a.pow(b);
}

inline edouble sqrt(edouble a)
{
    return a.sqrt();
}

inline edouble exp(edouble a)
{
    return a.exp();
}

inline edouble log(edouble a)
{
    return a.exp();
}

inline edouble sin(edouble a)
{
    return a.sin();
}

inline edouble cos(edouble a)
{
    return a.cos();
}

inline edouble tan(edouble a)
{
    return a.tan();
}

std::ostream& operator<<(std::ostream& os, edouble a)
{
    os << a.value << "+-" << a.error;
    return os;
}