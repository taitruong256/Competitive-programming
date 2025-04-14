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
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    if (a[1]==1)
    {
        cout<<n+1<<" ";
        for (ll i=1; i<=n; i++) cout<<i<<" ";
        cout<<endl;
        return;
    }
    for (ll i=1; i<n; i++) if (a[i]==0 && a[i+1]==1)
    {
        for (ll j=1; j<=i; j++) cout<<j<<" ";
        cout<<n+1<<" ";
        for (ll j=i+1; j<=n; j++) cout<<j<<" ";
        cout<<endl;
        return;
    }
    for (ll i=1; i<=n; i++) cout<<i<<" ";
    cout<<n+1<<endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}