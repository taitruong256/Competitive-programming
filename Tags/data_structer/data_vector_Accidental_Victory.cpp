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
    for (ll i=1; i<=n; i++)
    {
        ll x; cin>>x;
        v.push_back({x, i});
    }
    sort(v.begin(), v.end());   
    v.push_back({v[n-1].first, n+1});
    ll sum=0, ind=0;
    for (ll i=0; i<v.size(); i++) 
    {
        if (sum<v[i].first) ind=i;
        sum+=v[i].first;
    }
    vector<ll> ans;
    for (ll i=ind; i<v.size()-1; i++) ans.push_back(v[i].second);
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for (auto it: ans) cout<<it<<" ";
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