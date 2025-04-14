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
Van de:
Cho do thi G co n dinh m canh co huong, moi dinh co mot gia tri a[i].
Do thi H ban dau giong G, moi thao tac chon 3 dinh a, b, c sao cho 
co canh tu a den b va b den c thi them canh a den c.
Hoi trong so cac duong di dai nhat cua H, duong di co gia tri nho nhat la bao nhieu.

Test:
Input
3
5 6
2 2 4 1 3
1 2
1 3
2 4
3 4
4 5
5 2
7 7
999999999 999999999 999999999 999999999 1000000000 999999999 1000000000
1 2
2 3
3 4
4 1
4 5
4 6
6 7
14 22
2 3 5 7 3 4 1 4 3 4 2 2 5 1
1 2
2 3
2 4
3 1
4 4
4 5
5 6
5 6
5 12
6 7
6 8
7 5
7 7
7 9
8 4
9 11
10 9
11 10
11 10
12 13
13 14
14 12
Output
5 12
6 5999999995
11 37


Y tuong:
Nhan xet la tat ca cac dinh cung mot thanh phan lien thong manh (scc) se tao thanh mot do thi hoan hao. 
Vi vay ta nens cac scc lai 1 dinh thanh DAG, moi dinh co gia tri <size[u], sum[u]>
Dp tren DAG tim ket qua.
*/

ll n, m, a[200005], scc[200005], sum[200005], sz[200005], cnt, _size, _sum;
vector<ll> g[200005], g_t[200005], h[200005];
bool vis[200005];
vector<ll> topo;
pair<ll, ll> dp[200005];

void topo_scc(ll u)
{
    vis[u]=true;
    for (auto v: g[u]) if (vis[v]==false) topo_scc(v);
    topo.push_back(u);
}

void dfs_scc(ll u)
{
    vis[u]=true;
    ++_size;
    _sum+=a[u];
    scc[u]=cnt;
    for (auto v: g_t[u]) if (vis[v]==false) dfs_scc(v);
}

void calc(ll u)
{
    dp[u]={sz[u], -sum[u]};
    vis[u]=true;
    pair<ll, ll> mx={0, 0};
    for (auto v: h[u]) 
    {
        if (vis[v]==false) calc(v);
        mx=max(mx, dp[v]);
    }
    dp[u].first+=mx.first;
    dp[u].second+=mx.second;
}

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=m; i++)
    {
        ll u, v; cin>>u>>v; 
        g[u].push_back(v);
        g_t[v].push_back(u);
    }

    //danh dau dinh u thuoc scc nao
    for (ll i=1; i<=n; i++) vis[i]=false;
    topo.clear();
    for (ll i=1; i<=n; i++) if (vis[i]==false) topo_scc(i);
    reverse(topo.begin(), topo.end());
    for (ll i=1; i<=n; i++) vis[i]=false;
    cnt=0;
    for (ll i: topo) if (vis[i]==false)
    {
        ++cnt;
        _size=0;
        _sum=0;
        dfs_scc(i);
        sum[cnt]=_sum;
        sz[cnt]=_size;
    }
    
    //tao do thi h moi nen cac scc thanh 1 dinh thanh DAG
    for (ll i=1; i<=n; i++)
        for (auto j: g[i])
            if (scc[i]!=scc[j]) 
                h[scc[i]].push_back(scc[j]);

    //dp tren DAG
    for (ll i=1; i<=n; i++) vis[i]=false;
    for (ll i=1; i<=n; i++) if (vis[i]==false) calc(i);
    pair<ll, ll> ans;
    for (ll i=1; i<=cnt; i++) ans=max(ans, dp[i]);
    cout<<ans.first<<" "<<-ans.second<<endl;
    
    //reset testcase
    for (ll i=1; i<=n; i++) g[i].clear(), g_t[i].clear(), h[i].clear(), dp[i]={0, 0};
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