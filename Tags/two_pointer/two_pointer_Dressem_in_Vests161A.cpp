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
    ll n, m, x, y; cin>>n>>m>>x>>y;
    ll a[n], b[m];
    for (ll i=0; i<n; i++) cin>>a[i];
    for (ll i=0; i<m; i++) cin>>b[i];

    ll i=0, j=0;
    vector<pair<ll, ll>> ans;
    while (i<n && j<m)
    {
        if (b[j]>=a[i]-x && b[j]<=a[i]+y) 
        {
            ans.push_back({i+1, j+1});
            ++i;
            ++j;
        }
        else if (b[j]<a[i]-x) ++j;
        else ++i;
    }
    cout<<ans.size()<<endl;
    for (auto it: ans) cout<<it.first<<" "<<it.second<<endl;
}
 
int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}