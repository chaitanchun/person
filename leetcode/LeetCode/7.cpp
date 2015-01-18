#include <iostream>
#include <math.h>
#include <climits>
using namespace std;

int reverse(int x) 
{
    bool pos = x > 0 ? true : false;
    x = abs(x);
    int ret = 0;
    while (x != 0)
    {
        if (ret > INT_MAX / 10)
        {
            ret = 0;
            break;
        }
        ret = ret * 10;
        if (ret > INT_MAX - x % 10)
        {
            ret = 0;
            break;
        }  
        ret += x % 10;
        x = x / 10;
    }
    return pos ? ret : ret * -1;
}
    
int main()
{
    cout << reverse(-2147483412) << endl;
    cout << reverse(-123) << endl;
    return 0;
}