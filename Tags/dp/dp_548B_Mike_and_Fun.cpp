/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, m, q; cin>>n>>m>>q;
    ll a[n+5][m+5];
    memset(a, -1, sizeof(a));
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) cin>>a[i][j];

    ll f[n+5];
    memset(f, 0, sizeof(f));
    for (ll i=1; i<=n; i++)
    {
        ll cnt=0, mx=0;
        for (ll j=1; j<=m+1; j++) 
            if (a[i][j]==1) ++cnt; 
            else mx=max(mx, cnt), cnt=0;
        f[i]=mx;
    }

    // for (ll i=1; i<=n; i++) cout<<f[i]<<" "; cout<<endl;
    while (q--)
    {
        ll x, y; cin>>x>>y;
        a[x][y]^=1;

        // for (ll i=1; i<=n; i++)
        // {
        //     for (ll j=1; j<=m; j++) cout<<a[i][j]<<" "; cout<<endl;
        // }

        ll cnt=0, mx=0;
        for (ll i=1; i<=m+1; i++)
            if (a[x][i]==1) ++cnt; 
            else mx=max(mx, cnt), cnt=0;  
        f[x]=mx; 
        //for (ll i=1; i<=n; i++) cout<<f[i]<<" "; cout<<endl<<endl;
        cout<<*max_element(f+1, f+n+1)<<endl;
    }
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