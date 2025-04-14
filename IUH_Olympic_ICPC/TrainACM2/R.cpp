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
    map<ll, ll> cnt1, cnt2;
    map<pair<ll, ll>, ll> cnt3;
    for (ll i=0; i<n; i++)
    {
        ll x, y; cin>>x>>y;
        cnt1[x]++;
        cnt2[y]++;
        cnt3[{x, y}]++;
    }
    ll ans=0;
    for (auto i: cnt1) ans+=i.second*(i.second-1)/2;
    for (auto i: cnt2) ans+=i.second*(i.second-1)/2;
    for (auto i: cnt3) ans-=i.second*(i.second-1)/2;
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