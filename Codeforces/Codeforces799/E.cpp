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
    ll n, s; cin>>n>>s;
    ll a[n+5], pref[n+5], ans=1e9;
    pref[0]=0;
    for (ll i=1; i<=n; i++) cin>>a[i]; 
    for (ll i=1; i<=n; i++) pref[i]=pref[i-1]+a[i];
    ll tong=0, l=1;
    for (ll r=1; r<=n; r++)
    {
        tong+=a[r];
        while (tong>s)
        {
            tong-=a[l];
            ++l;
        }
        if (tong==s) ans=min(ans, n-r+l-1);
    }
    if (ans==1e9) ans=-1;
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