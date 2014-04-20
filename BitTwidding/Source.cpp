#include <iostream>
#include <bitset>

using namespace std;

void swap(int& a, int& b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

#define NUMBER 100
void FindPrime()
{
    bitset<NUMBER + 1> flag;
    for (size_t i = 2; i <= NUMBER; i++)
    {
        if (flag.test(i))
            continue;

        for (size_t k = 2; i * k <= NUMBER; k++)
        {
            flag.set(i * k);
        }
    }

    for (size_t i = 1; i <= NUMBER; i++)
    {
        if (!flag.test(i))
            cout << i << " ";
    }
    cout << endl;
}

int main()
{
    //opposite sign
    int a = 8;
    int b = -1;
    bool sign = (a ^ b) < 0;
    swap(a, b);
    a = ~a;
    b = ~b;
    FindPrime();
    return 0;
}