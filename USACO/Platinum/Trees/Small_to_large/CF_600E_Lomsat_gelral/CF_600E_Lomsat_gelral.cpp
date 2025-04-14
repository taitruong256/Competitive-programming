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
                                        Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
ll n, color[100005], mx[100005], sum[100005], ans[100005];
vector<ll> adj[100005];
map<ll, ll> col_cnt[100005];

void dfs(ll u, ll p)
{
    col_cnt[u][color[u]]+=1;
    mx[u]=1;
    sum[u]=color[u];
    for (ll v: adj[u]) if (v!=p) 
        dfs(v, u);
    for (ll v: adj[u]) if (v!=p) 
        if (col_cnt[u].size()<col_cnt[v].size()) 
        {
            col_cnt[u].swap(col_cnt[v]);
            swap(sum[u], sum[v]);
            swap(mx[u], mx[v]);
        }
    for (ll v: adj[u]) if (v!=p)
    {
        for (auto [col, cnt]: col_cnt[v]) 
        {
            col_cnt[u][col]+=cnt;
            if (col_cnt[u][col]>mx[u])
            {
                mx[u]=col_cnt[u][col];
                sum[u]=col;
            }
            else if (col_cnt[u][col]==mx[u]) 
            {
                sum[u]+=col;
            }
        }
    }
    ans[u]=sum[u];
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>color[i];
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for (ll i=1; i<=n; i++) cout<<ans[i]<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}