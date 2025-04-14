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
Có n ngọn núi và m con đường nối giữa các cặp ngọn núi u, v. Mỗi đỉnh núi có chiều cao h[i].
Để đi từ đỉnh núi u đến đỉnh núi v sẽ tiêu tốn h[i]-[j] năng lượng. (nếu h[i]-h[j]<0 nghĩa là đi xuống dốc, có thêm năng lượng).
Có q truy vấn, mỗi truy vấn (a, b, e) hỏi có thể đi từ a đến b khi có e năng lượng hay không?

Input
2
7 7
1 5 3 4 2 4 1
1 4
4 3
3 6
3 2
2 5
5 6
5 7
5
1 1 3
6 2 0
4 7 0
1 7 4
1 7 2
6 5
4 7 6 2 5 1
1 3
5 3
1 5
2 4
6 2
5
1 5 1
1 3 1
1 2 1000
6 2 6
6 2 5
Output
YES
NO
YES
YES
NO

YES
NO
NO
YES
NO
YES
NO
YES
YES
NO

YES
NO
NO
YES
NO

Ý tưởng:
Xét mức năng lượng tiêu tốn khi đi từ u->k->v: h[u]-h[k]+h[k]-h[v]=h[u]-h[v] => u chỉ có thể đi tới được những đỉnh có độ cao 
không lớn hơn h[u]+e.
Để kiểm tra u và v có cùng thành phần liên thông không, ta sắp sếp truy vấn h[u]+e theo thứ tự tăng dần.
Mỗi truy vấn, thêm cạnh có h[x]>h[y] và h[x]<=h[u]+e. Duy trì một DSU để kiểm tra xem u và v có cùng thành phần liên thông không?
*/

ll n, m, q, h[200005], ans[200005];
vector<ll> adj[200005];

struct edge{ll id, w;};
struct query{ll u, v, id, h;};

bool comp1(edge e1, edge e2)
{
    return e1.w<e2.w;
}

bool comp2(query q1, query q2)
{
    return q1.h<q2.h;
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

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=n; i++) cin>>h[i];
    deque<edge> e;
    vector<query> qry;
    for (ll i=1; i<=m; i++)
    {
        ll u, v; cin>>u>>v;
        if (h[u]>h[v]) adj[u].push_back(v);
        else adj[v].push_back(u);
    }
    for (ll i=1; i<=n; i++) e.push_back({i, h[i]});
    cin>>q;
    for (ll i=1; i<=q; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        qry.push_back({u, v, i, w+h[u]});
    }
    sort(e.begin(), e.end(), comp1);
    sort(qry.begin(), qry.end(), comp2);
    DSU dsu(n);

    for (auto [u, v, id, h]: qry)
    {   
        while (!e.empty() && e.front().w<=h) 
        {
            auto [i, w]=e.front(); e.pop_front();
            for (auto x: adj[i])
                dsu.merge(i, x);
        }
        ans[id]=dsu.same_component(u, v);
    }
    for (ll i=1; i<=q; i++) 
        if (ans[i]==0) cout<<"NO\n";
        else cout<<"YES\n";
    cout<<endl;

    for (ll i=1; i<=n; i++) adj[i].clear();
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