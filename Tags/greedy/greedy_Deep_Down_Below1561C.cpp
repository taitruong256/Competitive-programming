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
    ll n; cin>>n;
    vector<pair<ll, ll>> v;
    for (ll i=0; i<n; i++) 
    {
        ll m; cin>>m;
        ll maxi=0, x;
        for (ll j=0; j<m; j++) 
        {
            cin>>x;
            maxi=max(maxi, x-j);
        }
        v.push_back({maxi, m});
    }
    sort(v.begin(), v.end());
    ll ans=0, sum=0;
    for (ll i=0; i<n; i++) 
    {
        ans=max(ans, v[i].first-sum);
        sum+=v[i].second;
    }
    cout<<ans+1<<endl;
}
 
int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    while (t--) solve();
    return 0;
}