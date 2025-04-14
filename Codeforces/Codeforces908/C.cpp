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
vector<ll> adj[200005], adj2[200005];
ll vis[200005];
bool chutrinh=false;
ll n, k, a[200005];

void dfs(ll u, ll par)
{ 
    vis[u]=true;
    for (auto v: adj2[u]) if (v!=par)
    {
        if (vis[v]==false) dfs(v, u);
        else chutrinh=true;
    }
}

void solve()
{
    cin>>n>>k;
    for (ll i=0; i<n; i++) cin>>a[i];
    for (ll i=0; i<n; i++) if (a[i]<=n)
    {
        if (a[i]<=i+1) adj[i+1-a[i]].push_back(a[i]);
        else adj[i+1+n-a[i]].push_back(a[i]);
    }
    for (ll i=0; i<n; i++)
    {
        for (auto j: adj[i]) 
        {
            adj2[i].push_back((i+j)%n);
            adj2[(i+j)%n].push_back(i);
        }
    }
    dfs(0, -1);
    if (chutrinh==true) cout<<"Yes\n";
    else cout<<"No\n";
    for (ll i=0; i<=n; i++) adj[i].clear();
    for (ll i=0; i<=n; i++) adj2[i].clear();
    for (ll i=0; i<=n; i++) vis[i]=false;
    chutrinh=false;
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