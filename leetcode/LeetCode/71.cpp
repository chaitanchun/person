#include <iostream>
#include <string>
using namespace std;

string simplifyPath(string path) 
{
    string ret;
    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] != '/')
        {
            int start = i;
            while (path[++i] != '/');
            string folder = path.substr(start, i - start);
            if (folder == "..")
            {
                ret = ret.substr(0, ret.rfind('/'));
            }
            else if (folder != ".")
            {
                ret.push_back('/');
                ret.append(path.substr(start, i - start));
            }
            i--;
        }
    }
    if (ret == "")
        ret = "/";
    return ret;
}

int main()
{
    cout << simplifyPath("/home/") << endl;
    cout << simplifyPath("/a/./b/../../c/") << endl;
    cout << simplifyPath("/../") << endl;
    cout << simplifyPath("/home//foo/") << endl;
    return 0;
}