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
    string a[n+5];
    for (ll i=0; i<n; i++) cin>>a[i];
    ll ans=1e9;
    for (ll i=0; i<n-1; i++)
        for (ll j=i+1; j<n; j++)
        {
            ll cnt=0;
            for (ll k=0; k<m; k++) cnt+=abs(a[i][k]-a[j][k]);
            ans=min(ans, cnt);
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