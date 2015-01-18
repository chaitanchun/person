#include <iostream>
#include <cmath>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0)
        return false;
    for (int i = 0; i < ((int)log10(x) + 1) / 2; i++) 
        if (!((int)(x / pow(10, i)) % 10 == (int)(x / pow(10, (int)log10(x) - i)) % 10))
            return false;
    return true;
}
int main()
{
    return 0;
}