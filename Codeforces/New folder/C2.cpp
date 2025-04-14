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
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
     Laziness is only temporary comfort. The future will regret that day. Don't fall into the trap of comfort.
                The most beautiful meeting in this world is meeting the best version of yourself.
                          Practice doing things you don't like but are useful to you
                                   Success is born from problem solving
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, q, a[400005], b[400005], pos[400005];
set<ll> first_pos[400005];
Tree<pair<ll, ll>> st;

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
        build(1, 1, n);
    }

    ll opt(ll x, ll y)
    {
        return max(x, y);
    }

    void build(ll id, ll l, ll r)
    {
        if (l==r)
        {
            tree[id]=a[l];
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
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

void solve()
{
    cin>>n>>m>>q;
    for (ll i=1; i<=n; i++) 
    {
        cin>>a[i];
        pos[a[i]]=i;
    }
    
    for (ll i=1; i<=m; i++) cin>>b[i];
    for (ll i=m+1; i<=m+n; i++) b[i]=a[i-m];
    for (ll i=1; i<=n+m; i++) b[i]=pos[b[i]];
    for (ll i=1; i<=n+m; i++) first_pos[b[i]].insert(i);

    for (ll i=1; i<=n; i++) st.insert({i, *first_pos[i].begin()});
    segment_tree_lazy seg(n);
    for (ll i=1; i<=n; i++) seg.update(1, 1, n, i, i, -i);


    while (q--)
    {
        ll s, t; cin>>s>>t; t=pos[t];
        ll l=st.order_of_key({b[s], s});
        st.erase({b[s], *first_pos[b[s]].begin()});
        st.erase({t, *first_pos[t].begin()});
        first_pos[b[s]].erase(s);
        first_pos[t].insert(t);
        st.insert({b[s], *first_pos[b[s]].begin()});
        st.insert({t, *first_pos[t].begin()});
        
    }

    
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