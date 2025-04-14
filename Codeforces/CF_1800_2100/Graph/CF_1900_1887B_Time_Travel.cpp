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
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

/*
Có t thời điểm, mỗi thời điểm ghi lại 1 đồ thị.
Bạn sẽ du hành xuyên thời gian tại k thời điểm a[i], vào mỗi thời điểm bạn chỉ có thể di chuyển qua tối đa 1 cạnh kề
với đỉnh hiện tại. Mục tiêu là đi từ đỉnh 1 đến đỉnh n, hãy tính thời gian ít nhất.

Input
5 2
4
1 2
2 3
3 4
4 5
2
2 3
3 5
6
2 1 2 1 2 1
Output
5

Ý tưởng:
Gọi d[v] là thời gian di chuyển ít nhất từ đỉnh 1 đến đỉnh v.
d[1]=0, d[v]=oo với v!=1
Duyệt giống thuật toán Dijkstra, mỗi lần sẽ chọn đỉnh d[u] tối thiểu và không thể tối ưu d[u] được nữa. Ta sẽ chọn 
đỉnh d[v] là hành xóm của u là cạnh thuộc thời điểm x, chúng ta sẽ tìm vị trí i nhỏ nhất sao cho a[i]=x và d[u]<i. 
Sau đó d[v]=min(d[v], i). Để tìm vị trí i ta sẽ lưu chỉ xuất hiện số của từng thời điểm và chặt nhị phân.
*/

ll n, t, k, d[200005];
vector<pair<ll, ll>> adj[200005];
vector<ll> moments[200005];

void solve()
{
    cin>>n>>t;
    for (ll i=1; i<=t; i++)
    {
        ll m; cin>>m;
        for (ll j=0; j<m; j++)
        {
            ll u, v; cin>>u>>v;
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }
    }

    cin>>k;
    for (ll i=1; i<=k; i++)
    {
        ll x; cin>>x;
        moments[x].push_back(i);
    }

    for (ll i=1; i<=n; i++) d[i]=1e18;
    d[1]=0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto [du, u]=pq.top();     
        pq.pop();
        if (du!=d[u]) continue;
        for (auto [v, x]: adj[u]) 
        {
            ll i=upper_bound(moments[x].begin(), moments[x].end(), du)-moments[x].begin();
            if (i==moments[x].size()) continue;
            if (moments[x][i]<d[v])
            {
                d[v]=moments[x][i];
                pq.push({d[v], v});
            }
        }
    }
    if (d[n]==1e18) d[n]=-1;
    cout<<d[n];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}