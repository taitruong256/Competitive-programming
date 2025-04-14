/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
vector<ll> v[105];
bool visited[1105];

void dfs(ll x)
{
    visited[x]=true;
    for (auto it: v[x]) if (visited[it]==false) dfs(it);
}

void solve()
{
    cin>>n>>m;
    ll f=0;
    for (ll i=1; i<=n; i++)
    {
        ll k; cin>>k;
        if (k!=0) f=1;
        for (ll j=1; j<=k; j++) 
        {
            ll x; cin>>x;
            v[i].push_back(1000+x);
            v[1000+x].push_back(i);
        }
    }
    memset(visited, false, sizeof(visited));
    ll ans=0;
    for (ll i=1; i<=n; i++) if (visited[i]==false)
    {
        ++ans;
        dfs(i);
    }
    cout<<ans-f;
}
 
int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;
    while (t--) solve();
    return 0;
}
