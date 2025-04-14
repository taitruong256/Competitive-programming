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
ll n, d, a[200005], b[200005], par_d[200005];
vector<ll> adj[200005], stk;

void dfs1(ll u, ll p)
{
    if (stk.size()>=d) par_d[u]=stk[stk.size()-d];
    stk.push_back(u);
    for (auto v: adj[u]) if (v!=p) dfs1(v, u);
    stk.pop_back();
}

void dfs2(ll u, ll p)
{       
    for (auto v: adj[u]) if (v!=p)
    {
        dfs2(v, u);
        a[u]|=a[v];
        b[u]|=b[v];
    }
}

void solve()
{
    cin>>n>>d;
    for (ll i=0; i<n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);

    a[1]=b[1]=1;
    ll m1; cin>>m1;
    for (ll i=0; i<m1; i++)
    {
        ll x; cin>>x;
        a[x]=1;
        b[par_d[x]]=1;
    }
    ll m2; cin>>m2;
    for (ll i=0; i<m2; i++)
    {
        ll x; cin>>x;
        b[x]=1;
        a[par_d[x]]=1;
    }
  
    dfs2(1, 0);   
    ll ans=0;
    for (ll i=2; i<=n; i++) ans+=a[i]*2, ans+=b[i]*2;
    cout<<ans;
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