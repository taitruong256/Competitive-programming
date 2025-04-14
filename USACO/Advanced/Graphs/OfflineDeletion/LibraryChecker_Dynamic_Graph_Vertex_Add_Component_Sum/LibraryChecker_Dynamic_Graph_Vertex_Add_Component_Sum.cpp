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
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
ll n, q, a[300005];
vector<ll> qry[300005];
 
struct DynamicConnectOffline 
{
    struct DSU 
    {
        ll cnt; vector<ll> par, sza, stk, sum;
        void init(ll _n)
        {
            cnt=_n;
            par.resize(_n+5, 0);
            sum.resize(_n+5, 0);
            for (ll i=1; i<=_n; i++) par[i]=i, sum[i]=a[i];
            sza.resize(_n+5, 1);
            stk.clear();
        }
    
        int find(ll u) 
        { 
            if (u==par[u]) return u;
            return find(par[u]);
        }
 
        bool merge(ll u, ll v)
        {
            u=find(u);
            v=find(v);
            if (u==v) return false;
            if (sza[u]<sza[v]) swap(u, v);
            par[v]=u;
            sza[u]+=sza[v];
            sum[u]+=sum[v];
            cnt--;
            stk.push_back(v);
            return true;
        }
    
        void undo(ll t)
        {
            while (stk.size()>t)
            {
                ll u=stk.back();
                stk.pop_back();
                ++cnt;
                sum[par[u]]-=sum[u];
                sza[par[u]]-=sza[u];
                par[u]=u;
            }
        }
    };
 
    vector<ll> ans;
    vector<vector<pair<ll, ll>>> tree;
    ll q, cnt;
    DSU dsu;
 
    DynamicConnectOffline(){}
    DynamicConnectOffline(ll _n, ll _q)
    {
        q=_q;
        dsu.init(_n);
        tree.resize(4*_q+5); ans.resize(_q+5);
    }
 
    
 
    void update(ll id, ll l, ll r, ll u, ll v, pair<ll, ll> edge)
    {
        if (l>v || r<u) return;
        if (u<=l && r<=v)
        {  
            tree[id].push_back(edge);
            return;
        }
        ll mid=(l+r)/2;
        update(id*2, l, mid, u, v, edge);
        update(id*2+1, mid+1, r, u, v, edge);
    }
 
    void dfs(ll id, ll l, ll r)
    {
        ll t=dsu.stk.size();
        for (auto [u, v]: tree[id]) dsu.merge(u, v);
        if (l==r) ans[l]=dsu.cnt;
        else 
        {
            ll mid=(l+r)/2;
            dfs(id*2, l, mid);
            dfs(id*2+1, mid+1, r);
        }
        dsu.undo(t);
    }
};
 
void solve()
{
    map<pair<ll, ll>, ll> pre;
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    DynamicConnectOffline dc(n, q);      
    for (ll i=1; i<=q; i++)
    {
        ll type, u, v, x; cin>>type;
        if (type==0)
        {
            cin>>u>>v;
            if (u>v) swap(u, v);
            pre[{u, v}]=i;
        }
        else if (type==1)
        {
            cin>>u>>v;
            if (u>v) swap(u, v);
            dc.update(1, 0, q, pre[{u, v}], i-1, {u, v});
            pre.erase({u, v});
        }
        else if (type==2)
        {
            cin>>v>>x;
            dc.dsu.sum[dc.dsu.find(v)]+=x;
        }
        else 
        {
            cin>>v;
            qry[v].push_back(i);
        }
    }
    for (auto i: pre) dc.update(1, 0, q, i.second, q, i.first);
    dc.dfs(1, 0, q);
    for (ll i=0; i<=q; i++) cout<<dc.ans[i]<<" ";
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