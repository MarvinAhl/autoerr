#include <iostream>
#include "autoerr.hpp"

int main(int argc, char *argv[])
{
    // Definition: (value, error)
    err::edouble a(9.9, 4.2);
    err::edouble b = {5, 2.3};

    // Some random example, uncertainty is computed automatically!
    err::edouble c = a * 0.5 + (3 + b) * err::sqrt(b).sin() / a;

    // Value and uncertainty can be accessed like this
    double mean = c.value;
    double std_dev = c.error;

    // Output works too, no input though
    std::cout << c << std::endl;

    return 0;
}