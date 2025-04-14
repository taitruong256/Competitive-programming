/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

void solve()
{
    ll n; cin>>n;
    vector<tuple<ll, ll, ll>> project;
    for (ll i=0; i<n; i++)
    {
        ll start, endd, price; cin>>start>>endd>>price;
        project.push_back({endd, start, price});
    }
    sort(project.begin(), project.end());
    map<ll, ll> dp;
    dp[0]=0;
    ll ans=0;
    for (auto i: project)
    {
        ll start, endd, price; tie(endd, start, price)=i;
        auto it=dp.lower_bound(start);
        --it;
        ll now=(*it).second+price;
        ans=max(ans, now);
        dp[endd]=ans;
        for (auto j: dp) cout<<j.first<<" "<<j.second<<endl; cout<<endl;
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
    solve();
    return 0;
}