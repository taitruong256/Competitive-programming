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
ll a[500005];

struct segment_tree_nangcao
{
    ll n;
    vector<ll> tree;
    segment_tree_nangcao(){}
    segment_tree_nangcao(ll _n)
    {
        n=_n;
        tree.resize(2*n+5);
        for (ll i=0; i<n; i++) tree[i+n]=a[i+1];
        build();
    }
    void build()
    {
        for (ll i=n-1; i>=0; i--) tree[i]=max(tree[i<<1], tree[i<<1|1]);
    }
    ll query(ll l, ll r)
    {
        ll ans=0;
        for (l+=n, r+=n; l<=r; l>>=1, r>>=1) 
        {
            if (l&1) ans=max(ans, tree[l++]);
            if (!(r&1)) ans=max(ans, tree[r--]);
        }
        return ans;
    }
    void update(ll i, ll val)
    {
        for (tree[i+n]=val; i>1; i>>=1) tree[i>>1]=max(tree[i], tree[i^1]);
    }
};

void solve()
{
    ll n, m; cin>>n>>m;  
    while (m--)
    {
        ll l, r, v; cin>>l>>r>>v;
        a[l]+=v;
        a[r+1]-=v;
    }
    for (ll i=1; i<=n; i++) a[i]+=a[i-1];
    segment_tree_nangcao seg=segment_tree_nangcao(n);
    ll q; cin>>q;
    while (q--)
    {
        ll l, r; cin>>l>>r;
        cout<<seg.query(l-1, r-1)<<endl;
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