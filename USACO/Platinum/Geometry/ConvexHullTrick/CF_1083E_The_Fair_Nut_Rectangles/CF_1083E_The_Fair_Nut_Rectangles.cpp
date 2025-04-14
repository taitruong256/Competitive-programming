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
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
                                          Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
struct rect 
{
    ll x, y, a;
    bool operator< (const rect &other) {return x<other.x;}
};

struct line 
{
    ll a, b;
    ll get(ll x) {return a*x+b;}
    ld intersect(const line &other) {return (ld)(other.b-b)/(a-other.a);}
};

struct CHT 
{
    deque<line> dq={{0LL, 0LL}};
    void insert(line l)   //he so goc a giam dan nen them vao ben trai cua convex hull 
    {              
        while (dq.size()>=2 && dq[0].intersect(l)>=dq[0].intersect(dq[1])) dq.pop_front();
        dq.push_front(l); 
    }
    ll query(ll x)     //x giam dan nen xoa duong ben phai cua convex hull
    {
        while (dq.size()>=2 && (ld)x<dq[dq.size()-1].intersect(dq[dq.size()-2])) dq.pop_back();
        return dq.back().get(x);
    }   
};

ll n, dp[1000005], ans=-1e18;
rect rec[1000005];

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>rec[i].x>>rec[i].y>>rec[i].a;
    sort(rec+1, rec+n+1);
    CHT cht;
    for (ll i=1; i<=n; i++)
    {
        dp[i]=rec[i].x*rec[i].y-rec[i].a+cht.query(rec[i].y);
        cht.insert({-rec[i].x, dp[i]});
        ans=max(ans, dp[i]);
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