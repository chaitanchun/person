#include <iostream>
#include <string>
#include <vector>
using namespace std;

string multiply(string num1, string num2) 
{
    if (num1 == "0" || num2 == "0")
        return "0";
    string ret;
    vector<string> sum;
    for (int i = num2.length() - 1; i >= 0; i--)
    {
        int cur = num2[i] - '0';
        string mul;
        int inc = 0;
        for (int k = num1.length() - 1; k >= 0; k--)
        {
            int temp = cur * (num1[k] - '0') + inc;
            string temps;
            temps.push_back('0' + temp % 10);
            mul = temps + mul;
            inc = temp / 10;
        }
        if (inc > 0)
        {
            string temps;
            temps.push_back('0' + inc);
            mul = temps + mul;
        }
        sum.push_back(mul);
    }
    int inc = 0;
    for (int i = 0; i < num1.length() + num2.length(); i++)
    {
        int temp = inc;
        int valid = false;
        for (int k = 0; k < num2.length(); k++)
        {
            if ((sum[k].length() - 1 - i + k) >= 0 && (sum[k].length() - 1 - i + k) < sum[k].length())
            {
                temp += sum[k][sum[k].length() - 1 - i + k] - '0';
                valid = true;
            }
        }
        if (valid || inc > 0)
        {
            string temps;
            temps.push_back('0' + temp % 10);
            ret = temps + ret;
            inc = temp / 10;
        }
    }
    if (inc > 0)
    {
        string temps;
        temps.push_back('0' + inc);
        ret = temps + ret;
    }
    return ret; 
}


int main()
{
    string num1 = "9";
    string num2 = "9";
    string ret = multiply(num1, num2);
    return 0;

}