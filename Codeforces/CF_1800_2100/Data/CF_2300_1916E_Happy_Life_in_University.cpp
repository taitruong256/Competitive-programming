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
Cho một cây n đỉnh n-1 cạnh, mỗi đỉnh có một màu col[i].
Hỏi giá trị lớn nhất của f(u, v)=diff(u, lca(u, v))*diff(v, lca(u, v)) - diff(u, v) là số màu riêng biệt trên đường đi đơn u->v

Input
4
2
1
1 2
7
1 1 2 2 3 3
6 5 2 3 6 5 6
13
1 1 1 2 2 2 3 3 4 5 6 6
2 2 2 1 4 9 7 2 5 2 1 11 2
12
1 1 1 2 2 3 4 4 7 7 6
11 2 1 11 12 8 5 8 8 5 11 7
Output
2
9
9
12

All recreations are colored. The same colors mean that the activities in the recreations match. Consider the pair of vertices (11,12)
, lca(11,12)=1. Write down all activities on the path from 11 to 1 — [11,5,1,11], among them there are 3 different activities
, so diff(11,1)=3. Also write down all activities on the path from 12 to 1 — [7,8,2,11]
, among them there are 4 different activities, so diff(12,1)=4. We get that f(11,12)=diff(12,1)⋅diff(11,1)=4⋅3=12
, which is the answer for this tree. It can be shown that a better answer is impossible to obtain.

Ý tưởng:
Với mỗi đỉnh u là gốc, ta sẽ tìm hai đỉnh v, w thuộc cây con gốc u sao cho diff(v, u) lớn nhất và diff(w, u) lớn nhì.
Cập nhật lại đáp án ans=max(ans, diff(u, v)*diff(u, w)).
Để tìm diff(v, u) lớn nhất dùng segment tree lazy + euler tour, với mỗi đỉnh u ta sẽ cộng 1 trong đoạn [tin[u], tout[u]] và 
trừ 1 trong các đoạn [tin[v], tout[v]] với v nằm trong cây con gốc u và v cùng màu với u.
*/

struct segment_tree_lazy
{
    vector<ll> tree, lazy;
    ll n;

    void init(ll _n)
    {
        n=_n;
        tree.resize(0);
        lazy.resize(0);
        tree.resize(4*n+5);
        lazy.resize(4*n+5);
    }

    ll opt(ll x, ll y)
    {
        return max(x, y);
    }

    void down(ll id)
    {
        ll t=lazy[id];
        tree[id*2]+=t;
        lazy[id*2]+=t;
        tree[id*2+1]+=t;
        lazy[id*2+1]+=t;
        lazy[id]=0;
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        down(id);
        return opt(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if (l>v || r<u) return;
        if (u<=l && r<=v) 
        {
            tree[id]+=val;
            lazy[id]+=val;
            return;
        }
        ll mid=(l+r)/2;
        down(id);
        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
};

ll n, col[300005], tin[300005], tout[300005], timedfs=0, ans=0, pre_col[300005];
vector<ll> adj[300005], nxt_col[300005];
segment_tree_lazy seg;

void euler_tour(ll u, ll p)
{
    tin[u]=++timedfs;
    ll pre=pre_col[col[u]];  //lưu đỉnh cha cùng màu với u trước khi chuyển sang nhánh khác.
    if (pre!=-1)
        nxt_col[pre].push_back(u);
    pre_col[col[u]]=u;
    for (ll v: adj[u]) if (v!=p)
        euler_tour(v, u);
    tout[u]=timedfs;
    pre_col[col[u]]=pre;  //gán lại đỉnh cha cùng màu với u.
}

void calc(ll u, ll p)
{
    vector<ll> cand;
    for (ll v: adj[u]) if (v!=p)
        calc(v, u);
    seg.update(1, 1, n, tin[u], tout[u], 1);
    for (ll v: nxt_col[u])
        seg.update(1, 1, n, tin[v], tout[v], -1);
    ans=max(ans, seg.query(1, 1, n, tin[u], tout[u]));
    for (ll v: adj[u]) if (v!=p)
        cand.push_back(seg.query(1, 1, n, tin[v], tout[v]));
    sort(cand.begin(), cand.end(), greater<ll>());
    if (cand.size()>=2) ans=max(ans, cand[0]*cand[1]);
}

void solve()
{
    cin>>n;
    seg.init(n);
    for (ll i=1; i<=n; i++) pre_col[i]=-1;
    for (ll i=2; i<=n; i++)
    {
        ll p; cin>>p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    for (ll i=1; i<=n; i++) cin>>col[i];
    euler_tour(1, -1);
    calc(1, -1);
    cout<<ans<<endl;
    ans=timedfs=0;
    for (ll i=1; i<=n; i++) pre_col[i]=-1, adj[i].clear(), nxt_col[i].clear();
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