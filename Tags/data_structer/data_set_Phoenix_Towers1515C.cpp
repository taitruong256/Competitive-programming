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
    ll n; cin>>n;
    map<ll, ll> x, y;
    map<pair<ll, ll>, ll> xy;
    for (ll i=0; i<n; i++)
    {
        ll p, q; cin>>p>>q;
        x[p]++;
        y[q]++;
        xy[{p, q}]++;
    }
    ll ans=0;
    for (auto i: x) ans+=i.second*(i.second-1)/2;
    for (auto i: y) ans+=i.second*(i.second-1)/2;
    for (auto i: xy) ans-=i.second*(i.second-1)/2;
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