#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Line
{
    ll a, b;
    
    Line() {}
    Line(ll _a, ll _b) { a=_a; b=_b; }
    ll get(ll x){ return a*x+b; }
    double intersect(Line other) { return (double)(b-other.b)/(double)(other.a-a); }
};

struct CHT 
{
    deque<pair<Line, double>> dq;

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

ll n, C, h[200005], dp[200005];

void solve()
{
    cin>>n>>C;
    for (ll i=1; i<=n; i++) cin>>h[i];
    CHT cht;
    dp[0]=0;
    cht.insert({-2LL*h[1], h[1]*h[1]});
    for (ll i=2; i<=n; i++)
    {
        dp[i]=cht.query(h[i])+C+h[i]*h[i];
        cht.insert({-2LL*h[i], dp[i]+h[i]*h[i]});
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
