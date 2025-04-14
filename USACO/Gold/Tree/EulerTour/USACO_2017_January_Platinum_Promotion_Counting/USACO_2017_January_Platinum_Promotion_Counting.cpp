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
const ll inf = 1e18;
const ll mod = 1e9+7;

void setIO(string s)
{
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}

struct fenwick
{
    ll n; 
    vector<ll> bit;

    fenwick(){}
    fenwick(ll _n)
    {
        n=_n;
        bit.resize(n+5);
    }

    void update(ll idx, ll val)
    {
        for (ll i=idx; i<=n; i+=-i&i) bit[i]+=val;
    }

    ll query(ll idx)
    {
        ll sum=0;
        for (ll i=idx; i>0; i-=-i&i) sum+=bit[i];
        return sum;
    }

    ll getsum(ll l, ll r)
    {
        if (l>r) return 0;
        return query(r)-query(l-1);
    }
};

ll n, ans[100005], time_in[100005], time_out[100005], timer;
pair<ll, ll> p[100005];
vector<vector<ll>> adj(100005);

void dfs(ll u, ll par)
{
    time_in[u]=++timer;
    for (auto v: adj[u]) if (v!=par) dfs(v, u);
    time_out[u]=timer;
}   

void solve()
{
    setIO("promote");
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>p[i].first, p[i].second=i;
    for (ll i=2; i<=n; i++)
    {
        ll par; cin>>par;
        adj[i].push_back(par);
        adj[par].push_back(i);
    }
    sort(p+1, p+n+1, greater<pair<ll, ll>>());
    dfs(1, -1);
    fenwick ft(n);
    for (ll i=1; i<=n; i++)
    {
        ll u=p[i].second;
        ans[u]=ft.getsum(time_in[u], time_out[u]);
        ft.update(time_in[u], 1);
    }
    for (ll i=1; i<=n; i++) cout<<ans[i]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}