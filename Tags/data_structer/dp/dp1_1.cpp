#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define orderset tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

void solve()
{
    // ll n; cin>>n;
    // ll a[n+5], dp[n+5];
    // for (ll i=1; i<=n; i++) cin>>a[i];
    // dp[1]=1;
    // for (ll i=2; i<=n; i++) 
    // {
    //     ll mx=0;
    //     for (ll j=1; j<i; j++) if (dp[j]>mx && a[j]<a[i]) mx=dp[j];
    //     dp[i]=mx+1;
    // }
    // ll ans=1;
    // for (ll i=1; i<=n; i++) ans=max(ans, dp[i]);
    // cout<<ans;

    ll n; cin>>n;
    vector<ll> ans;
    for (ll i=1; i<=n; i++)
    {
        ll x; cin>>x;
        ll pos=lower_bound(ans.begin(), ans.end(), x)-ans.begin();
        if (pos==ans.size()) ans.push_back(x);
        else ans[pos]=x;
    }
    cout<<ans.size();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    clock_t start=clock();
    solve();
    clock_t finish=clock();
    cerr<<fixed<<setprecision(10)<<double(finish-start)/double(CLOCKS_PER_SEC)<<endl;
    return 0;
}
