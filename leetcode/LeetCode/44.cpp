#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isMatch(const char *s, const char *p) 
{
    const int m = strlen(s);
    const int n = strlen(p);
    int star = count(p, p + n, '*');
    if (n - star > m) return false;
    vector<bool> prev(n + 1, false); 
    prev[0] = true;
    for (int j = 1; j <= n; j++)
        prev[j] = prev[j - 1] && p[j - 1] == '*';
    for (int i = 1; i <= m; i++) {
        vector<bool> cur(n + 1, false);
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                cur[j] = cur[j - 1] || prev[j];
            }
            else {
                cur[j] = prev[j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
            }
        }
        prev = cur;
    }
    return prev[n];
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