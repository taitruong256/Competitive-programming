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
#define sz(x) (ll)(x.size())
const ll mod = 26;

struct segment_tree_lazy
{
    vector<ll> tree, lazy;
    ll n;

    void init(ll _n)
    {
        n=_n;
        tree.clear();
        tree.resize(4*n+5, 0);
        lazy.clear();
        lazy.resize(4*n+5, 0);
    }

    ll opt(ll x, ll y)
    {
        return (x+y)%mod;
    }

    void down(ll id, ll l, ll r)
    {
        ll t=lazy[id], mid=(l+r)/2;
        tree[id*2]+=t*(mid-l+1);
        tree[id*2]%=mod;
        lazy[id*2]+=t;
        lazy[id*2]%=mod;
        tree[id*2+1]+=t*(r-mid);
        tree[id*2+1]%=mod;
        lazy[id*2+1]+=t;
        lazy[id*2+1]%=mod;
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
            tree[id]%=mod;
            lazy[id]+=val;
            lazy[id]%=mod;
            return;
        }
        ll mid=(l+r)/2;
        down(id, l, r);
        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
} seg;

ll n, q;
string s;
set<ll> s2, s3;

void calc(ll l, ll r)
{
    l=max(1LL, l);
    r=min(r, n);
    for (ll i=l; i<=r; i++)
    {
        if (i+1<=r && seg.query(1, 1, n, i, i)==seg.query(1, 1, n, i+1, i+1)) s2.insert(i);
        else s2.erase(i);
        if (i+2<=r && seg.query(1, 1, n, i, i)==seg.query(1, 1, n, i+2, i+2)) s3.insert(i);
        else s3.erase(i);
    }
}

bool query(ll l, ll r)
{
    auto x=s2.lower_bound(l);
    if (x!=s2.end() && *x+1<=r) return false;
    auto y=s3.lower_bound(l);
    if (y!=s3.end() && *y+2<=r) return false;
    return true;
}

void solve()
{
    cin>>n>>q;
    string s; cin>>s; s=" "+s;
    seg.init(n);
    s2.clear();
    s3.clear();
    for (ll i=1; i<=n; i++) seg.update(1, 1, n, i, i, s[i]-'a');
    for (ll i=1; i<=n; i++)
    {
        if (i+1<=n && s[i]==s[i+1]) s2.insert(i);
        if (i+2<=n && s[i]==s[i+2]) s3.insert(i);
    }
    while (q--)
    {
        ll type; cin>>type;
        if (type==1)
        {
            ll l, r, x; cin>>l>>r>>x;
            x%=26;
            seg.update(1, 1, n, l, r, x);
            calc(l-5, l+5);
            calc(r-5, r+5);
        }
        else 
        {
            ll l, r; cin>>l>>r;
            if (query(l, r)==true) cout<<"YES\n";
            else cout<<"NO\n";
        }
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