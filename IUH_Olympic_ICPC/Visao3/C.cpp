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
ll n, a[400005], ans;

struct segment_tree_max
{
    vector<pair<ll, ll>> tree;
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
            tree[id]={a[l], l};
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tree[id]=max(tree[id*2], tree[id*2+1]);
    }

    pair<ll, ll> getvalue(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return {0LL, 0LL};
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        return max(getvalue(id*2, l, mid, u, v), getvalue(id*2+1, mid+1, r, u, v));
    }
};
segment_tree_max stmax;

struct segment_tree_min
{
    vector<pair<ll, ll>> tree;
    ll n;

    segment_tree_min(){}
    segment_tree_min(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
        build(1, 1, n);
    }

    void build(ll id, ll l, ll r)
    {
        if (l==r)
        {
            tree[id]={a[l], l};
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tree[id]=min(tree[id*2], tree[id*2+1]);
    }

    pair<ll, ll> getvalue(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return {1e18, 0LL};
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        return min(getvalue(id*2, l, mid, u, v), getvalue(id*2+1, mid+1, r, u, v));
    }
};
segment_tree_min stmin;

void query_max(ll l, ll r)
{
    if (l>r) return;
    auto [mx, pos]=stmax.getvalue(1, 1, n, l, r);
    ll trai=pos-l+1, phai=r-pos+1, cnt=trai*phai;
    ans+=mx*cnt;         
    query_max(l, pos-1);
    query_max(pos+1, r);
}

void query_min(ll l, ll r)
{
    if (l>r) return;
    auto [mn, pos]=stmin.getvalue(1, 1, n, l, r);
    ll trai=pos-l+1, phai=r-pos+1, cnt=trai*phai;
    ans-=mn*cnt;      
    query_min(l, pos-1);
    query_min(pos+1, r);
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    stmax=segment_tree_max(n);
    stmin=segment_tree_min(n);
    query_max(1, n);
    query_min(1, n);
    cout<<ans;
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