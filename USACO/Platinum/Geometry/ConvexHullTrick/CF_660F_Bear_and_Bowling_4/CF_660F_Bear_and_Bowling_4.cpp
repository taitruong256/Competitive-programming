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

struct line 
{
    ll a, b;
    ll get(ll x) {return a*x+b;}
    ld intersect(const line &other) {return (ld)(other.b-b)/(a-other.a);}
};

struct CHT     //find_max
{
    deque<line> dq;
    void insert(line l)   //he so goc a giam dan nen them vao ben trai cua convex hull 
    {              
        while (dq.size()>=2 && dq[0].intersect(l)>=dq[0].intersect(dq[1])) dq.pop_front();
        dq.push_front(l); 
    }
    ll query(ll x)   
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

ll n, a[200005], pref[200005], ips[200005], dp[200005], ans=0;

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) 
    {
        pref[i]=pref[i-1]+a[i];
        ips[i]=ips[i-1]+a[i]*i;
    }
    CHT cht;
    for (ll i=1; i<=n; i++)
    {
        cht.insert({-i, (i-1)*pref[i-1]-ips[i-1]});
        dp[i]=cht.query(pref[i])+ips[i]+pref[i];
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