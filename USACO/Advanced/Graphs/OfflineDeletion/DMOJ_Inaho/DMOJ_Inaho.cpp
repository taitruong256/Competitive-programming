/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|     
      __|  |__              __|  |__                                         |_|  | |  | |       | |  
     |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
        |  |    _____   _     |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | |_| | | |_| | | |  | | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  |_| \____ |   |______| |______/  \_______/
                                                                        | |
                                                                      __/ |
                                                                     |___/  
                                        Pratice, practice, and practice
                                       Where is the bug, delete it there
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> par, size, stk;
    int n;
    void init(int _n)
    {
        n=_n;
        par.resize(n+5, 0);
        for (int i=1; i<=n; i++) par[i]=i;
        size.resize(n+5, 1);
    }
    int find(int u)
    {
        if (u==par[u]) return u;
        return find(par[u]);
        }
    bool merge(int u, int v)
    {
        u=find(u);
        v=find(v);
        if (u==v) return false;
        if (size[u]<size[v]) swap(u, v);
        par[v]=u;
        size[u]+=size[v];
        stk.push_back(v);
        return true;
    }
    bool same_component(int u, int v)
    {
        return find(u)==find(v);
    }
    void rollback(int t)
    {
        while (stk.size()>t)
        {
            int u=stk.back(); stk.pop_back();
            size[par[u]]-=size[u];
            par[u]=u;
        }
    }
};
DSU dsu;

void Init(int n)
{
    dsu.init(1e6);
}

void AddEdge(int u, int v)
{
    dsu.merge(u, v);
}

void RemoveLastEdge()
{
    assert(dsu.stk.size()>=1);
    dsu.rollback(dsu.stk.size()-1);
}

int GetSize(int u)
{
    return dsu.size[dsu.find(u)];
}
