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
vector<bool> visited;
map<ll, vector<ll>> adj;

void dfs(ll u)
{
    visited[u]=true;
    for (auto v: adj[u]) if (visited[v]==false) dfs(v);
}

void solve()
{
    ll n; cin>>n;
    visited.resize(0);
    visited.resize(n+30, false);
    for (ll i=0; i<n; i++)
    {
        string s; cin>>s;
        for (auto c: s)
        {
            adj[i].push_back(n+c-'a');
            adj[n+c-'a'].push_back(i);
        }
    }

    ll ans=0;
    for (ll i=n; i<n+26; i++) if (visited[i]==false && !adj[i].empty()) 
    {
        ++ans;
        dfs(i);
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}