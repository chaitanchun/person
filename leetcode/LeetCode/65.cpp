#include <iostream>
#include <string>
using namespace std;

bool isNumber(const char *s) 
{
    bool left = true;
    // ignore the space before start
    while (*s == ' ') s++;

    // There could be 1 '+'/'-' before the first number
    if (*s && (*s == '+' || *s == '-')) s++;

    // the first element could be . or number, (there must be a number before e, so e is not valid)
    if (*s == '.'){
        left = false;
    }
    else if (*s < 48 || *s > 57){
        return false;
    }
    else {
        while (*s >= 48 && *s <= 57) s++;
    }

    // after first step, all the number before . or e has been processed.
    // 3 cases, all the number is over; . ; e
    if (!*s || *s == ' '){}
    // there could be a '+'/'-' after e. But after that, the remaining number must be a positive integer (no ., no e, no +-).
    else if (*s == 'e'){
        s++;
        if (*s == '+' || *s == '-') s++;
        if (!*s || *s == ' ') return false;
        while (*s >= 48 && *s <= 57) s++;
    }
    // the dot is a little bit complicated
    // (1) The left or right part of . could be null, but not both (So I used bool left to record that).
    // (2) after dot, check if left is empty, if left is empty, then the right side must be a number.
    // (3) if left is not empty, then the right side could be a number with e. Repeat the case above.
    else if (*s == '.'){
        s++;
        if ((*s < 48 || *s > 57) && !left) return false;
        while (*s >= 48 && *s <= 57) s++;
        if (*s == 'e') {
            s++;
            if (*s == '+' || *s == '-') s++;
            if (!*s || *s == ' ') return false;
            while (*s >= 48 && *s <= 57) s++;
        }
    }
    // other case return false;
    else return false;

    // deal with the space after all the number
    while (*s && *s == ' ') s++;

    // Still not end? Goodbye!
    if (*s) return false;

    // Succeed.
    return true;

}


int main()
{
    return 0;
}