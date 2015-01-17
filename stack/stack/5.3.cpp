#include <iostream>

using namespace std;

bool findNear(unsigned int source, unsigned int& smaller, unsigned int& bigger)
{
    bool ret = false;
    int firstZero = -1;
    int secondOne = -1;
    int firstOne = -1;
    unsigned int temp = source;
    int count = 0;
    while (firstOne == -1 || secondOne == -1 || firstZero == -1)
    {
        if (firstOne == -1)
        {
            if (temp % 2 == 1)
                firstOne = count;
        }
        else if (secondOne == -1)
        {
            if (temp % 2 == 1)
                secondOne = count;
        }
        if (firstZero == -1)
        {
            if (temp % 2 == 0)
                firstZero = count;
        }
        temp = temp >> 1;
        count++;
        if (count == 32)
            break;
    }
    if (firstOne == -1 || firstZero == -1 || secondOne == -1)
        return false;

    unsigned int zeroMask = 1 << firstZero;
    smaller = source | zeroMask;
    smaller = smaller & (~(1 << secondOne));
    bigger = source | zeroMask;
    bigger = bigger & (~(1 << firstOne));
    return true;
}

int main()
{
    unsigned int first, second;
    unsigned int input = 5;
    findNear(input, first, second);

    cout << first << " " << second << endl;
    return 0;
}