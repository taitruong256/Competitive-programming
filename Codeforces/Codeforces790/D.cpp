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
    ll a[n+5][m+5];
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) cin>>a[i][j];
    
    ll ans=0;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++)
        {
            // cout<<"----"<<i<<" "<<j<<endl;
            ll x=i, y=j, now=0;
            while (x>=1 && y>=1) 
            {
                // cout<<x<<" "<<y<<endl;
                now+=a[x][y];
                --x;
                --y;
            }

            x=i+1, y=j+1;
            while (x<=n && y<=m) 
            {
                // cout<<x<<" "<<y<<endl;
                now+=a[x][y];
                ++x;
                ++y;
            }

            x=i+1, y=j-1;
            while (x<=n && y>=1) 
            {
                // cout<<x<<" "<<y<<endl;
                now+=a[x][y];
                ++x;
                --y;
            }

            x=i-1, y=j+1;
            while (x>=1 && y<=m) 
            {
                // cout<<x<<" "<<y<<endl;
                now+=a[x][y];
                --x;
                ++y;
            }
            // cout<<now<<endl;

            ans=max(ans, now);
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
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}