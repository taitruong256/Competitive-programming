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
    vector<ll> sum, mx;
    ll n;

    segment_tree(){}
    segment_tree(ll _n)
    {
        n=_n;
        sum.resize(4*n+5);
        mx.resize(4*n+5);
    }

    void opt(ll id)
    {
        sum[id]=sum[id*2]+sum[id*2+1];
        mx[id]=max(mx[id*2], mx[id*2+1]);;
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return sum[id];
        ll mid=(l+r)/2;
        return query(id*2, l, mid, u, v)+query(id*2+1, mid+1, r, u, v);
    }

    void update_set(ll id, ll l, ll r, ll pos, ll v)
    {
        if (l>pos || r<pos) return;
        if (pos<=l && r<=pos) 
        {
            sum[id]=v;
            mx[id]=v;
            return;
        }
        ll mid=(l+r)/2;
        update_set(id*2, l, mid, pos, v);
        update_set(id*2+1, mid+1, r, pos, v);
        opt(id);
    }

    void update_mod(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if (r<u || l>v || mx[id]<val) return;
        if (l==r) 
        {
            sum[id]%=val;
            mx[id]%=val;
            return;
        }
        ll mid=(l+r)/2;
        update_mod(id*2, l, mid, u, v, val);
        update_mod(id*2+1, mid+1, r, u, v, val);
        opt(id);
    }
};
ll n, q, a[100005];

void solve()
{
    cin>>n>>q;
    segment_tree seg(n);
    for (ll i=1; i<=n; i++) 
    {
        cin>>a[i];
        seg.update_set(1, 1, n, i, a[i]);
    }
    while (q--)
    {
        ll type; cin>>type;
        if (type==1)
        {
            ll l, r; cin>>l>>r;
            cout<<seg.query(1, 1, n, l, r)<<endl;
        }
        else if (type==2)
        {
            ll l, r, x; cin>>l>>r>>x;
            seg.update_mod(1, 1, n, l, r, x);
        }
        else 
        {
            ll k, x; cin>>k>>x;
            seg.update_set(1, 1, n, k, x);
        }
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