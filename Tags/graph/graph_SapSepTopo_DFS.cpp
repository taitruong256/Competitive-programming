/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m; 
vector<ll> canh[5005], topo;
ll dau[5005];
bool kt=true;

void dfs(ll u)
{
    dau[u]=true;     
    for (auto v: canh[u]) 
    {
        if (dau[v]==false) dfs(v);
        else kt=false;
    }
    topo.push_back(u);
}

void solve()
{
    cin>>n>>m;
    memset(dau, false, sizeof(dau));
    for (ll i=1; i<=m; i++)
    {
        ll u, v; cin>>u>>v;
        canh[u].push_back(v);
    }
    for (ll i=1; i<=n; i++) if (dau[i]==false) dfs(i);
    reverse(topo.begin(), topo.end());
    for (auto i: topo) cout<<i<<" "; 
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