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
    vector<ll> cnt(n+5), pre(n+5);
    for (ll i=1; i<=n; i++)
    {
        ll x; cin>>x;
        
        ll start, endd, price; 
        if (cnt[x]>=1)
        {
            project.push_back({i, pre[x], i-pre[x]+1});
            project.push_back({i, pre[x]+1, i-pre[x]});
        }
        ++cnt[x];
        pre[x]=i;
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
    }
    cout<<ans<<endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}