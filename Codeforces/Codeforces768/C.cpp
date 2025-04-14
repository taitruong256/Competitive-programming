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
    ll n, k; cin>>n>>k;
    if (n==4 && k==3) 
    {
        cout<<-1<<endl;
        return;
    }
    vector<pair<ll, ll>> ans;
    if (k==0)
    {
        for (ll i=0; i<n/2; i++) ans.push_back({i, n-1-i});
        for (ll i=0; i<n/2; i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
        return;
    }
    else if (k>0 && k<n-1)
    {
        for (ll i=1; i<n/2; i++) if (i!=k && n-1-i!=k) ans.push_back({i, n-1-i});
        ans.push_back({n-1, k});
        ans.push_back({0, n-1-k});
        for (ll i=0; i<n/2; i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
        return;
    }
    else
    {
        ans.push_back({n-1, n-2});
        ans.push_back({n-3, 1});
        ans.push_back({0, 2});
        for (ll i=3; i<n/2; i++) ans.push_back({i, n-1-i});
        for (ll i=0; i<n/2; i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}