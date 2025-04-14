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
    ll n, m; cin>>n>>m;
    ll cnt[n+5];
    memset(cnt, 0, sizeof(cnt));
    for (ll i=1; i<=m; i++)
    {
        ll u, v; cin>>u>>v;
        if (u>v) swap(u, v);
        cnt[u]++;
    }

    ll ans=0;
    for (ll i=1; i<=n; i++) if (cnt[i]==0) ++ans;

    ll q; cin>>q;
    while (q--)
    {
        ll x; cin>>x;
        if (x==1)
        {
            ll u, v; cin>>u>>v;
            if (u>v) swap(u, v);
            if (cnt[u]==0) --ans;
            ++cnt[u];
        }
        else if (x==2)
        {
            ll u, v; cin>>u>>v;
            if (u>v) swap(u, v);
            if (cnt[u]==1) ++ans;
            --cnt[u];
        }
        else
            cout<<ans<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  //cin>>t;
    while (t--) solve();
    return 0;
}