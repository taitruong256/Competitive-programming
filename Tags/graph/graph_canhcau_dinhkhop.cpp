/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|     
      __|  |__              __|  |__                                         |_|  | |  | |       | |  
     |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
        |  |    _____   _     |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | |_| | | |_| | | |  | | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  |_| \____ |   |______| |______/  \_______/
                                                                        | |
                                                                      __/ |
                                                                     |___/  
                             Nothing is impossible, only you think it is impossible                 
                                     Try, try, try again until you succeed     
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
ll n, m;
vector<ll> adj[100005];
bool khop[100005];
ll num[100005], low[100005], tail[100005], timedfs=0, cau=0;

void dfs(ll u, ll par)
{
    int child = 0; // Số lượng con trực tiếp của đỉnh u trong cây DFS
    num[u] = low[u] = ++timedfs;
    for (int v : adj[u]) {
        if (v == par) continue;
        if (num[v]==-1) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] == num[v]) cau++;
            child++;
            if (u == par) { // Nếu u là đỉnh gốc của cây DFS
                if (child > 1) khop[u] = true;
            }
            else if (low[v] >= num[u]) khop[u] = true;
        }
        else low[u] = min(low[u], num[v]);
    }
}

void solve()
{
    cin>>n>>m;
    memset(num, -1, sizeof(num));
    memset(khop, false, sizeof(khop));
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (ll i=1; i<=n; i++) if (num[i]==-1) dfs(i, i);
    ll cntkhop=0;
    for (ll i=1; i<=n; i++) cntkhop+=khop[i];
    cout<<cntkhop<<" "<<cau;
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
