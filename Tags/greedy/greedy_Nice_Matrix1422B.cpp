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
    ll a[n+5][m+5];
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) cin>>a[i][j];
    
    ll ans=0;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++)
        {
            ll x=n-i+1, y=m-j+1;
            if (i>x || j>y) continue;

            vector<ll> now;
            now.push_back(a[i][j]);
            if (i<x) now.push_back(a[x][j]);
            if (j<y) now.push_back(a[i][y]);
            if (i<x && j<y) now.push_back(a[x][y]);

            sort(now.begin(), now.end());
            ll m=now[now.size()/2];
            for (auto it: now) ans+=abs(it-m);
        }
    
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  cin>>t;
    while (t--) solve();
    return 0;
}