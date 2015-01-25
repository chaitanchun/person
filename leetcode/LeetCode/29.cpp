#include <iostream>
#include <math.h>

using namespace std;

int divide(int dividend, int divisor) {
    typedef long long ll;
    int sign = dividend < 0 ^ divisor < 0 ? -1 : 1;
    ll ans = 0;
    ll n = abs((ll)dividend);
    ll d = abs((ll)divisor);

    // accumulate the inter value
    while (n >= d) {
        ll a = d;
        ll m = 1;
        while (a << 1 < n) {
            a <<= 1;
            m <<= 1;
        }
        ans += m;
        n = n - a;
    }

    if (sign < 0) ans = -ans;
    return ans > INT_MAX ? INT_MAX : ans < INT_MIN ? INT_MIN : ans;
}

int main()
{
    cout << divide(8, 2) << endl;
    return 0; 
}