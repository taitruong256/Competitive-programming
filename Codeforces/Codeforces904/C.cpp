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
                                Hãy hoàn thành công việc một cách cẩu thả nhất
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;

struct segment_tree_lazy
{
    vector<ll> lazy, mx, mn;
    ll n;

    segment_tree_lazy(){}
    segment_tree_lazy(ll _n)
    {
        n=_n;
        lazy.resize(4*n+5);
        mx.resize(4*n+5);
        mn.resize(4*n+5);
    }

    ll opt(ll x, ll y)
    {
        return x+y;
    }

    void down(ll id)
    {
        ll t=lazy[id];
        mx[id*2]+=t;
        mn[id*2]+=t;
        lazy[id*2]+=t;
        mx[id*2+1]+=t;
        mn[id*2+1]+=t;
        lazy[id*2+1]+=t;
        lazy[id]=0;
    }

    ll query_max(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return mx[id];
        ll mid=(l+r)/2;
        down(id);
        return max(query_max(id*2, l, mid, u, v), query_max(id*2+1, mid+1, r, u, v));
    }

    ll query_min(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 1e9;
        if (u<=l && r<=v) return mn[id];
        ll mid=(l+r)/2;
        down(id);
        return min(query_min(id*2, l, mid, u, v), query_min(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if (l>v || r<u) return;
        if (u<=l && r<=v) 
        {
            mx[id]+=val;
            mn[id]+=val;
            lazy[id]+=val;
            return;
        }
        ll mid=(l+r)/2;
        down(id);
        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);
        mx[id]=max(mx[id*2], mx[id*2+1]);
        mn[id]=min(mn[id*2], mn[id*2+1]);
    }
};

void solve()
{
    ll n, m; cin>>n>>m;
    pair<ll, ll> a[n+5];
    map<ll, vector<ll>> batdau, ketthuc;
    map<ll, ll> idx;
    vector<ll> diem;


    diem.push_back(1);
    diem.push_back(m);
    for (ll i=1; i<=n; i++) 
    {
        cin>>a[i].first>>a[i].second;
        auto [l, r]=a[i];
        diem.push_back(l);
        diem.push_back(r);
    }


    sort(diem.begin(), diem.end());
    diem.resize(unique(diem.begin(), diem.end())-diem.begin());
    for (ll i=0; i<diem.size(); i++) idx[diem[i]]=i+1;

    for (ll i=1; i<=n; i++)
    {
        auto [l, r]=a[i];
        batdau[idx[l]].push_back(idx[r]);
        ketthuc[idx[r]].push_back(idx[l]);
    }

    ll ans=0, sl=diem.size();
    segment_tree_lazy seg(sl);
    for (ll i: diem)
    {
        i=idx[i];
        for (ll j: batdau[i]) seg.update(1, 1, sl, i, j, 1);
        ll mx=seg.query_max(1, 1, sl, 1, sl);
        ll mn=seg.query_min(1, 1, sl, 1, sl);  
        ans=max(ans, mx-mn);  
        for (ll j: ketthuc[i]) seg.update(1, 1, sl, j, i, -1);
    }
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