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
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 998244353;
ll n, q, a[500005], b[500005];

struct segment_tree
{
    struct node { ll x, y; };
    vector<node> tree;
    ll n;

    void init(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
        build(1, 0, n-1);
    }

    node merge(node a, node b)
    {
        return {(a.x*b.x)%mod, (b.x*a.y+b.y)%mod};
    }

    void build(ll id, ll l, ll r)
    {
        if (l==r)
        {
            tree[id]={a[l], b[l]};
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tree[id]=merge(tree[id*2], tree[id*2+1]);
    }

    node getvalue(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return {1, 0};
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        return merge(getvalue(id*2, l, mid, u, v), getvalue(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll pos, ll x, ll y)
    {
        if (l>pos || r<pos) return;
        if (pos<=l && r<=pos) 
        {
            tree[id]={x, y};
            return;
        }
        ll mid=(l+r)/2;
        update(id*2, l, mid, pos, x, y);
        update(id*2+1, mid+1, r, pos, x, y);
        tree[id]=merge(tree[id*2], tree[id*2+1]);
    }
};
segment_tree seg;

void solve()
{
    cin>>n>>q;
    for (ll i=0; i<n; i++) cin>>a[i]>>b[i];
    seg.init(n);
    while (q--)
    {
        ll type; cin>>type;
        if (type==0)
        {
            ll pos, x, y; cin>>pos>>x>>y;
            seg.update(1, 0, n-1, pos, x, y);
        }
        else 
        {
            ll l, r, x; cin>>l>>r>>x;
            auto [A, B]=seg.getvalue(1, 0, n-1, l, r-1);
            cout<<(A*x+B)%mod<<endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}