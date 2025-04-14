#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll N, K, a[8005];
vector<ll> dp(8005), new_dp(8005);
ll pref[8005];

ll cost(ll l, ll r)
{
    return (r-l+1)*(pref[r]-pref[l-1]);
}

void calc(ll l, ll r, ll from, ll to)
{   
    if (l>r) return;
    ll mid=(l+r)/2;
    pair<ll, ll> best(1e18, -1);
    for (ll i=from; i<=min(mid, to); i++)
        best=min(best, {dp[i-1]+cost(i, mid), i});
    new_dp[mid]=best.first;
    calc(l, mid-1, from, best.second);
    calc(mid+1, r, best.second, to);
}
 
void solve()
{
    cin>>N>>K;
    for (ll i=1; i<=N; i++) cin>>a[i];
    for (ll i=1; i<=N; i++) pref[i]=pref[i-1]+a[i];
    sort(a+1, a+N+1);
    for (ll i=1; i<=N; i++) dp[i]=cost(1, i);
    for (ll i=2; i<=K; i++) 
    {
        calc(1, N, 1, N);
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