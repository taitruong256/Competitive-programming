/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll cnt[2];
vector<ll> v[100005];
bool visited[100005];

void dfs(ll x, ll color)
{
    ++cnt[color];
    visited[x]=true;
    for (auto it: v[x]) if (visited[it]==false) dfs(it, !color);
}

void solve()
{
    cin>>n;
    for (ll i=0; i<n-1; i++)
    {
        ll a, b; cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(visited, false, sizeof(visited));
    dfs(1, 0);

    cout<<cnt[0]*cnt[1]-(n-1);
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
