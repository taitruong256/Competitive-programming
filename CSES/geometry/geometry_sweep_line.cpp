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
const ll mod = 1e9+7, inf = 1e16, maxn=2e5+5;
ll bit[200005], n;
struct point
{
    ll type, st, fi, x;
    point(){}
    point(ll _type, ll _st, ll _fi, ll _x)
    {
        type=_type;
        st=_st;
        fi=_fi;
        x=_x;
    }
};
vector<point> v;

struct fenwick
{
    ll bit[maxn]={0};
    fenwick () 
    {
        for (ll i=0; i<maxn; i++) bit[i]=0;
    }
 
    void update(ll idx, ll val)
    {
        val=(val+mod)%mod;
        for (ll i=idx; i<maxn; i+=-i&i) bit[i]=(bit[i]+val)%mod;
    }
 
    ll query(ll idx)
    {
        ll sum=0;
        for (ll i=idx; i>0; i-=-i&i) sum=(sum+bit[i])%mod;
        return sum;
    }
} ft;

bool comp(point a, point b)
{
    if (a.type==b.type) return a.x<b.x;
    return a.type<b.type;
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++)
    {
        ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        if (y1==y2)
        {
            v.push_back(point(1, x1, 0, y1));
            v.push_back(point(2, 0, x2, y1));
        }
        else 
        {
            v.push_back(point(3, y1, y2, 0));
        }
    }
    sort(v.begin(), v.end(), comp);
    ll ans=0;
    for (auto [type, st, fi, x]: v)
    {
        if (type==1) ft.update(st, 1);
        else if (type==2) ft.update(fi, -1);
        else ans+=ft.query(fi)-ft.query(st-1);
    }
    cout<<ans;
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