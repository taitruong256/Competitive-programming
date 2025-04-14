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
ll n, q, par[200005], d[200005];
string s;
vector<ll> adj[200005];

void dfs(ll u, ll p)
{
    for (auto v: adj[u]) if (v!=p) 
    {
        par[v]=u;
        dfs(v, u);
    }
}

ll bfs(ll u, string t)
{
    queue<ll> q;
    q.push(u);
    d[u]=0;
    ll ans=0;
    while (!q.empty())
    {
        ll u=q.front(); q.pop(); 
        if (s[u]!=t[d[u]]) continue;
        if (d[u]==t.size()-1) 
        {
            ++ans;
            continue;
        }
        for (ll v: adj[u]) if (v!=par[u])
        {
            q.push(v);
            d[v]=d[u]+1;
        }
    }
    return ans;
}

void solve()
{
    cin>>n>>q;
    cin>>s; s=" "+s;  
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    while (q--)
    {
        ll u; cin>>u;
        string t; cin>>t;
        cout<<bfs(u, t)<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("str.inp", "r", stdin);
    freopen("str.out", "w", stdout);
    solve();
    return 0;
}