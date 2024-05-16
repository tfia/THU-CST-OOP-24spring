#include <map>
using namespace std;

template <typename T>
class Container
{
public:
    map<pair<int, int>, T> mp;
    void insert(int x, int y, T id)
    {
        mp[make_pair(x, y)] = id;
    }
    T * find(int x, int y)
    {
        if(mp.find(make_pair(x, y)) != mp.end())
        {
            T * p = &mp[make_pair(x, y)];
            return p;
        }
        else return nullptr;
    }
};

struct D
{
    int main() {}
};

#define main main_hack