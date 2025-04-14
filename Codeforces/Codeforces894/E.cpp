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

struct line 
{
    ll a, b;
    ll get(ll x) {return a*x+b;}
    ld intersect(const line &other) {return (ld)(other.b-b)/(a-other.a);}
};

struct line 
{
    ll a, b;
    ll get(ll x) {return a*x+b;}
    ld intersect(const line &other) {return (ld)(other.b-b)/(a-other.a);}
};

struct CHT     //find_max
{
    deque<line> dq={{0LL, 0LL}};
    void insert(line l)   //he so goc a giam dan nen them vao ben trai cua convex hull 
    {              
        while (dq.size()>=2 && dq[dq.size()-1].intersect(l)<=dq[dq.size()-2].intersect(dq[dq.size()-1])) dq.pop_back();
        dq.push_back(l); 
    }
    ll query_O_1(ll x)     
    {
        //x tang dan nen xoa duong ben trai cua convex hull
        while (dq.size()>=2 && (ld)x>=dq[0].intersect(dq[1])) dq.pop_front();
        return dq.front().get(x);
    }  
    ll query_O_logn(ll x)   
    {
        //tim duong thang x<=dq[ans].intersect(dq[ans+1])   [dq[ans].minX <= x <= dq[ans].maxX]
        ll l=0, r=dq.size()-2, ans=dq.size()-1;
        while (l<=r)
        {
            ll mid=(l+r)/2;
            if (x<=dq[mid].intersect(dq[mid+1])) ans=mid, r=mid-1;
            else l=mid+1;
        }
        return dq[ans].get(x);
    }   
};

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);
    vector<ll> dp(n+5);
    CHT cht;
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