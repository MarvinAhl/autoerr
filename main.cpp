#include <iostream>
#include "autoerr.h"

using namespace std;

int main(int argc, char *argv[])
{
    edouble a(10, 4);
    edouble b = {5, 1};

    edouble c = a + 3 * b;

    cout << c << endl;
    return 0;
}