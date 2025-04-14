#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                    Try, try, try again until you succeed     
                      Where is the bug, delete it there                     
 =====================================================================================
*/

void solve()
{               
    ll n, k; cin>>n>>k;
    ll ans[200005]={0};
    vector<pair<ll, ll>> v;
    map<ll, ll> count;
    for (ll i=0; i<n; i++) 
    {
        ll x; cin>>x;
        count[x]++;
        if (count[x]<=k) v.push_back({x, i});
    }
    sort(v.begin(), v.end());     
    for (ll i=0; i<v.size()/k*k; i++) ans[v[i].second]=i%k+1;
    for (int i=0; i<n; i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    while (t--) solve();
    return 0;
}