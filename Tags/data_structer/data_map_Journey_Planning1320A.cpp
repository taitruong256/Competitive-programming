#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                    Try, try, try again until you succeed                          
 =====================================================================================
*/

void solve()
{
    ll n, ans=0; cin>>n;
    map<ll, ll> mp;
    for (ll i=1; i<=n; i++)
    {
        ll x; cin>>x;
        mp[x-i]+=x;
        ans=max(mp[x-i], ans);
    }
    cout<<ans;
}

int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;                // cin>>t;
    while (t--) solve();
    return 0;
}