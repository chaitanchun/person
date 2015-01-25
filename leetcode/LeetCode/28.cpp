#include <iostream>
#include <string>
using namespace std;

int strStr(char *haystack, char *needle) {
    int index = -1;
    string h(haystack);
    string n(needle);
    if (h.length() < n.length())
        return index;
    for (size_t i = 0; i <= h.length() - n.length(); i++)
    {
        if (h.substr(i, n.length()) == n)
        {
            index = i;
            break;
        }
    }
    return index;
}

int main()
{
    cout << strStr("aaa", "a") << endl;
    return 0;
}