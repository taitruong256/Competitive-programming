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
    ll n, x; cin>>n>>x;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];

    map<ll, ll> cnt;
    ll f[n+5];
    f[0]=0;
    for (ll i=1; i<=n; i++) f[i]=f[i-1]+a[i];
    for (ll i=1; i<=n; i++) ++cnt[f[i]];
    ll ans=0;
    for (ll i=0; i<=n; i++)
    {
        ans+=cnt[f[i]+x];
        --cnt[f[i]+x];
    }
    cout<<ans;
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
