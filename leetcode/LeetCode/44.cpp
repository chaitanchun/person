#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool match(string target, string regExp, int min)
{

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