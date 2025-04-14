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
    ll n, l, r; cin>>n>>l>>r;
    ll a[n+5];
    for (ll i=1; i<=n; i++)
    {
        ll x=(r/i)*i;
        if (x>=l && x<=r) a[i]=x;
        else 
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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