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
ll n, ans;
string s;
vector<ll> adj[2005], path;
ll dp[2005][2005];

ll calc(ll l, ll r)
{
    if (l>r) return 0;
    ll u=path[l], v=path[r];
    if (u==v)
    {
        dp[u][v]=1;
        return 1;
    }
    if (dp[u][v]!=-1) return dp[u][v];
    ll res=max(calc(l+1, r), calc(l, r-1));
    if (s[u]==s[v]) res=max(res, calc(l+1, r-1)+2);
    dp[u][v]=res;
    return res;
}

void dfs(ll u, ll par)
{
    path.push_back(u);
    bool leaf=true;
    for (auto v: adj[u]) if (v!=par)
    {
        leaf=false;
        dfs(v, u);
    }
    if (leaf==true) ans=max(ans, calc(0, path.size()-1));
    path.pop_back();
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) dp[i][j]=-1;
    cin>>s; s=" "+s;
    for (ll i=0; i<n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans=1;
    for (ll i=1; i<=n; i++) if (adj[i].size()==1)
    {
        path.clear();
        dfs(i, i);
    }
    cout<<ans<<endl;
    for (ll i=1; i<=n; i++) adj[i].clear();
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