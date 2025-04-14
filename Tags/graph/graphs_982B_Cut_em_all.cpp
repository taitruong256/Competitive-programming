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
ll n, ans=0;
map<ll, vector<ll>> adj;
vector<bool> visited;

ll dfs(ll u)
{
    visited[u]=true;
    ll s=0;
    for (auto v: adj[u]) if (visited[v]==false) 
    {
        s+=dfs(v);
    }    //cout<<u<<" "<<s<<endl;
    ans+=s%2;
    return s+1;
}

void solve()
{
    cin>>n;
    if (n%2==1)
    {
        cout<<-1;
        return;
    }
    for (ll i=0; i<n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    visited.resize(0);
    visited.resize(n+5);
    dfs(1);
    cout<<ans-1;
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