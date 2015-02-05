#include <iostream>
#include <math.h>
using namespace std;

double powpow(double x, int n)
{
    double ret = 1.0;
    long long nn = n;
    nn = abs(nn);
    while (nn > 0)
    {
        long long i = 1;
        double temp = x;
        while (i * 2 <= nn)
        {
            temp *= temp;
            i *= 2;
        }
        ret *= temp;
        nn -= i;
    }
    return n > 0 ? ret : 1 / ret;
}

int main()
{
    cout << powpow(1.0, 2147483647) << endl;
    cout << powpow(34.00515, -3) << endl;
    cout << powpow(2.0, 1) << endl;
    cout << powpow(2.0, 20) << endl;
    return 0;
}