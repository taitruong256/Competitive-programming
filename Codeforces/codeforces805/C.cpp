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

ll up(ll x)
{
    ++x;
    if (x==10) x=0;
    return x;
}

ll down(ll x)
{
    --x;
    if (x==-1) x=9;
    return x;
}

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    ll b[n+5];
    for (ll i=1; i<=n; i++) b[i]=0;
    for (ll i=1; i<=n; i++)
    {
        ll m; cin>>m;
        string s; cin>>s;  //  cout<<s<<endl;
        for (ll j=0; j<m; j++) if (s[j]=='U') ++b[i]; else --b[i];
    }

    // for (ll i=1; i<=n; i++) cout<<b[i]<<" "; cout<<endl;
    for (ll i=1; i<=n; i++) 
        if (b[i]<0) a[i]=(a[i]-b[i])%10;
        else a[i]=(a[i]-b[i]+10)%10;

    for (ll i=1; i<=n; i++) cout<<a[i]<<" "; cout<<endl;
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