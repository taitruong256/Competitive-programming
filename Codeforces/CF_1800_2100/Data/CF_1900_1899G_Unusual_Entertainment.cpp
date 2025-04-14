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
Cho một cây n đỉnh n-1 cạnh và hoán vị p.
Có q truy vấn dạng (l, r, x): trong đoạn [a[p1], a[p2], ..., a[pn]] có tồn tại con của x hay không?

Input
3
3 5
1 2
2 3
1 2 3
1 2 2
1 2 3
2 3 1
1 2 3
2 3 3
10 10
2 6
2 7
2 4
1 7
2 8
10 6
8 5
9 4
3 4
10 2 5 9 1 7 6 4 3 8
8 9 8
7 8 1
7 10 6
4 8 9
5 5 10
7 10 1
9 9 2
9 10 6
6 6 2
10 10 6
1 1
1
1 1 1
Output
YES
NO
YES
NO
YES

NO
YES
YES
YES
NO
YES
YES
NO
NO
NO

YES

Ý tưởng:
DFS euler tour để tìm thời gian bắt đầu dfs tin[u] và thời gian kết thúc dfs tout[u] của u.
Đỉnh v sẽ là con của u nếu tin[u]<=tin[v]<=tout[v]<=tout[u].
=> Để tìm có con của u trong đoạn hay không ta dùng merge sort tree/persistent segment tree/wavelet tree với a[i]=tin[p[i]]

*/

ll n, q, tin[100005], tout[100005], timedfs;
vector<ll> adj[100005];

void dfs(ll u, ll p)
{
    tin[u]=++timedfs;
    for (ll v: adj[u]) if (v!=p)
    {
        dfs(v, u);
    }
    tout[u]=timedfs;
}

struct segment_tree_vector
{
    ll n;
    vector<ll> a, p;
    vector<vector<ll>> tree;
    segment_tree_vector(){}
    segment_tree_vector(ll _n, vector<ll> _a, vector<ll> _p)
    {
        n=_n;
        a=_a;
        p=_p;
        tree.resize(4*n+5);
        build(1, 1, n);
    }
    vector<ll> opt(vector<ll> a, vector<ll> b)
    {
        ll i=0, j=0;
        vector<ll> v;
        while (i<a.size() && j<b.size())
        {
            if (a[i]<b[j]) v.push_back(a[i++]);
            else v.push_back(b[j++]);
        }
        while (i<a.size()) v.push_back(a[i++]);
        while (j<b.size()) v.push_back(b[j++]);
        return v;
    }
    void build(ll id, ll l, ll r)
    {
        if (l==r)
        {
            tree[id].push_back(a[p[l-1]-1]);
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
    ll query(ll id, ll l, ll r, ll u, ll v, ll k)   //đếm bao nhiêu phần tử đoạn [l, r] >=k
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id].size()-(lower_bound(tree[id].begin(), tree[id].end(), k)-tree[id].begin());
        ll mid=(l+r)/2;
        return query(id*2, l, mid, u, v, k)+query(id*2+1, mid+1, r, u, v, k);
    }
};

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    vector<ll> v, p(n);
    for (ll i=1; i<=n; i++) v.push_back(tin[i]);
    for (ll i=1; i<=n; i++) cin>>p[i-1];
    segment_tree_vector seg(n, v, p);
    while (q--)
    {
        ll l, r, u; cin>>l>>r>>u; 
        ll ans=seg.query(1, 1, n, l, r, tin[u])-seg.query(1, 1, n, l, r, tout[u]+1);
        if (ans>0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    cout<<endl;
    timedfs=0;
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