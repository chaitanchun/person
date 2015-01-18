#include <iostream>
#include <string>
using namespace std;
char Roman[7] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };
int Base[7] = { 1000, 500, 100, 50, 10, 5, 1 };
int romanToInt(string s) {
    int index = 0;
    int ret = 0;
    while (s[index] == Roman[0])
    {
        ret += Base[0];
        index++;
    }
    for (size_t i = 1; i <= 3; i++)
    {
        int value = 0;
        while (s[index] == Roman[i * 2 - 1] || s[index] == Roman[i * 2] || s[index] == Roman[i * 2 - 2])
        {
            if (s[index] == Roman[i * 2])
                value += Base[i * 2];
            else if (s[index] == Roman[i * 2 - 1])
            {
                if (value == Base[i * 2])
                    value = Base[i * 2 - 1] - Base[i * 2];
                else
                    value += Base[i * 2 - 1];
            }
            else
            {
                if (value == Base[i * 2])
                    value = Base[i * 2 - 2] - Base[i * 2];
            }
            index++;
        }
        ret += value;
    }
    return ret;
}

int main()
{
    cout << romanToInt("IV") << endl;
    cout << romanToInt("MCMIV") << endl;
    return 0;
}