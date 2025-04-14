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
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
vector<ll> adj[200005];
ll n, k, cnt[200005], sz[200005], ans, mx_depth;
bool process[200005];

ll get_subtree_size(ll u, ll par)
{
    sz[u]=1;
    for (auto v: adj[u]) if (v!=par && process[v]==false) 
        sz[u]+=get_subtree_size(v, u);
    return sz[u];
}

ll get_centroid(ll u, ll par, ll s)
{         
    for (auto v: adj[u]) if (v!=par && process[v]==false && sz[v]>s/2) 
        return get_centroid(v, u, s);
    return u;
}

void get_cnt(ll u, ll par, bool flag, ll depth)
{
    if (depth>k) return;     
    mx_depth=max(mx_depth, depth);
    if (flag==true) ++cnt[depth];
    else ans+=cnt[k-depth];           
    for (auto v: adj[u]) if (process[v]==false && v!=par) get_cnt(v, u, flag, depth+1);    
}

void centroid_decomposition(ll u)
{
    ll centroid=get_centroid(u, -1, get_subtree_size(u, -1)); 
    process[centroid]=true;
    mx_depth=0;
    cnt[0]=1;
    for (auto v: adj[centroid]) if (process[v]==false)
    {
        get_cnt(v, centroid, false, 1);   
        get_cnt(v, centroid, true, 1);   
    } 
    fill(cnt+1, cnt+mx_depth+1, 0);
    for (auto v: adj[centroid]) if (process[v]==false) centroid_decomposition(v);
}

void solve()
{
    cin>>n>>k;
    for (ll i=1; i<n; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    centroid_decomposition(1);
    cout<<ans;
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