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
const ll mod = 1e9+7;

/*
Cải tiến từ phiên bản dễ.
Dùng segment tree để cập nhật dp nhanh hơn.
Ta sẽ duy trì segment tree từ dp[j=0->k]=inf. segment tree sẽ duy trì dp[i][j]: thời gian ít nhất chương 
trình cuối cùng trên CPU 1 là i, trên CPU 2 sẽ là j, dp[i][j] duy trì trong segment tree.
Ban 
*/

ll n, k;
ll a[300005], cold[300005], hot[300005];

struct segment_tree_lazy
{
    vector<ll> tree, lazy;
    ll n;

    segment_tree_lazy(){}
    segment_tree_lazy(ll _n)
    {
        n=_n;
        tree.resize(4*n+5, 1e18);
        lazy.resize(4*n+5);
    }

    ll opt(ll x, ll y)
    {
        return min(x, y);
    }

    void down(ll id)
    {
        ll t=lazy[id];
        tree[id*2]+=t;
        lazy[id*2]+=t;
        tree[id*2+1]+=t;
        lazy[id*2+1]+=t;
        lazy[id]=0;
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 1e18;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        down(id);
        return opt(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if (l>v || r<u) return;
        if (u<=l && r<=v) 
        {
            tree[id]+=val;
            lazy[id]+=val;
            return;
        }
        ll mid=(l+r)/2;
        down(id);
        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }

    void update_pos(ll id, ll l, ll r, ll pos, ll val)
    {
        if (l>pos || r<pos) return;
        if (pos<=l && r<=pos) 
        {
            tree[id]=val;
            lazy[id]=0;
            return;
        }
        ll mid=(l+r)/2;
        down(id);
        update_pos(id*2, l, mid, pos, val);
        update_pos(id*2+1, mid+1, r, pos, val);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
};

void solve()
{
    cin>>n>>k;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=k; i++) cin>>cold[i];
    for (ll i=1; i<=k; i++) cin>>hot[i];
    segment_tree_lazy seg(k+1);
    seg.update_pos(1, 0, k, 0, 0);
    for (ll i=1; i<=n; i++)
    {
        ll best=min(seg.query(1, 0, k, 0, k)+cold[a[i]], seg.query(1, 0, k, a[i], a[i])+hot[a[i]]);
        if (a[i]==a[i-1]) seg.update(1, 0, k, 0, k, hot[a[i]]);
        else seg.update(1, 0, k, 0, k, cold[a[i]]);
        seg.update_pos(1, 0, k, a[i-1], best);
    }
    cout<<seg.query(1, 0, k, 0, k)<<endl;
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