#include "autoerr.hpp"

namespace err {

inline double sqr(double a) { return a * a; }  // Square utility

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

edouble edouble::pow(const edouble& a)
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

edouble operator+(const edouble& a, const edouble& b)
{
    double value = a.value + b.value;
    double error = std::sqrt(sqr(a.error) + sqr(b.error));
    return edouble(value, error);
}

edouble operator-(const edouble& a, const edouble& b)
{
    double value = a.value - b.value;
    double error = std::sqrt(sqr(a.error) + sqr(b.error));
    return edouble(value, error);
}

edouble operator*(const edouble& a, const edouble& b)
{
    double value = a.value * b.value;
    double error = std::sqrt(sqr(b.value * a.error) + sqr(a.value * b.error));
    return edouble(value, error);
}

edouble operator/(const edouble& a, const edouble& b)
{
    double value = a.value / b.value;
    double error = std::sqrt(sqr(a.error / b.value) + sqr(a.value * b.error / sqr(b.value)));
    return edouble(value, error);
}

std::ostream& operator<<(std::ostream& os, const edouble& a)
{
    os << a.value << " +- " << a.error;
    return os;
}

double edouble::abs_to_rel()
{
    return this->error / this->value;
}

double edouble::abs_to_rel(const double& abs_error)
{
    return abs_error / this->value;
}

double edouble::rel_to_abs(const double& rel_error)
{
    return rel_error * this->value;
}

}  // End namespace err