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
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
ll n, p, a[200005], id[200005], is_connected[200005], ans, remaining_edge;

bool comp(ll x, ll y)
{
    return a[x]<a[y];
}

struct DSU
{
    vector<ll> par, size;
    ll n, component;
    DSU(){}
    DSU(ll _n)
    {
        n=_n;
        component=_n;
        par.resize(n+5, 0);
        for (ll i=1; i<=n; i++) par[i]=i;
        size.resize(n+5, 1);
    }
    ll find(ll u)
    {
        if (u==par[u]) return u;
        return par[u]=find(par[u]);
        }
    bool merge(ll u, ll v)
    {
        u=find(u);
        v=find(v);
        if (u==v) return false;
        --component;
        if (size[u]<size[v]) swap(u, v);
        par[v]=u;
        size[u]+=size[v];
        return true;
    }
    bool same_component(ll u, ll v)
    {
        return find(u)==find(v);
    }
};

void solve()
{
    cin>>n>>p;
    for (ll i=1; i<=n; i++) cin>>a[i], id[i]=i;
    sort(id+1, id+n+1, comp);
    DSU dsu(n);
    for (ll i=1; i<=n; i++)
    {
        ll pos=id[i], val=a[pos], j;
        if (val>=p) break;
        j=pos-1;
        while (j>=1 && a[j]%a[pos]==0 && dsu.merge(pos, j)==true)
        {
            --j;
            ans+=val;
        }
        j=pos+1;
        while (j<=n && a[j]%a[pos]==0 && dsu.merge(pos, j)==true)
        {
            ++j;
            ans+=val;
        }
    }
    ans+=(dsu.component-1)*p;
    cout<<ans<<endl;
    ans=0;
    for (ll i=1; i<=n; i++) is_connected[i]=0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}