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
const ll mod = 1e9+7;
ll a[200005];

ll sum_digit(ll x)
{
    ll ans=0;
    while (x>0)
    {
        ans+=x%10;
        x/=10;
    }
    return ans;
}

struct segment_tree
{
    vector<ll> tree, value;
    ll n;

    segment_tree(){}
    segment_tree(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
        value.resize(4*n+5);
        build(1, 1, n);
    }

    void build(ll id, ll l, ll r)
    {
        if (l==r)
        {
            value[id]=a[l];
            tree[id]=(value[id]>9);
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tree[id]=tree[id*2]+tree[id*2+1];
    }

    ll getvalue(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return value[id];
        ll mid=(l+r)/2;
        return getvalue(id*2, l, mid, u, v)+getvalue(id*2+1, mid+1, r, u, v);
    }

    void update(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return;
        if (tree[id]==0) return;
        if (l==r) 
        {
            value[id]=sum_digit(value[id]);
            tree[id]=(value[id]>9);
            return;
        }
        ll mid=(l+r)/2;
        update(id*2, l, mid, u, v);
        update(id*2+1, mid+1, r, u, v);
        tree[id]=tree[id*2]+tree[id*2+1];
    }
};

void solve()
{
    ll n, q; cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    segment_tree st(n);
    while (q--)
    {
        ll t; cin>>t;
        if (t==1)
        {
            ll l, r; cin>>l>>r;
            st.update(1, 1, n, l, r);
        }
        else
        {
            ll pos; cin>>pos;
            cout<<st.getvalue(1, 1, n, pos, pos)<<endl;
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
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}