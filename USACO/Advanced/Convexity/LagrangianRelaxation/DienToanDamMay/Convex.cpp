#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll N, K, a[100005];
vector<ll> dp;
ll inf = 1e18;

struct line 
{
    ll a, b;
    ll get(ll x) {return a*x+b;}
    ld intersect(const line &other) {return (ld)(other.b-b)/(a-other.a);}
};

struct CHT   
{
    deque<line> dq={{0LL, 0LL}};
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
 
void solve()
{
    cin>>N>>K;
    dp.resize(N+5);
    for (ll i=1; i<=N; i++) cin>>a[i];
    sort(a+1, a+N+1);
    ll c=0;
    for (ll i=1; i<=N; i++) dp[i]=a[i]*i+c;

    for (ll k=2; k<=K; k++)
    {
        vector<ll> new_dp(N+5, inf);
        CHT cht;
        for (ll i=k; i<=N; i++)
        {
            cht.insert({-(i-1), dp[i-1]});
            new_dp[i]=i*a[i]+cht.query(a[i])+c;
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
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}