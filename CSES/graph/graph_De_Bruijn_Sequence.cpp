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
const ll mod = 1e9+7;
const ll inf = 1e9;
ll n;
map<ll, vector<pair<ll, ll>>> adj;
string ans;
vector<bool> vis;

void dfs(int u) 
{
    for (auto it: adj[u]) if (vis[it.second]==false)
    { 
        ll v=it.first, id=it.second;
        vis[id]=true;
        dfs(v);
        ans.push_back('0'+id%2);
    }
}

void solve()
{
    cin>>n;
    for (ll i=0; i<(1<<n); i++)
    {
        ll u=i>>1, v=i&((1<<(n-1))-1);
        adj[u].push_back({v, i});   //tach ra thanh n-1 bit dau va 1 bit cuoi
    }
    vis.resize(0); vis.resize(200005, false);
    dfs(0);
    for (ll i=0; i<n-1; i++) ans.push_back('0');
    reverse(ans.begin(), ans.end());
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