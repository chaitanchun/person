#include <iostream>
#include <sstream>
using namespace std;

string changeString(string const &str)
{
    string ret = "";
    unsigned int index;
    size_t find = str.find_last_not_of(" ");
    if (find == string::npos)
        return ret;
    for (index = 0; index <= find; index++)
    {
        if (str[index] != ' ')
            ret.push_back(str[index]);
        else
            ret += "%20";
    }
    return ret;
}

int main()
{
    string input;
    getline(cin, input);
    cout << changeString(input) << endl;
    return 0;
}