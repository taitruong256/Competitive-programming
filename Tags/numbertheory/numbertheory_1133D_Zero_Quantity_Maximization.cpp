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
    ll n; cin>>n;
    ll a[n+5], b[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) cin>>b[i];
    map<pair<ll, ll>, ll> cnt;
    ll d=0;
    for (ll i=1; i<=n; i++) 
    {
        if (a[i]==0 && b[i]==0) ++d;
        else if (a[i]!=0) ++cnt[{-b[i]/__gcd(b[i], a[i]), a[i]/__gcd(b[i], a[i])}];
    }
    ll ans=0;
    for (auto it: cnt) ans=max(ans, it.second);
    cout<<ans+d;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}