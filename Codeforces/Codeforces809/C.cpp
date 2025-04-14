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
const ll mod = 1e9+7;
const ll inf = 1e9;

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    if (n%2==1)
    {
        ll ans=0;
        for (ll i=2; i<n; i+=2) ans+=max(0LL, max(a[i-1], a[i+1])+1-a[i]);
        cout<<ans<<endl;
        return;
    }
    
    ll chan[n+5], le[n+5];
    memset(chan, 0, sizeof(chan));
    memset(le, 0, sizeof(le));
    for (ll i=2; i<n; i+=2) chan[i]=chan[i-2]+max(0LL, max(a[i-1], a[i+1])+1-a[i]);
    for (ll i=n-1; i>=3; i-=2) le[i]=le[i+2]+max(0LL, max(a[i-1], a[i+1])+1-a[i]);
    // for (ll i=1; i<=n; i++) cout<<chan[i]<<" "; cout<<endl;
    // for (ll i=1; i<=n; i++) cout<<le[i]<<" "; cout<<endl;
    ll ans=min(chan[n-2], le[3]);
    for (ll i=2; i<n-3; i+=2) 
    {
        // if (chan[i]+le[i+3]<ans)
        // {
        //     cout<<i<<endl;
        //     ans=min(ans, chan[i]+le[i+3]);
        // }
        ans=min(ans, chan[i]+le[i+3]);
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