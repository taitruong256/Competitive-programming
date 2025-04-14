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
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll inf = 1e18;
const ll mod = 1e9+7;

void setIO(string s)
{
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}

ll bit(ll x, ll p)
{
    if (x&(1LL<<p)) return 1;
    return 0;
}

ll n, q;

struct segment_tree
{
    struct node 
    {
        vector<ll> val;
        node ()
        {
            val.resize(4, 0);
        };
        node (ll x)
        {
            val.resize(4, 0);
            val[3]=x;
        }
    };

    node merge(node a, node b)
    {
        node new_node;
        for (ll i=0; i<16; i++) if (bit(i, 1)!=1 || bit(i, 2)!=1)
        {
            ll id=bit(i,3)*2+bit(i, 0), l=bit(i, 3)*2+bit(i, 2), r=bit(i, 1)*2+bit(i, 0);
            new_node.val[id]=max(new_node.val[id], a.val[l]+b.val[r]);
        }
        return new_node;
    }
    vector<node> tree;
    ll n;

    segment_tree(){}
    segment_tree(ll _n)
    {
        n=_n;
        tree.resize(4*n+5, node());
    }

    node query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return node();
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        return merge(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll pos, ll v)
    {
        if (l>pos || r<pos) return;
        if (pos<=l && r<=pos) 
        {
            tree[id]=node(v);
            return;
        }
        ll mid=(l+r)/2;
        update(id*2, l, mid, pos, v);
        update(id*2+1, mid+1, r, pos, v);
        tree[id]=merge(tree[id*2], tree[id*2+1]);
    }
};

void solve()
{
    setIO("optmilk");
    cin>>n>>q;
    segment_tree seg(n);
    for (ll i=1; i<=n; i++)
    {
        ll x; cin>>x;
        seg.update(1, 1, n, i, x);
    }
    
    ll ans=0;
    while (q--)
    {
        ll pos, val; cin>>pos>>val;
        seg.update(1, 1, n, pos, val);
        vector<ll> v=seg.tree[1].val;
        ll mx=0;
        for (auto i: v) mx=max(mx, i);
        ans+=mx;
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}