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
Cho một cây n đỉnh n-1 cạnh. (n<=10^5)
Bạn cần tô màu một số cạnh sao cho với mỗi k (k<=20) cặp (a[i], b[i]) có ít nhất 1 cạnh được tô màu
trên đường đi từ a[i] đến b[i].
Tính số cạnh ít nhất cần tô màu

3
4
1 2
2 3
2 4
2
1 3
4 1
6
1 2
3 1
6 1
5 2
4 2
3
3 1
3 6
2 6
5
1 2
2 3
3 4
4 5
4
1 2
2 3
3 4
4 5

Note:
Note
In the first test case, Sasha could have colored only one edge (1,2). Then, there would be at least one colored edge on the simple path between vertices 1 and 3, and vertices 4 and 1.
https://espresso.codeforces.com/3f7d6ce35b22623c0032d394977870094ba2408a.png

In the second test case, Sasha could have colored the edges (1,6) and (1,3).
https://espresso.codeforces.com/18abe115a6e9ef0c464030e3f3fffb4349cdecae.png

Ý tưởng:
Xét từng cạnh u và p[u], đánh dấu tập s[i] các cặp đỉnh mà nó bao trùm.
Sẽ có tối đa O(K) bộ khác nhau (vì chúng ta chỉ quan tâm đến những cạnh nén trong k cặp đỉnh). (Không biết chính xác bao nhiêu nhưng nó sẽ không quá 5*k)
Gọi dp[mask] là số cạnh ít nhất cần tô màu trong tập hợp mask tương ứng vị trí bit=1.
dp[mask|s[i]]=min(dp[mask|s[i]], dp[mask]+1)
*/

vector<ll> adj[100005], nodes, dp;

void dfs(ll u, ll p)
{
    for (ll v: adj[u]) if (v!=p) 
    {
        dfs(v, u);
        nodes[u]^=nodes[v];
    }
}

void solve()
{
    ll n; cin>>n;
    nodes.resize(0);
    nodes.resize(n+5);
    for (ll i=0; i<n-1; i++)
    {
        ll u, v; cin>>u>>v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll k; cin>>k;
    dp.resize(0);
    dp.resize((1LL<<k)+5, 1e18);
    for (ll i=0; i<k; i++)
    {
        ll u, v; cin>>u>>v;
        --u;
        --v;
        nodes[u]^=(1LL<<i);
        nodes[v]^=(1LL<<i);
    }
    dfs(0, -1);
    sort(nodes.begin(), nodes.end());
    nodes.resize(unique(nodes.begin(), nodes.end())-nodes.begin());
    assert(nodes.size()<=5*k);
    dp[0]=0;
    for (ll mask=0; mask<(1LL<<k); mask++)
    {
        for (auto s: nodes) 
            dp[mask|s]=min(dp[mask|s], dp[mask]+1);
    }
    cout<<dp[(1LL<<k)-1]<<endl;
    for (ll i=0; i<n; i++) adj[i].clear();
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