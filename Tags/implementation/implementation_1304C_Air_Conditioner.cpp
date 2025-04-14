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
    ll n, m; cin>>n>>m;
    ll t[n+5], a[n+5], b[n+5];
    t[0]=0;
    for (ll i=1; i<=n; i++) cin>>t[i]>>a[i]>>b[i];

    ll low=m, high=m;
    for (ll i=1; i<=n; i++)
    {
        low-=(t[i]-t[i-1]);
        high+=(t[i]-t[i-1]);
        low=max(low, a[i]);
        high=min(high, b[i]);
        if (low>high)
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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