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
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
 
struct Line
{
    ll a, b;
    
    Line() {}
    Line(ll _a, ll _b) { a=_a; b=_b; }
    ll get(ll x){ return a*x+b; }
    ll intersect(Line other) { return (b-other.b+other.a-a-1)/(other.a-a); }
};
 
struct CHT 
{
    deque<pair<Line, ll>> dq;
 
    void insert(Line L)
    {
        while (dq.size()>=2 && dq.back().second>=dq.back().first.intersect(L)) dq.pop_back();
        if (dq.empty()) dq.push_back({L, 0});
        else dq.push_back({L, dq.back().first.intersect(L)}); 
    }
 
    ll query(ll x)
    {
        while (dq.size()>=2 && dq[1].second<=x) dq.pop_front();
        return dq[0].first.get(x);
    }
};
 
ll n, K, a[3005], pref[3005], dp[3005];
 
void solve()
{
    cin>>n>>K;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) pref[i]=pref[i-1]+a[i];
    for (ll i=1; i<=n; i++) dp[i]=pref[i]*pref[i];
 
    for (ll k=2; k<=K; k++)
    {
        CHT cht;
        vector<ll> new_dp(n+5, LLONG_MAX);
        for (ll i=k; i<=n; i++) 
        {
            cht.insert({-2*pref[i-1], dp[i-1]+pref[i-1]*pref[i-1]});
            new_dp[i]=pref[i]*pref[i]+cht.query(pref[i]);
        }
        for (ll i=1; i<=n; i++) dp[i]=new_dp[i];
    }
    cout<<dp[n];
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