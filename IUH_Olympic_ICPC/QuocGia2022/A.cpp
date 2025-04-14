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
struct QUERY
{
    char type;
    ll id, s, u, v;
    bool ans;

    QUERY(){}
    QUERY(ll _type, ll _id, ll _s, ll _u, ll _v)
    {
        type=_type;
        id=_id;
        s=_s;
        u=_u;
        v=_v;
    }
};

struct DSU
{
    vector<ll> parent, size;

    DSU(){}
    DSU(ll n)
    {
        parent.resize(n+5);
        size.resize(n+5, 1);
        for (ll i=1; i<=n; i++) parent[i]=i;
    }
    
    ll find(ll u)
    {
        if (parent[u]==u) return u;
        return parent[u]=find(parent[u]);
    }
    
    void merge(ll u, ll v)
    {
        u=find(u);   
        v=find(v); 
        if (u==v) return;
        if (size[u]<size[v]) swap(u, v);
        parent[v]=u;
        size[u]+=size[v];
    }

    bool same_component(ll u, ll v)
    {
        return find(u)==find(v);
    }
};
ll n, q, u, v, s;
QUERY queries[200005];
vector<ll> q_queries[200005];

void solve()
{
    cin>>n>>q;   
    ll snapshot=0;
    for (ll k=1; k<=q; k++)
    {

        char c; cin>>c; 
        if (c=='A' || c=='?')
        {
            cin>>u>>v;
            queries[k]=QUERY(c, k, -1LL, u, v);
        }
        else if (c=='C') 
        {
            queries[k]=QUERY(c, k, -1LL, 0LL, 0LL);
            ++snapshot;
        }
        else 
        {
            cin>>s>>u>>v;
            queries[k]=QUERY(c, k, s, u, v);
            q_queries[s].push_back(k);
        }
    }

    DSU dsu(n);
    snapshot=-1;
    queries[0]=QUERY('C', 0, 0, 0, 0);
    for (ll i=0; i<=q; i++)
    {
        char c=queries[i].type;
        ll u=queries[i].u, v=queries[i].v;
        if (c=='A') dsu.merge(u, v);
        else if (c=='?') queries[i].ans=dsu.same_component(u, v);
        else if (c=='C') 
        {
            ++snapshot;
            for (auto qry: q_queries[snapshot]) queries[qry].ans=dsu.same_component(queries[qry].u, queries[qry].v);
        }
    }

    for (ll i=1; i<=q; i++) if (queries[i].type=='?' || queries[i].type=='Q') 
        cout<<(queries[i].ans==true?"Y":"N");
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