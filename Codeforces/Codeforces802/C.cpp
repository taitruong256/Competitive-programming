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
    ll n; cin>>n;
    ll a[n+5], b[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    ll cnt=0;
    b[1]=a[1];
    for (ll i=2; i<=n; i++)
    {
        if (a[i]-cnt>b[i-1])
        {
            cnt+=abs(a[i]-cnt-b[i-1]);
            
        }
        b[i]=a[i]-cnt;
    }
    // for (ll i=1; i<=n; i++) cout<<b[i]<<" "; cout<<endl;
    ll ans=0;
    for (ll i=2; i<=n; i++) if (b[i]!=b[i-1]) ans+=a[i]-b[i];
    ans+=abs(b[n])+abs(b[1]-b[n]);
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