#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
ll N, K, a[100005];
vector<ll> dp;
ll inf = 1e4;

struct line 
{
    ll a, b, c;
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
    ll query(ll x)     
    {
        while (dq.size()>=2 && (ld)x>=dq[0].intersect(dq[1])) dq.pop_front();
        return dq.front().get(x);
    }  
};

ll check(ll lambda)
{
    CHT cht;
    ll c=lambda, x;
    cht.insert({0, 0, 0});
    dp[1]=a[1]+c;                              
    for (ll i=2; i<=N; i++) 
    {
        cht.insert({-(i-1), dp[i-1], cht.dq[0].c+1});     
        x=cht.dq[0].c+1;
        dp[i]=cht.query(a[i])+i*a[i]+c;     
    }        
    return x+1;
}

void solve()
{
    cin>>N>>K;
    dp.resize(N+5);
    for (ll i=1; i<=N; i++) cin>>a[i];
    sort(a+1, a+N+1);

    ll ans=-1;
    ll l=0, r=a[N];
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (check(mid)<=K) ans=mid, r=mid-1;
        else l=mid+1;
    }
    ll cnt;
    cnt=check(ans);
    cout<<dp[N]-cnt*ans+1;
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