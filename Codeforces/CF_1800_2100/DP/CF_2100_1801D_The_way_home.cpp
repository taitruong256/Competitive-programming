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
Cho n thành phố, m chuyến bay giữa các thành phố u, v có giá w. Ban đầu bạn đứng ở thành phố 1.
Bạn có thể biểu diễn ảo thuật ở thành phố i và kiếm được c[i] tiền.
Hỏi số buổi biểu diễn ít nhất để đi từ thành phố 1 đến thành phố n.

Input
4
4 4 2
7 4 3 1
1 2 21
3 2 6
1 3 8
2 4 11
4 4 10
1 2 10 1
1 2 20
2 4 30
1 3 25
3 4 89
4 4 7
5 1 6 2
1 2 5
2 3 10
3 4 50
3 4 70
4 1 2
1 1 1 1
1 3 2
4
24
10
-1

Y tuong:
Các buổi biểu diễn có thể hoãn lại. Khi chúng ta không đủ tiền để đến thành phố v, chúng ta có thể biểu diễn ở một thành phố u trước đó (mà số tiền kiếm được là nhiều nhất
trên đường đi từ 1->u->v).
Gọi dp[u][id]=(min show, max money): u là đỉnh hiện tại, id là chỉ số đỉnh có số tiền kiếm được từ buổi biểu diễn lớn nhất. Đáp án tối ưu là giảm thiểu buổi biểu 
diễn trước đó, tối đa hóa số tiền.
Có thể dùng Dijkstra + dp để tính.
*/

ll n, m, s, c[805];
vector<pair<ll, ll>> adj[805];
pair<ll, ll> dp[805][805];

struct info
{
    ll show, remain, u, id;
    bool operator <(const info &other) const
    {
        if (show==other.show)
            return remain<other.remain;
        return show>other.show;
    }
};

bool comp(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    if (a.first==b.first) return a.second>b.second;
    return a.first<b.first;
}

void solve()
{
    cin>>n>>m>>s;
    for (ll i=1; i<=n; i++) cin>>c[i];
    for (ll i=1; i<=m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
    }

    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) dp[i][j]={LLONG_MAX, -LLONG_MAX};

    priority_queue<info> pq;
    pq.push({0, s, 1, 1});
    dp[1][1]={0, s};
    while (!pq.empty())
    {
        auto [show, remain, u, id]=pq.top();
        pq.pop();
        if (make_pair(show, remain)!=dp[u][id]) continue;
        for (auto [v, w]: adj[u])
        {
            ll needs=(max(0LL, w-remain)+c[id]-1)/c[id];
            ll new_show=show+needs;
            ll new_remain=remain+needs*c[id]-w;
            ll new_id=c[v]>c[id]?v:id;
            if (comp(make_pair(new_show, new_remain), dp[v][new_id]))
            {
                dp[v][new_id]={new_show, new_remain};
                pq.push({new_show, new_remain, v, new_id});
            }
        }
    }

    ll ans=LLONG_MAX;
    for (ll i=1; i<=n; i++) ans=min(ans, dp[n][i].first);
    if (ans==LLONG_MAX) ans=-1;
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