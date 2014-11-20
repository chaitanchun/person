#include <iostream>
#include <sstream>
using namespace std;

string compose(string const &str)
{
    string ret;
    size_t i = 0;
    
    while (i < str.length())
    {
        char current = str[i];
        ret.push_back(current);
        int num = 1;
        i++;
        while (i < str.length() && str[i] == current)
        {
            num++;
            i++;
        }
        ret += std::to_string(num);
    }

    return ret.length() < str.length() ? ret : str;
}

int main()
{
    string str;
    getline(cin, str);
    cout << compose(str) << endl;
    return 0;
}