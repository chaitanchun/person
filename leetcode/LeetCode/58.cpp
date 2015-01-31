#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(const char *s) {
    string str(s);
    int index = -1;
    int lastchar = -1;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            if (lastchar != -1)
            {
                index = i;
                break;
            }
        }
        else 
        {
            if (lastchar == -1)
                lastchar = i;
        }
    }
    return (index == -1 && lastchar == -1) ? 0 : lastchar - index;
}

int main()
{
    
    cout << lengthOfLastWord("a") << endl;

    return 0;
}