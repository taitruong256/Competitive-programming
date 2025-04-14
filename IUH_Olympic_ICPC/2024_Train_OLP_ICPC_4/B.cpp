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

ll n, ans[200005];
pair<pair<ll, ll>, pair<ll, ll>> a[200005];
vector<ll> v;

ll get_id(ll x)
{
    return lower_bound(v.begin(), v.end(), x)-v.begin()+1;
}

struct segment_tree
{
    vector<ll> tree;
    ll n;

    segment_tree(){}
    segment_tree(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
    }

    ll opt(ll x, ll y)
    {
        return x+y;
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        return opt(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll pos, ll v)
    {
        if (l>pos || r<pos) return;
        if (pos<=l && r<=pos) 
        {
            tree[id]+=v;
            return;
        }
        ll mid=(l+r)/2;
        update(id*2, l, mid, pos, v);
        update(id*2+1, mid+1, r, pos, v);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
};

bool comp(pair<pair<ll, ll>, pair<ll, ll>> a, pair<pair<ll, ll>, pair<ll, ll>> b)
{
    if (a.first.second==b.first.second)
        return a.first.first<b.first.first;
    return a.first.second<b.first.second;
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) 
    {
        ll l, r, k, id; cin>>l>>r>>k; id=i;
        a[i]={{l, r}, {k, id}};
        v.push_back(l);
        v.push_back(r);
        v.push_back(l+k-1);
        v.push_back(r-k+1);
    }

    sort(a+1, a+n+1);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end())-v.begin());
    for (auto i: v) cout<<i<<" "<<get_id(i)<<endl; cout<<endl;
    
    for (ll i=1; i<=n; i++) ans[i]=0;
    segment_tree seg1(4*n);
    for (ll i=1; i<=n; i++)
    {
        auto [fi, se]=a[i];
        auto [l, r]=fi;
        auto [k, id]=se;
        ans[id]+=seg1.query(1, 1, 4*n, 1, get_id(l+k-1));
        seg1.update(1, 1, 4*n, get_id(r), 1);   
    }
    for (ll i=1; i<=n; i++) cout<<ans[i]<<" "; cout<<endl;

    for (ll i=1; i<=n; i++) ans[i]=0;
    sort(a+1, a+n+1, comp);
    segment_tree seg2(4*n);
    for (ll i=n; i>=1; i--)
    {
        auto [fi, se]=a[i];
        auto [l, r]=fi;
        auto [k, id]=se;
        ans[id]+=seg2.query(1, 1, 4*n, get_id(r-k+1), 4*n);
        cerr<<l<<" "<<r<<endl;
        for (ll x=1; x<=4*n; x++) cerr<<seg2.query(1, 1, 4*n, x, x)<<" "; cerr<<endl;
        cerr<<get_id(l)<<" "<<get_id(r-k+1)<<endl;
        seg2.update(1, 1, 4*n, get_id(l), 1);
    }
    for (ll i=1; i<=n; i++) cout<<ans[i]<<" "; cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}