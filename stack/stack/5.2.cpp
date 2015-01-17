#include <iostream>

using namespace std;

int transform(unsigned int a, unsigned int b)
{
    int ret = 0;
    while (a != b)
    {
        if ((a & 1) != (b & 1))
            ret++;
        a >>= 1;
        b >>= 1;
    }
    return ret;
}

int main()
{
    cout << transform(5, 9) << endl;
    return 0;
}