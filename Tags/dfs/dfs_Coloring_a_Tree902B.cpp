/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ans=0;
ll color[10005], parent[10005];
vector<ll> v[10005];

void dfs(ll x, ll par, ll col)
{
    color[x]=col;
    for (auto i: v[x]) if (i!=par) dfs(i, parent[i], col);
}

void solve()
{
    cin>>n;
    memset(parent, 0, sizeof(parent));
    for (ll i=2; i<=n; i++)
    {
        ll x; cin>>x;
        v[i].push_back(x);
        v[x].push_back(i);
        parent[i]=x;
    }
    memset(color, 0, sizeof(color));
    for (ll i=1; i<=n; i++)
    {
        ll x; cin>>x;
        if (x!=color[i])
        {
            ++ans;
            dfs(i, parent[i], x);

            //for (ll j=1; j<=n; j++) cout<<color[j]<<" "; cout<<endl;
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
