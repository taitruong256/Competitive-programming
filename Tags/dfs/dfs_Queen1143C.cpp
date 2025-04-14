/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, root;
vector<ll> v[100005];
bool visited[100005];
ll c[100005];
vector<ll> ans;

void dfs(ll x)
{                   
    visited[x]=true;
    ll del=c[x];
    for (auto i: v[x]) if (visited[i]==false) 
    {
        del=del&c[i];
        dfs(i);
    }
    if (del==1) ans.push_back(x);
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n ;i++)
    {
        ll x; cin>>x>>c[i];
        if (x==-1)
        {
            root=i;
            continue;
        }
        v[i].push_back(x);
        v[x].push_back(i);
    }
    dfs(root);
    sort(ans.begin(), ans.end());
    if (ans.size()==0) cout<<-1;
    else for (int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
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
