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
ll bit[1030][1030];
ll n, q, h[100005], w[100005];

void update(ll x, ll y, ll val)
{
    for (ll i=x; i<=1000; i+=-i&i)
        for (ll j=y; j<=1000; j+=-j&j) bit[i][j]+=val;
}

ll query(ll x, ll y)
{
    ll sum=0;
    for (ll i=x; i>0; i-=-i&i)
        for (ll j=y; j>0; j-=-j&j) sum+=bit[i][j];
    return sum;
}

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>h[i]>>w[i];
    for (ll i=1; i<=n; i++) update(h[i], w[i], h[i]*w[i]);
    while(q--)
    {
        ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        cout<<query(x2-1, y2-1)-query(x1, y2-1)-query(x2-1, y1)+query(x1, y1)<<endl;
    }
    for (ll i=1; i<=n; i++) update(h[i], w[i], -h[i]*w[i]);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    clock_t start = clock();
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<< double(end-start)/ double(CLOCKS_PER_SEC)<<endl;
    return 0;
}