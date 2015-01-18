#include <iostream>
#include <string>
using namespace std;

char Roman[7] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };
int Base[7] = { 1000, 500, 100, 50, 10, 5, 1 };

string intToRoman(int num) 
{
    string roman;
    while (num >= Base[0])
    {
        roman.push_back(Roman[0]);
        num -= Base[0];
    }

    for (size_t i = 1; i <= 3; i++)
    {
        bool overHalf = false;
        if (num >= Base[i * 2 - 1])
        {
            overHalf = true;
            num -= Base[i * 2 - 1];
        }
        int repeat = 0;
        while (num >= Base[i * 2])
        {
            repeat++;
            num -= Base[i * 2];
        }
        if (repeat == 4)
        {
            roman.push_back(Roman[i * 2]);
            if (overHalf)
                roman.push_back(Roman[i * 2 - 2]);
            else
                roman.push_back(Roman[i * 2 - 1]);
            repeat = 0;
        }
        else
        {
            if (overHalf)
                roman.push_back(Roman[i * 2 - 1]);
            while (repeat > 0)
            {
                roman.push_back(Roman[i * 2]);
                repeat--;
            }
        }
    }
    return roman;
}

int main()
{
    cout << intToRoman(4) << endl;
    cout << intToRoman(1904) << endl;
    return 0;
}