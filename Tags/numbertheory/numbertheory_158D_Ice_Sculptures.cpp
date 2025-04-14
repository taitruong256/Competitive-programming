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
    ll ans=-1e18;
    for (ll i=1; i*i<=n; i++) if (n%i==0)
    {
        if (i>=3)
        {
            for (ll j=1; j<=n/i; j++) 
            {
                ll res=0;
                for (ll k=j; k<=n; k+=n/i) res+=a[k];
                ans=max(ans, res);
            }
        }
        if (n/i>=3)
        {
            for (ll j=1; j<=i; j++) 
            {
                ll res=0;
                for (ll k=j; k<=n; k+=i) res+=a[k];
                ans=max(ans, res);
            }
        }
    }
    cout<<ans;
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