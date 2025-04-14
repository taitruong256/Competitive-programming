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
struct block {ll l, w, h, p, idx;};
vector<block> v;
ll n, m, dp[100005], par[100005];

struct fenwick2D
{
    vector<vector<ll>> bit;
    ll n, m;
    fenwick2D() {}
    fenwick2D(ll _n, ll _m)
    {
        n=_n; m=_m;
        bit.resize(n+5);
        for (ll i=0; i<=n; i++) bit[i].resize(m+5, 0);
    }
    void update(ll x, ll y, ll idx)
    {
        for (ll i=x; i<=n; i+=-i&i) 
            for (ll j=y; j<=m; j+=-j&j)
                if (dp[idx]>dp[bit[i][j]]) bit[i][j]=idx;
    }
    ll query(ll x, ll y)
    {
        ll ans=0;
        for (ll i=x; i>0; i-=-i&i)
            for (ll j=y; j>0; j-=-j&j)
                if (dp[bit[i][j]]>dp[ans]) ans=bit[i][j];
        return ans;
    }
};
fenwick2D ft(5000, 5000);

bool comp(block a, block b)
{
    if (a.h!=b.h) return a.h<b.h;
    if (a.l!=b.l) return a.l<b.l;
    return a.w<b.w;
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++)
    {
        ll l, w, h, p; cin>>l>>w>>h>>p;
        if (l<w) swap(l, w);
        v.push_back({l, w, h, p, i});
    }
    sort(v.begin(), v.end(), comp);
    for (auto [l, w, h, p, idx]: v)
    {
        par[idx]=ft.query(l, w);       
        dp[idx]=dp[par[idx]]+p;            
        ft.update(l, w, idx);
    }
    ll mx=0;
    for (ll i=1; i<=n; i++) if (dp[i]>dp[mx]) mx=i;
    cout<<dp[mx]<<endl;
    vector<ll> ans;
    while (mx>0)
    {
        ans.push_back(mx);
        mx=par[mx];
    }
    cout<<ans.size()<<endl;
    for (auto i: ans) cout<<i<<" ";
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