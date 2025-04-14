/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const ll mod = 1e9+7;
const ll inf = 1e9;
ll n, m; 
vector<ll> adj[100005];
vector<ll> in, dp;

void solve()
{
    cin>>n>>m;
    in.resize(0); in.resize(n+5, 0);
    dp.resize(0); dp.resize(n+5, 0); dp[1]=1; 
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        ++in[v];
    }   

    queue<ll> q;
    for (ll i=1; i<=n; i++) if (in[i]==0) q.push(i);
    while (!q.empty())
    {
        ll u=q.front(); q.pop();
        for (auto v: adj[u])
        {
            dp[v]=(dp[v]+dp[u])%mod;
            --in[v];
            if (in[v]==0) q.push(v);
        }
    }
    cout<<dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}