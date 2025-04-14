/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve()
{
    ll n, k; cin>>n>>k;
    ll a[n+5], bit[32];
    memset(bit, 0, sizeof(bit));
    for (ll i=1; i<=n; i++) cin>>a[i];

    for (ll j=30; j>=0; j--)
        for (ll i=1; i<=n; i++) if (!(a[i]&(1LL<<j))) ++bit[j];
    
    ll ans=0;
    for (ll i=30; i>=0; i--) if (k>=bit[i]) ans|=(1LL<<i), k-=bit[i];
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}