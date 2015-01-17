#include <iostream>

using namespace std;

unsigned int change(unsigned int value)
{
    unsigned int odd = (value & 0x5555) << 1;
    unsigned int even = (value & 0xaaaa) >> 1;
    return odd | even;
}

int main()
{
    cout << change(9) << endl;
    return 0;
}