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
                             Nothing is impossible, only you think it is impossible                 
                                     Try, try, try again until you succeed     
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
const double EPS = 1e-9;

struct events
{
    double x;
    ll y, y2, type;

    events(){}
    events(double _x, ll _y, ll _y2, ll _type)
    {
        x=_x;
        y=_y;
        y2=_y2;
        type=_type;
    }

    bool operator < (events other)
    {
        return x<other.x;
    }
};

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

    void update(ll pos, ll val)
    {
        for (ll i=pos; i<=n; i+=-i&i) bit[i]+=val;
    }

    ll getsum(ll pos)
    {
        ll ans=0;
        for (ll i=pos; i>0; i-=-i&i) ans+=bit[i];
        return ans;
    }

    ll query(ll l, ll r)
    {
        return getsum(r)-getsum(l-1);
    }
};

void solve()
{
    ll n; cin>>n;
    double blue_x1[n+5], blue_x2[n+5], blue_y[n+5];
    double red_x[n+5], red_y1[n+5], red_y2[n+5];
    for (ll i=0; i<n; i++) cin>>blue_x1[i]>>blue_x2[i]>>blue_y[i];
    for (ll i=0; i<n; i++) cin>>red_y1[i]>>red_y2[i]>>red_x[i];

    vector<double> compress_y;
    vector<events> v;
    for (ll i=0; i<n; i++) compress_y.push_back(blue_y[i]);
    for (ll i=0; i<n; i++) compress_y.push_back(red_y1[i]), compress_y.push_back(red_y2[i]);
    sort(compress_y.begin(), compress_y.end());
    for (ll i=0; i<n; i++) 
    {
        if (blue_x1[i]>blue_x2[i]) swap(blue_x1[i], blue_x2[i]);
        ll l=lower_bound(compress_y.begin(), compress_y.end(), blue_y[i])-compress_y.begin()+1;
        v.push_back(events(blue_x1[i]-EPS, l, 0LL, 1LL));
        v.push_back(events(blue_x2[i]+EPS, l, 0LL, 2LL));
    }
    for (ll i=0; i<n; i++) 
    {
        if (red_y1[i]>red_y2[i]) swap(red_y1[i], red_y2[i]);
        ll l=lower_bound(compress_y.begin(), compress_y.end(), red_y1[i])-compress_y.begin()+1;
        ll r=lower_bound(compress_y.begin(), compress_y.end(), red_y2[i])-compress_y.begin()+1;
        v.push_back(events(red_x[i], l, r, 3LL));
    }
    sort(v.begin(), v.end());
    fenwick ft = fenwick(3*n);
    ll ans=0;
    for (auto e: v)
    {
        // cout<<e.type<<" "<<e.x<<" "<<e.y<<" "<<e.y2<<endl;
        if (e.type==1) ft.update(e.y, 1);
        else if (e.type==2) ft.update(e.y, -1);
        else ans+=ft.query(e.y, e.y2);
    }
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