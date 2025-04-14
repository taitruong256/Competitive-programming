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
                                       Where is the bug, delete it there
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;

/*
Cho đồ thị vô hướng n đỉnh m cạnh có trọng số.
Tìm bất kỳ chu trình nào sao cho trọng số cạnh nhẹ nhất là nhỏ nhất.

Input
5
6 6
1 2 1
2 3 1
3 1 1
4 5 1
5 6 1
6 4 1
6 6
1 2 10
2 3 8
3 1 5
4 5 100
5 6 40
6 4 3
6 15
1 2 4
5 2 8
6 1 7
6 3 10
6 5 1
3 2 8
4 3 4
5 3 6
2 6 6
5 4 5
4 1 3
6 4 5
4 2 1
3 1 7
1 5 5
4 6
2 3 2
1 3 10
1 4 1
3 4 7
2 4 5
1 2 2
4 5
2 1 10
3 1 3
4 2 6
1 4 7
2 3 3
Output
1 3
1 2 3 
3 3
6 4 5 
1 5
4 2 1 6 3 
1 4
1 4 3 2 
3 3
2 3 1 

Ý tưởng:
Sắp sếp các cạnh theo trọng số giảm dần.
Dùng DSU để merge các cạnh
    -Nếu cạnh được merge, thêm vào đồ thị cây
    -Nếu cạnh không được merge (tạo thành chu trình), lưu cạnh đó lại vì đó là cạnh cần tìm.
Để tìm chu trình chỉ đơn giản là tìm đường đi trên cây u->v (đường đi là duy nhất).
*/

ll n, m, par[200005];
vector<ll> adj[200005], path;

struct edge {ll u, v, w; };
bool comp(edge a, edge b)
{
    return a.w>b.w;
}

struct DSU
{
    vector<ll> par, size;
    ll n;
    DSU(){}
    DSU(ll _n)
    {
        n=_n;
        par.resize(n+5, 0);
        for (ll i=1; i<=n; i++) par[i]=i;
        size.resize(n+5, 1);
    }
    ll find(ll u)
    {
        if (u==par[u]) return u;
        return par[u]=find(par[u]); 
        }
    bool merge(ll u, ll v)
    {
        u=find(u);
        v=find(v);
        if (u==v) return false;
        if (size[u]<size[v]) swap(u, v);
        par[v]=u;
        size[u]+=size[v];
        return true;
    }
    bool same_component(ll u, ll v)
    {
        return find(u)==find(v);
    }
};

void dfs(ll u, ll p)
{
    par[u]=p;
    for (auto v: adj[u]) if (v!=p)
        dfs(v, u);
}

void solve()
{
    cin>>n>>m;
    vector<edge> e;
    for (ll i=1; i<=m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        e.push_back({u, v, w});
    }
    sort(e.begin(), e.end(), comp);
    DSU dsu(n);
    ll st=-1, fi=-1, ans=1e18;
    for (auto [u, v, w]: e)
    {   
        if (dsu.merge(u, v))
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else 
        {
            st=u;
            fi=v;
            ans=w;
        }
    }
    dfs(st, -1);
    while (fi!=st)
    {
        path.push_back(fi);
        fi=par[fi];
    }
    path.push_back(st);
    reverse(path.begin(), path.end());
    cout<<ans<<" "<<path.size()<<endl;
    for (auto i: path) cout<<i<<" ";
    cout<<endl;

    for (ll i=1; i<=n; i++) adj[i].clear();
    path.clear();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}