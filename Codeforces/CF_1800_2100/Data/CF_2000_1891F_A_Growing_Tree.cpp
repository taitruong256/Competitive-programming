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
vector<ll> adj[500005];
ll q, timein[500005], timeout[500005], timedfs=0;

/*
Cho cây ban đầu có một đỉnh gốc là 1.
Có q truy vấn:
    -Loại 1: thêm một con sz+1 vào đỉnh u. (sz là kích thước cây hiện tại)
    -Loại 2: cộng x vào tất cả con hiện tại của đỉnh u.

Input
3
9
2 1 3
1 1
2 2 1
1 1
2 3 2
1 3
2 1 4
1 3
2 3 2
5
2 1 1
1 1
2 1 -1
1 1
2 1 1
5
1 1
1 1
2 1 1
2 1 3
2 2 10
Output
7 5 8 6 2 
1 0 1 
4 14 4 

Ý tưởng:
Xử lý offline + euler tour
-Loại 1: Khi thêm con sz+1 vào đỉnh u thì ta gán lại giá trị tree[sz+1]=0 (bằng cách cộng -x vào đỉnh sz+1, x là giá trị hiện tại của sz+1)
         bằng cách đó ta sẽ ghi đè giá trị mới bằng 0.
-Loại 2: dùng segment tree update đoạn timein[u], timeout[u] cộng thêm x.
*/

struct segment_tree_lazy
{
    vector<ll> tree, lazy;
    ll n;

    segment_tree_lazy(){}
    segment_tree_lazy(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
        lazy.resize(4*n+5);
    }

    ll opt(ll x, ll y)
    {
        return x+y;
    }

    void down(ll id, ll l, ll r)
    {
        ll t=lazy[id];
        ll mid=(l+r)/2;
        tree[id*2]+=t*(mid-l+1);
        lazy[id*2]+=t;
        tree[id*2+1]+=t*(r-mid);
        lazy[id*2+1]+=t;
        lazy[id]=0;
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        down(id, l, r);
        return opt(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if (l>v || r<u) return;
        if (u<=l && r<=v) 
        {
            tree[id]+=val*(r-l+1);
            lazy[id]+=val;
            return;
        }
        ll mid=(l+r)/2;
        down(id, l, r);
        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
};

struct query
{
    ll type, u, v;
};

void euler_tour(ll u, ll p=0)
{
    timein[u]=++timedfs;
    for (auto v: adj[u]) if (v!=p) euler_tour(v, u);
    timeout[u]=timedfs;
}

void solve()
{
    cin>>q;
    vector<query> qry;
    while (q--)
    {
        ll type; cin>>type;
        if (type==1) 
        {
            ll u; cin>>u;
            qry.push_back({1, u, 0});
        }
        else 
        {
            ll u, v; cin>>u>>v;
            qry.push_back({2, u, v});
        }
    }
    ll sz=1;
    for (auto [type, u, v]: qry) if (type==1)
    {
        sz+=1;
        adj[u].push_back(sz);
    }
    euler_tour(1);
    segment_tree_lazy seg(sz);
    ll siz=1;
    for (auto [type, u, v]: qry)
    {
        if (type==1)
        {
            ++siz;
            ll x=seg.query(1, 1, sz, timein[siz], timein[siz]); //đoạn [timein[u], timein[u]] hoặc [timein[u], timeout[u]] đều được.
            seg.update(1, 1, sz, timein[siz], timein[siz], -x);
        } 
        else 
        {
            seg.update(1, 1, sz, timein[u], timeout[u], v);
        }
    }
    for (ll i=1; i<=sz; i++) cout<<seg.query(1, 1, sz, timein[i], timein[i])<<" "; cout<<endl;
     
    timedfs=0;
    for (ll i=1; i<=sz; i++) adj[i].clear();
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