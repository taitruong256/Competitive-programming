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
#define ll int
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
ll n, a[300005], lef[300005], rig[300005];
long long pref[300005];

struct segment_tree
{
    vector<pair<ll, ll>> tree;
    ll n;

    segment_tree(){}
    segment_tree(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
    }

    pair<ll, ll> opt(const pair<ll, ll> &x, const pair<ll, ll> &y)
    {
        if (x.first==y.first) return {x.first, x.second+y.second};
        if (x.first>y.first) return x;
        return y;
    }

    pair<ll, ll> query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return {0, 0};
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        return opt(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll pos, ll val)
    {
        if (l>pos || r<pos) return;
        if (pos<=l && r<=pos) 
        {
            tree[id]={val, 1};
            return;
        }
        ll mid=(l+r)/2;
        update(id*2, l, mid, pos, val);
        update(id*2+1, mid+1, r, pos, val);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
};

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) pref[i]=pref[i-1]+a[i];
    segment_tree seg(n);
    for (ll i=1; i<=n; i++) seg.update(1, 1, n, i, a[i]);
    for (ll i=1; i<=n; i++)
    {
        ll l=1, r=i-1, ans=1e9;
        while (l<=r)
        {
            ll mid=(l+r)/2;
            pair<ll, ll> it=seg.query(1, 1, n, mid, i-1);
            ll mx=it.first, cnt=it.second;
            long long sum=pref[i-1]-pref[mid-1];
            if ((cnt!=i-mid || mx>a[i]) && sum>a[i]) ans=mid, l=mid+1;
            else r=mid-1;
        }
        lef[i]=ans;
    }
    for (ll i=1; i<=n; i++)
    {
        ll l=i+1, r=n, ans=1e9;
        while (l<=r)
        {
            ll mid=(l+r)/2;
            pair<ll, ll> it=seg.query(1, 1, n, i+1, mid);
            ll mx=it.first, cnt=it.second;
            long long sum=pref[mid]-pref[i];
            if ((cnt!=mid-i || mx>a[i]) && sum>a[i]) ans=mid, r=mid-1;
            else l=mid+1;
        }
        rig[i]=ans;
    }
    for (ll i=1; i<=n; i++) 
    {
        ll ans=min(abs(i-lef[i]), abs(i-rig[i]));
        if (ans>1e8) cout<<-1<<" ";
        else cout<<ans<<" ";
    }
    cout<<endl;
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