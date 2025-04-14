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
    ll n; cin>>n;
    ll u[n+5];
    vector<ll> ans(n+5), region[n+5];
    ll sum[n+5]={0};
    for (ll i=1; i<=n; i++) cin>>u[i];
    for (ll i=1; i<=n; i++) {ll x; cin>>x; region[u[i]].push_back(x);}
    
    for (ll i=1; i<=n; i++)
    {
        sort(region[i].begin(), region[i].end(), greater<ll>());
        ll size=region[i].size();
        for (ll j=1; j<=size; j++) sum[j]=sum[j-1]+region[i][j-1];
        //for (ll j=1; j<=size; j++) cout<<sum[j]<<" "; cout<<endl;
        for (ll j=1; j<=size; j++) ans[j]+=sum[size-size%j];
    }
    for (ll i=1; i<=n; i++) cout<<ans[i]<<" ";
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
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}