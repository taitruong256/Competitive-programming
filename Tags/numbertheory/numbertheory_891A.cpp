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
    ll a[n+5], cnt=0;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) if (a[i]==1) ++cnt;
    if (cnt>0)
    {
        cout<<n-cnt;
        return;
    }
    ll ans=1e18;
    for (ll i=1; i<=n; i++)
    {
        ll g=a[i];
        for (ll j=i+1; j<=n && g>1; j++) 
        {
            g=__gcd(g, a[j]);
            if (g==1) ans=min(ans, j-i);
        }
    }
    if (ans==1e18) cout<<-1;
    else cout<<ans+n-1;
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