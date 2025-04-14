/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    map<ll, ll> won, cnt;
    for (ll i=0; i<n*(n-1)/2-1; i++)
    {
        ll x, y; cin>>x>>y;
        ++won[x];
        ++cnt[x];
        ++cnt[y];
    }
    ll u=0, v=0;
    for (ll i=1; i<=n; i++) 
        if (cnt[i]!=n-1)
        {
            if (u==0) u=i; else v=i;
        }
    if (won[u]>won[v]) cout<<u<<" "<<v;
    else cout<<v<<" "<<u;
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
