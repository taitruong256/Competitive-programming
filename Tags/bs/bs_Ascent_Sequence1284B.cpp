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
    ll ans=n*n;
    while (n--)
    {
        ll m; cin>>m;
        vector<ll> a(m);
        for (ll i=0; i<m; i++) cin>>a[i];
        if (is_sorted(a.rbegin(), a.rend())) v.emplace_back(make_pair(a[m-1], a[0]));
    }
    sort(v.begin(), v.end());
    //for (auto it: v) cout<<it.first<<" "<<it.second<<endl;
    for (ll i=0; i<v.size(); i++) 
        ans-=v.end()-lower_bound(v.begin(), v.end(), pair<ll, ll>(v[i].second, -1));
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
    ll t=1; 
    while (t--) solve();
    return 0;
}