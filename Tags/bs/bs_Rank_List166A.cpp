/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
 =====================================================================================
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first==b.first) return a.second<b.second;
    return a.first>b.first;
}

void solve()
{
    ll n, k; cin>>n>>k;
    vector<pair<ll, ll>> a(n);
    for (ll i=0; i<n; i++) cin>>a[i].first>>a[i].second;
    sort(a.begin(), a.end(), comp);

    auto it=a[k-1];
    ll l=k-1, r=k-1;
    while (l>=0 && a[l].first==it.first && a[l].second==it.second) --l;
    while (r<n && a[r].first==it.first && a[r].second==it.second) ++r;
    cout<<r-l-1<<endl;
}

int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; //cin>>t;
    while (t--) solve();
    return 0;
}