#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int compareVersion(string version1, string version2) 
{
    int dot1, dot2;
    string v1, v2;
    int i1, i2;
    do
    {
        dot1 = version1.find_first_of('.');
        dot2 = version2.find_first_of('.');
        v1 = version1.substr(0, dot1);
        v2 = version2.substr(0, dot2);
        i1 = stoi(v1);
        i2 = stoi(v2);
        if (i1 > i2)
            return 1;
        else if (i1 < i2)
            return -1;
        if (dot1 != string::npos)
            version1 = version1.substr(dot1 + 1);
        if (dot2 != string::npos)
            version2 = version2.substr(dot2 + 1);
    } while (dot1 != string::npos && dot2 != string::npos);
    if (dot1 == string::npos && dot2 == string::npos)
    {
        return 0;
    }
    else if (dot1 == string::npos)
    {
        do
        {
            dot2 = version2.find_first_of('.');
            v2 = version2.substr(0, dot2);
            i2 = stoi(v2);
            if (i2 > 0)
                return -1;
            if (dot2 != string::npos)
                version2 = version2.substr(dot2 + 1);
        } while (dot2 != string::npos);
        return 0;
    }
    else
    {
        do
        {
            dot1 = version1.find_first_of('.');
            v1 = version1.substr(0, dot1);
            i1 = stoi(v1);
            if (i1 > 0)
                return 1;
            if (dot1 != string::npos)
                version1 = version1.substr(dot1 + 1);
        } while (dot1 != string::npos);
        return 0;
    }
}

int main()
{
    return 0;
}