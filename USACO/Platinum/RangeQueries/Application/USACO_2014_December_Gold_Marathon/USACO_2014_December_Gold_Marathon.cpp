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

pair<ll, ll> p[100005];
ll n, q;

ll dist(ll x, ll y)
{
    return abs(p[x].first-p[y].first)+abs(p[x].second-p[y].second);
}

struct segment_tree_sum
{
    vector<ll> tree;
    ll n;

    segment_tree_sum(){}
    segment_tree_sum(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
        build(1, 1, n);
    }

    void build(ll id, ll l, ll r)
    {
        if (l==r)
        {
            if (l<=n-1) tree[id]=dist(l, l+1);
            else tree[id]=0;
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tree[id]=tree[id*2]+tree[id*2+1];
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>r) return 0;
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        return query(id*2, l, mid, u, v)+query(id*2+1, mid+1, r, u, v);
    }

    void update(ll id, ll l, ll r, ll pos)
    {
        if (!(1<=pos && pos<=n-1)) return;
        if (l>pos || r<pos) return;
        if (pos<=l && r<=pos) 
        {
            tree[id]=dist(pos, pos+1);
            return;
        }
        ll mid=(l+r)/2;
        update(id*2, l, mid, pos);
        update(id*2+1, mid+1, r, pos);
        tree[id]=tree[id*2]+tree[id*2+1];
    }
};

struct segment_tree_max
{
    vector<ll> tree;
    ll n;

    segment_tree_max(){}
    segment_tree_max(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
        build(1, 1, n);
    }

    void build(ll id, ll l, ll r)
    {
        if (l==r)
        {
            if (l<=n-2) tree[id]=dist(l, l+1)+dist(l+1, l+2)-dist(l, l+2);
            else tree[id]=0;
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tree[id]=max(tree[id*2], tree[id*2+1]);
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>r) return 0;
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        return max(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll pos)
    {
        if (!(1<=pos && pos<=n-2)) return;
        if (l>pos || r<pos) return;
        if (pos<=l && r<=pos) 
        {
            tree[id]=dist(pos, pos+1)+dist(pos+1, pos+2)-dist(pos, pos+2);
            return;
        }
        ll mid=(l+r)/2;
        update(id*2, l, mid, pos);
        update(id*2+1, mid+1, r, pos);
        tree[id]=max(tree[id*2], tree[id*2+1]);
    }
};

void solve()
{
    setIO("marathon");
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>p[i].first>>p[i].second;
    segment_tree_sum segsum(n);
    segment_tree_max segmax(n);
    while (q--)
    {
        char c; cin>>c;
        if (c=='Q') 
        {
            ll l, r; cin>>l>>r;
            cout<<segsum.query(1, 1, n, l, r-1)-segmax.query(1, 1, n, l, r-2)<<endl;
        }
        else 
        {
            ll pos, x, y; cin>>pos>>x>>y;
            p[pos].first=x;
            p[pos].second=y;
            for (ll i=pos-1; i<=pos; i++) segsum.update(1, 1, n, i);
            for (ll i=pos-2; i<=pos; i++) segmax.update(1, 1, n, i);
        }
    }
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