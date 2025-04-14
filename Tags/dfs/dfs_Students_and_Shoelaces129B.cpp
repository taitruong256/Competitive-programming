/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[105];
ll n, m;
vector<ll> nodes[105];
ll adj[105];

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=m; i++)
    {
        ll a, b; cin>>a>>b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
        adj[a]++;
        adj[b]++;
    }

    ll ans=0;
    while (true)
    {
        vector<ll> temp;
        for (ll i=1; i<=n; i++) if (adj[i]==1) temp.push_back(i);
        if (temp.size()==0) break;
        ++ans;
        for (auto i: temp)
        {
            adj[i]=0;
            for (auto j: nodes[i]) adj[j]--;
        }
           
    }

    cout<<ans;
}
 
int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;
    while (t--) solve();
    return 0;
}
