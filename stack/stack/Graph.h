#include <vector>
using namespace std;

class Gnode
{
public:
    Gnode(int newid);
    ~Gnode();
    int value;
    vector<int> adj;
    int id;
    bool visited;
};

Gnode::Gnode(int newid) : id(newid)
{
    visited = false;
    value = 0;
}

Gnode::~Gnode()
{
}