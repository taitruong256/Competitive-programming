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

ll n, k, a[200005];

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

    ll opt(ll x, ll y)
    {
        return x+y;
    }

    void down(ll id, ll l, ll r)
    {
        ll t=lazy[id], mid=(l+r)/2;
        tree[id*2]+=t*(mid-l+1);
        lazy[id*2]+=t;
        tree[id*2+1]+=t*(r-mid);
        lazy[id*2+1]+=t;
        lazy[id]=0;
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        down(id, l, r);
        return opt(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if (l>v || r<u) return;
        if (u<=l && r<=v) 
        {
            tree[id]+=val*(r-l+1);
            lazy[id]+=val;
            return;
        }
        ll mid=(l+r)/2;
        down(id, l, r);
        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
};

void solve()
{
    cin>>n>>k;
    for (ll i=1; i<=n; i++) cin>>a[i];
    ll mx=*max_element(a+1, a+n+1);
    vector<pair<ll, ll>> range;
    for (ll i=1; i<=n; i++)
    {
        ll t=(mx-a[i])/(2*k);
        ll l=a[i]+t*2*k;
        ll r=l+k-1;
        range.push_back({l, r});
        range.push_back({l+2*k, r+2*k});
    }
    ll minl=1e18, maxr=0;
    for (auto [l, r]: range) minl=min(minl, l), maxr=max(maxr, r);
    ll len=maxr-minl+1;
    segment_tree_lazy seg(len);
    for (auto [l, r]: range) seg.update(1, 1, len, l-minl+1, r-minl+1, 1);
    for (ll i=minl; i<=maxr; i++) if (seg.query(1, 1, len, i-minl+1, i-minl+1)==n) 
    {
        cout<<i<<endl;
        return;
    }
    cout<<-1<<endl;
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