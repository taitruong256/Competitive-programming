#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

void solve()
{
    ll m, n; cin>>m>>n;
    ll a[m][n];
    for (ll i=0; i<m; i++)
        for (ll j=0; j<n; j++) cin>>a[i][j];

    ll column[n], ans=1e9+5;
    memset(column, 0, sizeof(column));
    for (ll j=0; j<n; j++)
    {
        for (ll i=0; i<m; i++) if (a[i][j]>column[j]) column[j]=a[i][j];
        ans=min(ans, column[j]);
    }

    if (m<n) cout<<ans<<endl;
    else
    {
        ll mx=0;
        for (int i=0; i<m; i++)
        {
            sort(a[i], a[i]+n);
            mx=max(mx, a[i][n-2]);
        }
        ans=min(ans, mx);
        cout<<ans<<endl;
    }
}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}
