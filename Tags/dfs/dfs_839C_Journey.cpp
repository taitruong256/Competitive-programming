/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, vector<ll>> ke;
ll n;
double f[100005];

void dfs(ll u, ll parent)
{
    ll length=0;
    for (auto v: ke[u]) if (v!=parent) 
    {
        ++length;
        dfs(v, u);
        f[u]+=f[v];
    }
    if (length==0) return;
    f[u]=1+f[u]/length;
}

void solve()
{
    cin>>n;
    for (ll i=0; i<n-1; i++)
    {
        ll u, v; cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    memset(f, 0, sizeof(f));
    dfs(1, 0);
    printf("%.7f", f[1]);
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