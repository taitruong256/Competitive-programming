/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, sz=0;
vector<ll> a(100005), pos(100005), temp(100005);
bool visited[100005];
vector<ll> ans[100005];

void dfs(ll x)
{    
    if (visited[x]==true) return;
    visited[x]=true;        
    ans[sz].push_back(x+1);
    dfs(pos[x]);
}

void solve()
{
    cin>>n;
    for (ll i=0; i<n; i++) 
    {
        cin>>a[i];
        temp[i]=a[i];    
    }
    sort(temp.begin(), temp.begin()+n);
    for (ll i=0; i<n; i++) pos[i]=lower_bound(temp.begin(), temp.begin()+n, a[i])-temp.begin();

    memset(visited, false, sizeof(visited));
    for (ll i=0; i<n; i++) if (visited[i]==false) 
    {
        dfs(i);
        ++sz;  
    }

    cout<<sz<<endl;
    for (ll i=0; i<sz; i++)
    {
        cout<<ans[i].size()<<" ";
        for (auto j: ans[i]) cout<<j<<" ";
        cout<<endl;
    }
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
