/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define mod 1000000007

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    map<ll, ll> cnt1, cnt2, cnt3;
    for (ll i=0; i<n; i++)
    {
        ll x; cin>>x;
        ++cnt1[x];
    }
    for (ll i=0; i<n-1; i++)
    {
        ll x; cin>>x;
        ++cnt2[x];
    }
    for (ll i=0; i<n-2; i++)
    {
        ll x; cin>>x;
        ++cnt3[x];
    }
    for (auto it: cnt1) if (cnt2[it.first]!=it.second)
    {
        cout<<it.first<<endl;
        break;
    }
    for (auto it: cnt2) if (cnt3[it.first]!=it.second) 
    {
        cout<<it.first;
        break;
    }
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