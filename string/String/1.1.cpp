#include <iostream>
#include <string>
using namespace std;

bool allCharDiff(const string& str)
{
    bool hasChar[26];
    for (size_t i = 0; i < 26; i++)
        hasChar[i] = false;
    for (size_t i = 0; i < str.length(); i++)
    {
        int index = str[i] - 'a';
        if (index >= 0 && index < 26)
        {
            if (hasChar[index])
                return true;
            else
                hasChar[index] = true;
        }
        index = str[i] - 'A';
        if (index >= 0 && index < 26)
        {
            if (hasChar[index])
                return true;
            else
                hasChar[index] = true;
        }
    }
    return false;
}

int main()
{
    string str;
    cin >> str;
    if (allCharDiff(str))
        cout << "this string has the same char!" << endl;
    else
        cout << "this string doesn't have the same char!" << endl;
    return 0;
}