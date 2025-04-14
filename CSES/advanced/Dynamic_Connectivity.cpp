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
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
 
struct DSU {
    ll num; vector<ll> par, sza, stk;
    void init(ll _n)
    {
        num=_n;
        par.resize(_n+5, 0);
        for (ll i=1; i<=_n; i++) par[i]=i;
        sza.resize(_n+5, 1);
        stk.clear();
    }

    int find(ll u) 
    { 
        if (u==par[u]) return u;
        return find(par[u]);
    }
    bool same(ll u, ll v) { return find(u) == find(v); }
    bool merge(ll u, ll v)
    {
        u=find(u);
        v=find(v);
        if (u==v) return false;
        if (sza[u]>sza[v]) swap(u, v);
        par[u]=v;
        sza[v]+=sza[u];
        num--;
        stk.push_back(u);
        return true;
    }
    bool same_component(ll u, ll v)
    {
        return find(u)==find(v);
    }
    void undo(ll t)
    {
        while (stk.size()>t)
        {
            ll u=stk.back();
            stk.pop_back();
            ++num;
            sza[par[u]]-=sza[u];
            par[u]=u;
        }
    }
};
 
vector<pair<ll, ll>> st[400005];
ll n, m, q, ans[100005];
DSU dsu;
 
void update(ll id, ll l, ll r, ll u, ll v, pair<ll, ll> edge)
{
    if (l>v || r<u) return;
    if (u<=l && r<=v)
    {  
        st[id].push_back(edge);
        return;
    }
    ll mid=(l+r)/2;
    update(id*2, l, mid, u, v, edge);
    update(id*2+1, mid+1, r, u, v, edge);
}
 
void dfs(ll id, ll l, ll r)
{
    ll t=dsu.stk.size();
    for (auto [u, v]: st[id]) dsu.merge(u, v);
    if (l==r) ans[l]=dsu.num;
    else 
    {
        ll mid=(l+r)/2;
        dfs(id*2, l, mid);
        dfs(id*2+1, mid+1, r);
    }
    dsu.undo(t);
}
 
void solve()
{
    cin>>n>>m>>q;  
    dsu.init(n);
    map<pair<ll, ll>, ll> pre;
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        if (u>v) swap(u, v);
        pre[{u, v}]=0;
    }
 
    for (ll i=1; i<=q; i++)
    {
        ll type, u, v; cin>>type>>u>>v;
        if (u>v) swap(u, v);
        if (type==1) pre[{u, v}]=i;
        else 
        {
            update(1, 0, q, pre[{u, v}], i-1, {u, v});
            pre.erase({u, v});
        }
    }
    for (auto [e, i]: pre) update(1, 0, q, i, q, e);
    dfs(1, 0, q);
    for (ll i=0; i<=q; i++) cout<<ans[i]<<" ";
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}