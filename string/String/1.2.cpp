#include <iostream>
using namespace std;

void reverse(char* str)
{
    char* tail = str;
    while (*(tail + 1) != '\n')
        tail = tail + 1; 

    char* start = str;
    char temp;
    while (start < tail)
    {
        temp = *start;
        *start = *tail;
        *tail = temp;
        start++;
        tail--;
    }
}

int main()
{
    char* s = "abcdefg\n";
    reverse(s);
    return 0;
}