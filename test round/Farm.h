#ifndef FARM_H
#define FARM_H
#include<unordered_map>
#include<vector>
class Farm
{
private:
    std::unordered_map<std::string, int> mp1;
    std::unordered_map<std::string, double> mp2;
    int n, cnt;
    double tot;
    std::vector<Cow> v;
public:
    Farm(int n_) : n(n_) {cnt = 0; tot = 0;}
    void addCow(Cow c)
    {
        cnt++;
        mp1[c.name] = 0; mp2[c.name] = 0;
        v.push_back(c);
    }
    void supply(std::string s, int a)
    {
        mp1[s] += a;
    }
    void startMeal()
    {
        for(auto & it : v)
        {
            std::string x = it.name;
            int l = it.l, u = it.u, m = it.m;
            if(mp1[x] == 0)
            {
                mp2[x] = 0;
                continue;
            }
            if(mp1[x] >= u)
            {
                mp1[x] -= u;
                mp2[x] = m;
            }
            else if(mp1[x] < l)
            {
                mp1[x] = 0;
                mp2[x] = (m*1.0) / 2;
            }
            else
            {
                mp1[x] = 0;
                mp2[x] = m;
            }
        }
    }
    void produceMilk()
    {
        for(auto & it : mp2)
        {
            tot += it.second;
            it.second = 0;
        }
    }
    double getMilkProduction() {return tot;}
};

#endif