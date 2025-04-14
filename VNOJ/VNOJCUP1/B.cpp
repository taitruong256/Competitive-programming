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
#define ll int

ll cnt[100005];

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    map<ll, ll> dem;
    for (ll i=1; i<=n; i++) cin>>a[i], ++dem[a[i]];
    memset(cnt, 0, sizeof(cnt));
    for (ll i=2; i<=1000000; i+=2)
        for (ll j=i; j<=1000000; j+=i)
            cnt[i]+=dem[j];
    for (ll i=1; i<=n; i++)
    {
        ll x=cnt[a[i]*2];
        cout<<x*(x-1)/2<<" ";
    }
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