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
ll n; 
vector<pair<ll, ll>> v;
bool check(ll x)
{
    for (ll i=0; i<n; i++) if (x>v[i].first) x+=v[i].second; else return false;
    return true;
}

void solve()
{
    cin>>n;
    v.clear();
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
    ll ans=0, l=0, r=2e9;
    while (l<=r)
    {
        ll mid=(l+r)>>1;
        if (check(mid)) ans=mid, r=mid-1;
        else l=mid+1;
    }
    cout<<ans<<endl;
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