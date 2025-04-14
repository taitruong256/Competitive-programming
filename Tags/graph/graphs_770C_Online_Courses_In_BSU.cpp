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
ll n, k;
map<ll, vector<ll>> adj;
vector<ll> color, a, ans;

void dfs(ll u)
{
    color[u]=1;
    for (auto v: adj[u]) 
    {
        if (color[v]==0) dfs(v);
        else if (color[v]==1)
        {
            cout<<-1;
            exit(0);
        }
    }
    color[u]=2;
    ans.push_back(u);
}

void solve()
{
    cin>>n>>k;
    color.resize(0); color.resize(n+5, 0);
    a.resize(0); a.resize(n+5);
    for (ll i=1; i<=k; i++) cin>>a[i];
    for (ll i=1; i<=n; i++)
    {
        ll t; cin>>t;
        for (ll j=1; j<=t; j++)
        {
            ll x; cin>>x;
            adj[i].push_back(x);
        }
    }
    for (ll i=1; i<=k; i++) if (color[a[i]]==0) dfs(a[i]);
    cout<<ans.size()<<endl;
    for (auto it: ans) cout<<it<<" ";
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