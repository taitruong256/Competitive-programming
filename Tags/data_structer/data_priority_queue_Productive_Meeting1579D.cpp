/*=====================================================================================
    Nothing is impossible, only you think it is impossible                 
            Try, try, try again until you succeed     
              Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    priority_queue<pair<ll, ll>> pq;
    vector<pair<ll, ll>> ans;
    for (ll i=1; i<=n; i++)
    {
        cin>>a[i];
        pq.push({a[i], i});
    }

    while (pq.size()>1)
    {
        ll i=pq.top().second; pq.pop();
        ll j=pq.top().second; pq.pop();
        if (a[i]>0 && a[j]>0)
        {
            ans.push_back({i, j});
            pq.push({--a[i], i});
            pq.push({--a[j], j});
        } 
    }
    cout<<ans.size()<<endl;
    for (auto it: ans) cout<<it.first<<' '<<it.second<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  cin>>t;
    while (t--) solve();
    return 0;
}