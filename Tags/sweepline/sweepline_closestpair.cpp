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
const ll inf = 1e18;
struct point 
{
    ll x, y, id;

    bool operator < (point other)
    {
        if (x==other.x) return y<other.y;
        return x<other.x;
    }
};

bool cmp(point a, point b)
{
    if (a.y==b.y) return a.x<b.x;
    return a.y<b.y;
};

ll dist(point a, point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

void solve()
{
    ll n; cin>>n;
    point a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i].x>>a[i].y, a[i].id=i;
    sort(a+1, a+n+1);
    set<point, decltype(&cmp)> st(&cmp);
    st.insert(a[1]);
    ll l=1, d=inf;
    pair<ll, ll> pos;
    for (ll i=2; i<=n; i++)
    {
        ll dd=ceil(sqrt(d));
        while (l<i && a[i].x-a[l].x>dd) st.erase(a[l++]);
        auto low=st.lower_bound({-inf, a[i].y-dd, 0LL});
        auto hight=st.upper_bound({-inf, a[i].y+dd, 0LL});
        for (auto it=low; it!=hight; it++)  
            if (dist(a[i], *it)<d) d=dist(a[i], *it), pos={(*it).id, a[i].id};
        st.insert(a[i]);
    }   
    if (pos.first>pos.second) swap(pos.first, pos.second);
    cout<<pos.first-1<<" "<<pos.second-1<<" ";
    cout << fixed << setprecision(6) << (double)sqrt((double)d);
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