/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

void solve()
{
    ll n, m; cin>>n>>m;
    char a[10][10];
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) cin>>a[i][j];
    
    ll x=0, y=0;
    for (ll i=1; i<=n; i++)
    {
        for (ll j=1; j<=m; j++) if (a[i][j]=='R')
        {
            x=i; 
            y=j;
            break;
        }
        if (x!=0 && y!=0) break;
    }

    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) if (a[i][j]=='R')
        {
            if (j<y)
            {
                cout<<"NO\n";
                return;
            }
        }
    
    cout<<"YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}