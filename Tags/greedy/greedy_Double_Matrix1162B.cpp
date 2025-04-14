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
    ll a[n+5][m+5], b[n+5][m+5];

    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));

    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) cin>>a[i][j];

    for (ll i=1; i<=n; i++)
    {
        for (ll j=1; j<=m; j++) 
        {
            cin>>b[i][j];
            if (a[i][j]>b[i][j]) swap(a[i][j], b[i][j]);
        }
    }

    bool ok=true;
    for (ll i=1; i<=n; i++)
    {
        for (ll j=1; j<=m; j++)
        {
            if (a[i][j]>=a[i][j+1] && j+1<=m) ok=false;
            if (a[i][j]>=a[i+1][j] && i+1<=n) ok=false;
            if (b[i][j]>=b[i][j+1] && j+1<=m) ok=false;
            if (b[i][j]>=b[i+1][j] && i+1<=n) ok=false;
        }
    }
    if (ok) cout<<"Possible";
    else cout<<"Impossible";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  //cin>>t;
    for (ll _=0; _<t; _++)
    {
        //cout<<"Test case "<<_<<endl;
        solve();
    }
    return 0;
}
