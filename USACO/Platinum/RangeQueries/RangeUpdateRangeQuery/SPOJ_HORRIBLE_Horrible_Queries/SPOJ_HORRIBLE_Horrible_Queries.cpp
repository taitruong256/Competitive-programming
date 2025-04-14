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
    void down(ll id, ll l, ll r)
    {
        ll t=lazy[id];
        if (t!=0)
        {
            ll mid=(l+r)/2;
            tree[id*2]+=t*(mid-l+1);
            lazy[id*2]+=t;
            tree[id*2+1]+=t*(r-mid);
            lazy[id*2+1]+=t;
            lazy[id]=0;
        }
    }
    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        down(id, l, r);
        return query(id*2, l, mid, u, v)+query(id*2+1, mid+1, r, u, v);
    }
    void update(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if (l>v || r<u) return;
        if (u<=l && r<=v) 
        {
            tree[id]+=(r-l+1)*val;
            lazy[id]+=val;
            return;
        }
        ll mid=(l+r)/2;
        down(id, l, r);
        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);
        tree[id]=tree[id*2]+tree[id*2+1];
    }
};

void solve()
{
    ll n, q; cin>>n>>q;
    segment_tree_lazy seg(n);
    while (q--)
    {
        ll type; cin>>type;
        if (type==0)
        {
            ll l, r, v; cin>>l>>r>>v;
            seg.update(1, 1, n, l, r, v);
        }
        else 
        {
            ll l, r; cin>>l>>r;
            cout<<seg.query(1, 1, n, l, r)<<endl;
        }
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}