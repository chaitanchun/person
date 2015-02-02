#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool match(string target, string regExp, int min)
{
    if (regExp.size() == 0)
        return target.size() == 0 ? true : false;
    if (regExp.size() == 1)
    {
        if (regExp[0] == '*')
            return true;
        else
        {
            if (target.size() == 1 && (regExp[0] == target[0] || regExp[0] == '?'))
                return true;
            else
                return false;
        }
    }

    bool bMatch = false;
    if (regExp[0] == '*' && regExp.back() == '*')
    {
        for (int i = 0; i < target.size() - min + 1; i++)
        {
            if (regExp[1] == target[i] || regExp[1] == '?')
            {
                for (int k = i + min - 1; k < target.size(); k++)
                {
                    if (regExp[regExp.size() - 2] == target[k] || regExp[regExp.size() - 2] == '?')
                    {
                        if (match(target.substr(i, k - i + 1), regExp.substr(1, regExp.size() - 2), min))
                            return true;
                    }
                }
            }
        }
    }
    else
    {
        int i;
        for (i = 0; i < regExp.size() && regExp[i] != '*'; i++)
        {
            if (regExp[i] != target[i] && regExp[i] != '?')
                return false;
        }
        min -= i;
        regExp = regExp.substr(i, regExp.size() - i);
        target = target.substr(i, target.size() - i);
        for (i = 0; i < regExp.size() && regExp[regExp.size() - 1 - i] != '*'; i++)
        {
            int it = regExp.size() - 1 - i;
            if (regExp[it] != target[target.size() - 1 - i] && regExp[it] != '?')
                return false;
        }
        min -= i;
        regExp = regExp.substr(0, regExp.size() - i);
        target = target.substr(0, target.size() - i);
        bMatch = match(target, regExp, min);
    }
    return bMatch;
}

bool isMatch(const char *s, const char *p) 
{
    string target(s);
    string exp(p);
    string regExp;
    regExp.push_back(exp[0]);
    int num = regExp.back() != '*' ? 1 : 0;
    for (size_t i = 1; i < exp.size(); i++)
    {
        if (exp[i] != '*' || regExp.back() != '*')
        {
            regExp.push_back(exp[i]);
            if (regExp.back() != '*')
                num++;
        }
    }
    if (target.size() < num)
        return false;
    return match(target, regExp, num);
}

int main()
{
    cout << isMatch("abbbaaaaaaaabbbabaaabbabbbaabaabbbbaabaabbabaabbabbaabbbaabaabbabaabaabbbbaabbbaabaaababbbbabaaababbaaa", "ab**b*bb*ab**ab***b*abaa**b*a*aaa**bba*aa*a*abb*a*a") << endl;
    cout << isMatch("aaa", "*") << endl;
    cout << isMatch("aa", "a*") << endl;
    cout << isMatch("ab", "?*") << endl;
    cout << isMatch("bbbbbbbabbaabbabbbbaaabbabbabaaabbababbbabbbabaaabaabb", "b*b*ab**ba*b**b***bba") << endl;
    cout << isMatch("aabbbbaababbabababaabbbbabbabbaabbbabbbabaabbaaaababababbababbabbbbabaaabaaabaabbaaaabbbbabaaabbbbbabbbaabbbbbabaabababaaabaaababaababbaaabaabbabaababbabababaaababbabbabaabbbbabbbbabaabbaababaaabababbabb", "a*b*a*b*aaaa*abaaa**b*a***b*a*bb****ba*ba*b******a********a**baba*ab***a***bbba*b**a*b*ba*a*aaaa*ab**") << endl;
    return 0;
}