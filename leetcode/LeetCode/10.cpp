#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isMatch(const char *s, const char *p) {
    string regExp(p);
    string target(s);
    if (regExp.size() == 0 && target.size() == 0)
        return true;

    if (regExp.size() == 0 && target.size() != 0)
        return false;

    bool bMatch = false;
    if (regExp.size() > 1 && regExp[1] == '*')
    {
        size_t i = 0;
        if (target[0] == regExp[0] || regExp[0] == '.')
        {
            for (; i < target.size() && (target[i] == target[0] || regExp[0] == '.'); i++)
            {
                bMatch = bMatch || isMatch((target.substr(i, target.size() - i)).c_str(), (regExp.substr(2, regExp.size() - 2).c_str()));
                if (bMatch)
                    return bMatch;
            }
        }
        bMatch = bMatch || isMatch((target.substr(i, target.size() - i)).c_str(), (regExp.substr(2, regExp.size() - 2).c_str()));
    }
    else
    {
        if (target.size() != 0 && (regExp[0] == target[0] || regExp[0] == '.'))
            bMatch = bMatch || isMatch((target.substr(1, target.size() - 1)).c_str(), (regExp.substr(1, regExp.size() - 1).c_str()));
    }
    return bMatch;
}


int main()
{
    cout << isMatch("aa", "a") << endl;
    cout << isMatch("aa", "aa") << endl;
    cout << isMatch("aaa", "aa") << endl;
    cout << isMatch("aa", "a*") << endl;
    cout << isMatch("ab", ".*") << endl;
    cout << isMatch("aabbbbaababbabababaabbbbabbabbaabbbabbbabaabbaaaababababbababbabbbbabaaabaaabaabbaaaabbbbabaaabbbbbabbbaabbbbbabaabababaaabaaababaababbaaabaabbabaababbabababaaababbabbabaabbbbabbbbabaabbaababaaabababbabb", "a*b*a*b*aaaa*abaaa**b*a***b*a*bb****ba*ba*b******a********a**baba*ab***a***bbba*b**a*b*ba*a*aaaa*ab**") << endl;
    return 0;
}