#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define orderset tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> 
ll dp[2005][2005];

void solve()
{
    string s, t; cin>>s>>t; 
    s=" "+s;
    t=" "+t;
    ll n=s.size()-1, m=t.size()-1;  
    
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) 
            if (s[i]==t[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    cout<<dp[n][m];
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
    cerr<<"Time: "<<fixed<<setprecision(5)<<double(finish-start)/double(CLOCKS_PER_SEC);
    return 0;
}