
#include <iostream>
#include "fruction.h"
using namespace std;
int main()
{
    Fruction a(1, 2);
    Fruction b(3, 2);
    Fruction c;
    b = b + a;
    cout << b;
}
