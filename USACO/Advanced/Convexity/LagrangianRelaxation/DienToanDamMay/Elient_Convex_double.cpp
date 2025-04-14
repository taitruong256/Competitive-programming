#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
ll N, K, a[200005];
vector<pair<ll, ll>> dp(200005);

struct line 
{
    ll a, b;
    ll get(ll x) {return a*x+b;}
    ld intersect(const line &other) {return (ld)(other.b-b)/(a-other.a);}
};

struct CHT
{
    deque<line> dq;
    void insert(line l)  
    {              
        while (dq.size()>=2 && dq[dq.size()-1].intersect(l)<=dq[dq.size()-2].intersect(dq[dq.size()-1])) dq.pop_back();
        dq.push_back(l); 
    }
    pair<ll, ll> query(ll x)
    {
        while (dq.size()>=2 && (ld)x>=dq[0].intersect(dq[1])) dq.pop_front();
        return make_pair(dq.front().a, dq.front().b);
    }  
};

ll check(ll lambda)
{
    CHT cht;
    cht.insert({0, 0});
    for (ll i=1; i<=N; i++) 
    {
        auto [j, dpj]=cht.query(a[i]);
        dp[i]={dpj+(i+j)*a[i]+lambda, dp[-j].second+1};
        cht.insert({-i, dp[i].first});   
    }        
    return dp[N].second;
}

void solve()
{
    cin>>N>>K;
    dp.resize(N+5);
    for (ll i=1; i<=N; i++) cin>>a[i];
    sort(a+1, a+N+1);

    ll ans=-1;
    ll l=0, r=a[N]*N;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (check(mid)<=K) ans=mid, r=mid-1;
        else l=mid+1;
    }
    check(ans);
    cout<<dp[N].first-ans*dp[N].second;

}
 
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}