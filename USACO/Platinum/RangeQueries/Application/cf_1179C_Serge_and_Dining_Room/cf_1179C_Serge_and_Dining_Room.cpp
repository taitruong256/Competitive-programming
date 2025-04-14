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
const ll mod = 1e9+7;

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
    void down(ll id)
    {
        ll t=lazy[id];
        tree[id*2]+=t;
        lazy[id*2]+=t;
        tree[id*2+1]+=t;
        lazy[id*2+1]+=t;
        lazy[id]=0;
    }
    ll query(ll id, ll l, ll r)
    {
        if (l==r) return l;
        if (tree[id]<=0) return -1;
        ll mid=(l+r)/2;
        down(id);
        if (tree[id*2+1]>0) return query(id*2+1, mid+1, r);
        return query(id*2, l, mid);
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
        tree[id]=max(tree[id*2], tree[id*2+1]);
    }
};
segment_tree_lazy seg(1000000);
ll n, m, a[300005], b[300005];

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=n; i++)
    {
        cin>>a[i];
        seg.update(1, 1, 1e6, 1, a[i], 1);
    }
    for (ll i=1; i<=m; i++)
    {
        cin>>b[i];
        seg.update(1, 1, 1e6, 1, b[i], -1);
    }
    ll q; cin>>q;
    while (q--)
    {
        ll type, pos, val; cin>>type>>pos>>val;
        if (type==1)
        {
            seg.update(1, 1, 1e6, 1, a[pos], -1);
            a[pos]=val;
            seg.update(1, 1, 1e6, 1, a[pos], 1);
        }
        else 
        {
            seg.update(1, 1, 1e6, 1, b[pos], 1);
            b[pos]=val;
            seg.update(1, 1, 1e6, 1, b[pos], -1);
        }
        cout<<seg.query(1, 1, 1e6)<<endl;
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