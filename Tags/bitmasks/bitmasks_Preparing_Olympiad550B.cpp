/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, l, r, x; cin>>n>>l>>r>>x;
    ll a[n+5];
    for (ll i=0; i<n; i++) cin>>a[i];
    ll s=0, ans=0;
    for (ll i=0; i<(1<<n); i++)
    { 
        vector<ll> v; 
        //for (ll j=n-1; j>=0; j--) if (i&(1<<j)) cout<<1; else cout<<0; cout<<endl;
        for (ll j=n-1; j>=0; j--) if (i&(1<<j)) v.push_back(a[j]);
        if (v.size()<2) continue;
        ll mx=-1e10, mn=1e10;
        for (ll j=0; j<v.size(); j++) mx=max(mx, v[j]);
        for (ll j=0; j<v.size(); j++) mn=min(mn, v[j]);
        ll d=mx-mn;
        if (d<x) continue;
        ll s=0;
        for (ll j=0; j<v.size(); j++) s+=v[j];
        if (l<=s && s<=r) ++ans;
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
    ll t=1;// cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}