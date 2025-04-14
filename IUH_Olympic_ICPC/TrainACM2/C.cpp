/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    map<ll, ll> cnt;
    ll ans=0;
    for (ll i=1; i<=n; i++)
    {
        cin>>a[i];
        for (ll j=1; j<32; j++) 
        {
            ll x=1<<j;
            ans+=cnt[x-a[i]];
        }
        ++cnt[a[i]];
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; //cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}