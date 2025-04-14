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
                 Don't pray for an easy life, pray for the strength to endure a difficult one - Bruce Lee
 I fear not the man who has practiced 10,000 kicks once, but I fear the man who has practiced 1 kick 10,000 times - Bruce Lee
==============================================================================================================*/
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define ll long long
//tree<ll, null_type, less<ll>, rb_tree_tag,
//tree_order_statistics_node_update> T;             //find_by_order            order_of_key
#define endl '\n'
const ll mod = 1e9+7, inf = 1e9;
ll n, q, a[30005], ans[200005], res=0;

struct fenwick 
{
    vector<ll> bit;
    fenwick() {}
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
};

vector<pair<ll, ll>> ds[300005];

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    cin>>q;
    for (ll i=1; i<=q; i++)
    {
        ll l, r; cin>>l>>r;
        ds[r].push_back({l, i});
    }
    for (ll i=1; i<=n; i++) sort(ds[i].begin(), ds[i].end());

    map<ll, ll> prev;
    fenwick ft = fenwick(n);
    for (ll r=1; r<=n; r++)
    {
        if (prev[a[r]]!=0) ft.update(prev[a[r]], -1);
        prev[a[r]]=r;
        ft.update(r, 1);
        for (auto [l, i]: ds[r]) ans[i]=ft.query(r)-ft.query(l-1);  
    }
    for (ll i=1; i<=q; i++) cout<<ans[i]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    clock_t start = clock();
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<< double(end-start)/ double(CLOCKS_PER_SEC)<<endl;
    return 0;
}