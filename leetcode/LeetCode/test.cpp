#include <iostream>
#include <unordered_set>
using namespace std;

class A {
public:
    A() : s("") {}
    friend bool eq(const A& a, const A& other);
    friend size_t hasher(const A& a);
protected:
    std::string s;
};

bool eq(const A& a, const A& other) {
    return a.s == other.s;
}
size_t hasher(const A& a) {
    return std::hash<std::string>()(a.s);
}


int main()
{

    using settype = std::unordered_set<A, decltype(hasher)*, decltype(eq)*>;
    settype us(hasher(A()), hasher, eq);


    return 0;
}