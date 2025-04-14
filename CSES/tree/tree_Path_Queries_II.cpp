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
                 Don't pray for an easy life, pray for the strength to endure a difficult one - Bruce Lee
 I fear not the man who has practiced 10,000 kicks once, but I fear the man who has practiced 1 kick 10,000 times - Bruce Lee
==============================================================================================================*/
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define ll long long
//tree<ll, null_type, less<ll>, rb_tree_tag,
//tree_order_statistics_node_update> T;             //find_by_order            order_of_key
#define endl '\n'
const ll mod = 1e9+7;
vector<ll> adj[200005];
ll n, q, nHead=0, nBase=0, nChain=1, head[200005], chains[200005], degree[200005], pos[200005], nChild[200005], parent[200005];
ll a[200005], t[200005], tree[400005];
 
void dfs(ll u, ll p)
{
    nChild[u]=1;
    parent[u]=p;
    for (auto v: adj[u]) if (v!=p)
    {
        dfs(v, u);
        nChild[u]+=nChild[v];
    }
}
 
void hld(ll u, ll p)
{
    if (head[nChain]==0) head[nChain]=u;
    chains[u]=nChain;
    pos[u]=++nBase;
    ll mx=-1;
    for (auto v: adj[u]) if (v!=p && (mx==-1 || nChild[v]>nChild[mx])) mx=v;
    if (mx>-1) hld(mx, u);
    for (auto v: adj[u]) if (v!=p && v!=mx)
    {
        ++nChain;
        degree[nChain]=degree[chains[u]]+1;
        hld(v, u);
    }
}
 
ll lca(ll u, ll v)
{
    if (degree[chains[u]]<degree[chains[v]]) swap(u, v);
    while (degree[chains[u]]>degree[chains[v]]) u=parent[head[chains[u]]];
    while (chains[u]!=chains[v])
    {
        u=parent[head[chains[u]]];
        v=parent[head[chains[v]]];
    }     
    return pos[u]<pos[v]?u:v;
}

void build() {
    for (ll i = 0; i < n; i++) tree[i + n] = a[t[i+1]];
    for (ll i = n - 1; i > 0; i--) tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
}

ll query(ll l, ll r) {
    ll res = -1e10;
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, tree[l++]);
        if (!(r & 1)) res = max(res, tree[r--]);
    }
    return res;
}

void update(ll i, ll x) {
    for (tree[i += n] = x; i > 1; i >>= 1) tree[i >> 1] = max(tree[i], tree[i ^ 1]);
}


ll path(ll u, ll lca)
{
    ll ans=INT_MIN;
    while (1==1)
    {         
        if (chains[u]==chains[lca]) 
        {           
            ans=max(ans, query(pos[lca]-1, pos[u]-1));
            break;
        }                
        ans=max(ans, query(pos[head[chains[u]]]-1, pos[u]-1)); 
        u=parent[head[chains[u]]];
    }
    return ans;
}

void solve()
{
    scanf("%lld%lld", &n, &q);    
    for (ll i=1; i<=n; i++) scanf("%lld", &a[i]);      
    for (ll i=2; i<=n; i++)
    {
        ll u, v; scanf("%lld%lld", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    hld(1, 0);
    for (ll i=1; i<=n; i++) t[pos[i]]=i;
    build();
    // for (ll i=0; i<=2*n; i++) cout<<tree[i]<<" "; cout<<endl;

    while (q--)
    {
        ll type; scanf("%lld", &type);
        if (type==1)
        {
            ll p, v; scanf("%lld%lld", &p, &v);
            update(pos[p]-1, v);
            // for (ll i=0; i<=2*n; i++) cout<<tree[i]<<" "; cout<<endl;
        }
        else 
        {
            ll u, v; scanf("%lld%lld", &u, &v);
            ll l=lca(u, v);
            cout<<max(path(u, l), path(v, l))<<" ";
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    clock_t start = clock();
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<< double(end-start)/ double(CLOCKS_PER_SEC)<<endl;  
    return 0;
}