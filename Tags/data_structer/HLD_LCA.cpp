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
const ll mod = 1e9+7, inf = 1e16;
vector<ll> adj[200005], chain[200005];
ll n, q, nHead=0, nBase=0, nChain=1, chainHead[200005], chainIndex[200005], degreeHead[200005], posInBase[200005], nChild[200005], parent[200005];

void dfs(ll u, ll p)
{
    nChild[u]=1;
    for (auto v: adj[u]) if (v!=p)
    {
        dfs(v, u);
        nChild[u]+=nChild[v];
    }
}

void hld(ll u, ll p)
{
    if (chainHead[nChain]==0) chainHead[nChain]=u;
    chainIndex[u]=nChain;
    posInBase[u]=++nBase;
    ll mx=-1;
    for (auto v: adj[u]) if (v!=p && (mx==-1 || nChild[v]>nChild[mx])) mx=v;
    if (mx>-1) hld(mx, u);
    for (auto v: adj[u]) if (v!=p && v!=mx)
    {
        ++nChain;
        degreeHead[nChain]=degreeHead[chainIndex[u]]+1;
        hld(v, u);
    }
}

ll lca(ll u, ll v)
{
    if (degreeHead[chainIndex[u]]<degreeHead[chainIndex[v]]) swap(u, v);
    while (degreeHead[chainIndex[u]]>degreeHead[chainIndex[v]]) u=parent[chainHead[chainIndex[u]]];
    while (chainIndex[u]!=chainIndex[v])
    {
        u=parent[chainHead[chainIndex[u]]];
        v=parent[chainHead[chainIndex[v]]];
    }     
    return posInBase[u]<posInBase[v]?u:v;
}

void solve()
{
    cin>>n>>q;
    for (ll i=2; i<=n; i++)
    {
        ll x; cin>>x;
        adj[x].push_back(i);
        parent[i]=x;
    }
    dfs(1, 0);
    hld(1, 0);
    while (q--)
    {
        ll u, v; cin>>u>>v;
        cout<<lca(u, v)<<endl;
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