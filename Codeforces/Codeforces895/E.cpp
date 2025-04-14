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
ll n, a[100005], xr, q;
string s;

struct segment_tree_lazy
{
    vector<ll> tree, lazy, xr;
    ll n;

    segment_tree_lazy(){}
    segment_tree_lazy(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
        lazy.resize(4*n+5);
        xr.resize(4*n+5);
        build(1, 1, n);
    }

    ll opt(ll x, ll y)
    {
        return x^y;
    }

    void build(ll id, ll l, ll r)
    {
        if (l==r)
        {
            xr[id]=a[l];
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        xr[id]=opt(xr[id*2], xr[id*2+1]);
    }

    void down(ll id)
    {
        ll t=lazy[id];
        if (t!=0)
        {
            tree[id*2]=xr[id*2]^tree[id*2];
            lazy[id*2]^=1;
            tree[id*2+1]=xr[id*2+1]^tree[id*2+1];
            lazy[id*2+1]^=1;
            lazy[id]=0;
        }
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        down(id);
        return opt(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return;
        if (u<=l && r<=v) 
        {
            tree[id]=xr[id]^tree[id];
            lazy[id]^=1;
            return;
        }
        ll mid=(l+r)/2;
        down(id);
        update(id*2, l, mid, u, v);
        update(id*2+1, mid+1, r, u, v);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
};

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    cin>>s;
    segment_tree_lazy seg(n);
    for (ll i=1; i<=n; i++) if (s[i-1]=='1') seg.update(1, 1, n, i, i);
    cin>>q;
    while (q--)
    {
        ll type; cin>>type;
        if (type==1)
        {
            ll l, r; cin>>l>>r;
            seg.update(1, 1, n, l, r);
        }
        else 
        {
            ll g; cin>>g;
            if (g==1) cout<<seg.query(1, 1, n, 1, n)<<" ";
            else cout<<(seg.xr[1]^seg.tree[1])<<" ";
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