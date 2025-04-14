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
ll n, p[305], ans[305];
set<ll> pos, value;
vector<ll> adj[305];
string A[305];
bool vis[305];

void dfs(ll u)
{
    vis[u]=true;
    pos.insert(u);
    value.insert(p[u]);
    for (auto v: adj[u]) if (vis[v]==false) dfs(v);
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>p[i];
    for (ll i=1; i<=n; i++)
    {
        cin>>A[i];
        A[i]=" "+A[i];
    }
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) if (A[i][j]=='1')
        {
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    for (ll i=1; i<=n; i++) if (vis[i]==false)
    {
        pos.clear(); value.clear();
        dfs(i);
        auto it=value.begin();
        for (auto p: pos)
        {
            ans[p]=*it;
            ++it;
        }
    }
    for (ll i=1; i<=n; i++) cout<<ans[i]<<" "; 
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