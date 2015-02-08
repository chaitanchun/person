#include <iostream>
#include <math.h>
using namespace std;
int sqrta(int x)
{
    if (x == 0)
        return 0;
    int a = 1;
    int b = x;
    while (a * 2 < b / 2)
    {
        a *= 2;
        b /= 2;
    }
    for (int i = a; i <= b; i++)
    {
        if (i * i == x)
            return i;
        else if (i > x / i)
            return i - 1;
    }
}

int main()
{
    cout << sqrta(2147483647) << endl;
    cout << sqrta(529) << endl;
    cout << sqrta(16) << endl;
    cout << sqrta(1) << endl;
    cout << sqrta(49) << endl;
    cout << sqrta(64) << endl;
    return 0;
}