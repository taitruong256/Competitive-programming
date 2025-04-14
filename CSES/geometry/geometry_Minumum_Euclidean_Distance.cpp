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
#define point pair<ll, ll>
#define X first
#define Y second
const ll mod = 1e9+7, inf = LLONG_MAX;

bool comp(point a, point b)
{
    if (a.Y==b.Y) return a.X<b.X;
    return a.Y<b.Y;
}

ll dist(point a, point b)
{
    return (a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y);
}

void solve()
{
    ll n; cin>>n;
    point a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i].X>>a[i].Y;
    sort(a+1, a+n+1, comp);
    ll j=1, d=inf;
    set<point> st;
    st.insert(a[1]);
    for (ll i=2; i<=n; i++)
    {
        ll dd=ceil(sqrt(d));
        while (j<i && a[j].Y<a[i].Y-dd) st.erase(a[j++]);
        auto lo=st.lower_bound({a[i].X-dd, -inf});
        auto hi=st.upper_bound({a[i].X+dd, -inf});
        for (auto it=lo; it!=hi; it++) d=min(d, dist(*it, a[i])); 
        st.insert(a[i]);  
    }
    cout<<d;
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