#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll N, K, a[100005];
vector<ll> dp;
ll inf = 1e18;

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
    deque<pair<Line, ll>> dq;   // he so a giam dan, x tang dan
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
 
void solve()
{
    cin>>N>>K;  
    dp.resize(N+5);
    for (ll i=1; i<=N; i++) cin>>a[i];
    sort(a+1, a+N+1);
    for (ll i=1; i<=N; i++) dp[i]=a[i]*i;

    for (ll k=2; k<=K; k++)
    {
        vector<ll> new_dp(N+5, inf);
        CHT cht;
        for (ll i=k; i<=N; i++)
        {
            cht.insert({-(i-1), dp[i-1]});
            new_dp[i]=i*a[i]+cht.query(a[i]);
        }
        dp=new_dp;
    }
    cout<<dp[N];
}
 
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}