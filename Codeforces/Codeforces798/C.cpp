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
ll n;
map<ll, vector<ll>> ke;
vector<bool> visited;
vector<ll> dinhcon, dp;

void dfs(ll u)
{
    visited[u]=true;
    dinhcon[u]=1;
    for (auto v: ke[u]) if (visited[v]==false) 
    {
        dfs(v);
        dinhcon[u]+=dinhcon[v];
    }
}

void dfs2(ll u)
{
    visited[u]=true;
    vector<ll> nxt;
    for (auto v: ke[u]) if (visited[v]==false) 
    {
        dfs2(v);
        nxt.push_back(v);
    }
    if (nxt.size()==1) 
        dp[u]=dinhcon[nxt[0]]-1;
    else if (nxt.size()==2)
        for (ll i=0; i<2; i++) dp[u]=max(dp[u], dinhcon[nxt[i]]-1+dp[nxt[1-i]]);
}


void solve()
{
    cin>>n;
    for (auto it: ke) it.second.clear();
    ke.clear();
    for (ll i=1; i<n; i++) 
    {
        ll u, v; cin>>u>>v; 
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    visited.resize(0);
    visited.resize(n+5, false);
    dinhcon.resize(0);
    dinhcon.resize(n+5, 0);
    dp.resize(0);
    dp.resize(n+5, 0);
    dfs(1);
    visited.resize(0);
    visited.resize(n+5, false);
    dfs2(1);
    // for (ll i=1; i<=n; i++) cout<<dinhcon[i]<<" "; cout<<endl;    
    // for (ll i=1; i<=n; i++) cout<<dp[i]<<" "; cout<<endl;  
    cout<<dp[1]<<endl;  
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}