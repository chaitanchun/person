#include <iostream>
#include <climits>
using namespace std;

int atoi(const char *str) 
{
    if (str == "")
        return 0;
    int ret = 0;
    char* curr = const_cast<char*>(str);
    while (*curr == ' ' )
        curr++;
    int sign = 1;
    if (*curr == '-' || *curr == '+')
    {
        
        sign = *curr == '+' ? 1 : -1;
        curr++;
    }
    while (*curr != '\n')
    {
        if (*curr < '0' || *curr > '9')
            break;
        int val = sign * (*curr - '0');
        if (ret > INT_MAX / 10 || ret < INT_MIN / 10)
        {
            ret = sign == 1 ? INT_MAX : INT_MIN;
            break;
        }
        ret = ret * 10;
        if ((sign == 1 && ret > INT_MAX - val) || (sign == -1 && ret < INT_MIN - val))
        {
            ret = sign == 1 ? INT_MAX : INT_MIN;
            break;
        }
        ret += val;
        curr++;
    }
    return ret;
}

int main()
{
    cout << atoi("1") << endl;

    return 0;
}