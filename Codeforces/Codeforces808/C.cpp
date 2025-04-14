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

void binary(ll n)
{
    while (n>0)
    {
        cout<<n%2;
        n/=2;
    }
}

void solve()
{
    ll n, q; cin>>n>>q;      cout<<n<<endl;
    ll a[n+5];
    for (ll i=0; i<n; i++) cin>>a[i]; 

    pair<ll, ll> ans={0, 0};
    for (ll i=0; i<(1<<n); i++)
    {
        ll tam=q+1;
        for (ll j=0; j<n; j++) if (i&(1<<j)) --tam;
        if (tam>=0) ans=max(ans, {q-tam, i});
    }
    cout<<ans.second<<endl;
    binary(ans.second);
    cout<<endl;
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