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
ll a[3005];
ll n, x;

ll calc(ll k)
{
    ll mx=a[1]/k, mn=a[1]/k;
    for (ll i=1; i<=x; i++)
    {
        mx=max(mx, a[i]);
        mn=min(mn, a[i]);
        if (max(a[i]/i, mx)-min(a[i]/i, mn)<=mx-mn)
        {
            mx=max(mx, a[i]/i);
            mn=min(mn, a[i]/i);
        }
    }
    cout<<mx<<" "<<mn<<endl;
    return mx-mn;
}

void solve()
{
    cin>>n>>x;
    for (ll i=1; i<=n; i++) cin>>a[i];  //cout<<n<<endl;
    sort(a+1, a+n+1, greater<ll>());
    ll ans=inf;
    for (ll i=1; i<=x; i++) ans=min(calc(i), ans);
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