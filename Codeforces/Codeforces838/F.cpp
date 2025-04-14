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
const ll maxn = 1e6+5;

struct fenwick
{
    ll n; 
    vector<ll> bit;

    fenwick(){}
    fenwick(ll _n)
    {
        n=_n;
        bit.resize(n+5);
    }

    void update(ll idx, ll val)
    {
        for (ll i=idx; i<=n; i+=-i&i) bit[i]+=val;
    }

    ll query(ll idx)
    {
        ll sum=0;
        for (ll i=idx; i>0; i-=-i&i) sum+=bit[i];
        return sum;
    }

    ll getsum(ll l, ll r)
    {
        if (l>r) return 0;
        return query(r)-query(l-1);
    }
};

struct segment_tree
{
    vector<ll> tree;
    ll n;

    segment_tree(){}
    segment_tree(ll _n)
    {
        n=_n;
        tree.resize(4*n+5, maxn);
    }

    ll getvalue(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return maxn;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        return min(getvalue(id*2, l, mid, u, v), getvalue(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll pos, ll v)
    {
        if (l>pos || r<pos) return;
        if (pos==l && r==pos) 
        {
            tree[id]=v;
            return;
        }
        ll mid=(l+r)/2;
        if (pos<=mid) update(id*2, l, mid, pos, v);
        else update(id*2+1, mid+1, r, pos, v);
        tree[id]=min(tree[id*2], tree[id*2+1]);
    }
};

ll n, k;
ll a[500005] ,dp[500005];
segment_tree seg(maxn);
fenwick ft(maxn);

ll calc()
{
    ll res=0;
    for (ll i=n; i>=1; i--)
    {
        ll j=seg.getvalue(1, 1, maxn, a[i]+1, a[i]+k);
        if (j<maxn) dp[i]=dp[j]+ft.getsum(a[i]+1, a[j]); 
        else dp[i]=0;
        res+=dp[i];
        seg.update(1, 1, maxn, a[i], i);
        ft.update(a[i], 1);
    }

    for (ll i=1; i<=n; i++) 
    {
        dp[i]=0;
        seg.update(1, 1, maxn, a[i], maxn);
        ft.update(a[i], -1);
    }
    return res;
}

void solve()
{
    cin>>n>>k;     
    map<ll, ll> cnt;
    ll ans=0;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=n; i>=1; i--)
    {
        ++cnt[a[i]];
        ans+=cnt[a[i]]; 
    }             
    ans+=calc();          
    reverse(a+1, a+n+1);
    ans+=calc();
    cout<<ans<<endl;
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