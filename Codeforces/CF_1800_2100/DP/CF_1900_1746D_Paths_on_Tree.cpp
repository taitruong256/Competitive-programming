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
Cho cây n đỉnh n-1 cạnh, mỗi đỉnh có số điểm score[i].
Một tập tập k-đường đi đơn:
    -Xuất phát từ 1
    -Gọi c[i] là số đường đi qua đỉnh i, với mỗi (u, v) mà u, v có chung cha, |c[u]-c[v]|<=1.
Giá trị của tập k-đường đi đơn là sum(s[i]*c[i]).
Tìm giá trị lớn nhất.

Input
2
5 4
1 2 1 3
6 2 1 5 7
5 3
1 2 1 3
6 6 1 4 10
Output
54
56

Ý tưởng: dp + tham lam
Gọi dfs(u, k): tính giá trị lớn nhất của cây con gốc u, k đường đi qua đỉnh u.
    -Khi gọi dfs xuống cây con v của u, ta gọi dfs(v, k/child(u))
    -Lưu dp[u] là giá trị lớn nhất khi có thể có thêm một đường đi qua u.
    -Sắp sếp dp[v] tăng dần, chọn k%child(u) lớn nhất, gán dp[u]=candidates[k%child(u)+1]
*/

ll n, k, dp[200005], sum[200005], cost[200005], ans=0;
vector<ll> adj[200005];

void dfs(ll u, ll k)
{
    ll child=adj[u].size();
    if (child==0)
    {
        ans+=sum[u]*k;
        dp[u]=sum[u];
        return;
    }
    vector<ll> candidates;
    for (ll v: adj[u]) 
    {
        sum[v]=sum[u]+cost[v];
        dfs(v, k/child);
        candidates.push_back(dp[v]);
    }
    sort(candidates.begin(), candidates.end(), greater<ll>());
    for (ll i=0; i<k%child; i++) ans+=candidates[i];
    dp[u]=candidates[k%child];
}

void solve()
{
    cin>>n>>k;
    for (ll i=2; i<=n; i++)
    {
        ll p; cin>>p;
        adj[p].push_back(i);
    }
    for (ll i=1; i<=n; i++) cin>>cost[i];
    ans=0;
    sum[1]=cost[1];
    dfs(1, k);
    cout<<ans<<endl;
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