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
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e18;

struct segment_tree
{
    vector<pair<ll, ll>> tree;
    ll n;

    segment_tree(){}
    segment_tree(ll _n)
    {
        n=_n;
        tree.resize(4*n+5, {inf, 0});
    }

    pair<ll, ll> opt(pair<ll, ll> x, pair<ll, ll> y)
    {
        if (x.first<y.first) return x;
        if (y.first<x.first) return y;
        return {x.first, (x.second+y.second)%mod};
    }

    pair<ll, ll> query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return {inf, 0};
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        return opt(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll pos, pair<ll, ll> v)
    {
        if (l>pos || r<pos) return;
        if (pos<=l && r<=pos) 
        {
            tree[id]=v;
            return;
        }
        ll mid=(l+r)/2;
        update(id*2, l, mid, pos, v);
        update(id*2+1, mid+1, r, pos, v);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
};

void solve()
{
    ll n; cin>>n;
    pair<ll, ll> a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i].second>>a[i].first;
    sort(a+1, a+n+1);
    segment_tree seg(n);
    for (ll i=n; i>=1; i--)
    {
        ll pos=lower_bound(a+i, a+n+1, make_pair(a[i].second, 0LL))-a;  
        if (pos>n) 
        {
            seg.update(1, 1, n, i, make_pair(a[i].first, 1LL));
        }
        else 
        {
            pair<ll, ll> best=seg.query(1, 1, n, pos, n);
            seg.update(1, 1, n, i, make_pair(best.first-(a[i].second-a[i].first), best.second));
        }
    }
    cout<<seg.query(1, 1, n, 1, n).second;
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