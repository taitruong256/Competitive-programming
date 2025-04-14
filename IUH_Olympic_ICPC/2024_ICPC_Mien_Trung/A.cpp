#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll inf = 1e18;
const ll mod = 1e9+7;
ll dp[105][100005], weight[105], value[105];
ll N, W, H, used[105], ans1, ans2;
vector<ll> cand;

void trace(ll i, ll j)
{
    if (dp[i][j]==0) return;
    if (dp[i][j]==dp[i-1][j]) trace(i-1, j);
    else 
    {
        cand.push_back(i);
        trace(i-1, j-value[i]);
    }
}

void solve()
{
    for (ll i=0; i<=100; i++)
      for (ll j=0; j<=100000; j++) dp[i][j]=1e18;
    cin>>N>>W>>H;
    for (ll i=0; i<=N; i++) dp[i][0]=0;
    for (ll i=1; i<=N; i++) cin>>weight[i]>>value[i];
    for (ll i=1; i<=N; i++)
    {
        for (ll j=1; j<=100000; j++) 
        {
            dp[i][j]=dp[i-1][j];
            if (j>=value[i]) dp[i][j]=min(dp[i-1][j], dp[i-1][j-value[i]]+weight[i]);
        }
    }
    for (ll i=100000; i>=0; i--) if (dp[N][i]<=W)
    {
        ans1=i;
        trace(N, i);
        break;
    }
    
    for (auto i: cand) used[i]=1;
    for (ll i=1; i<=N; i++) if (used[i]==0 && weight[i]<=H) ans2=max(ans2, value[i]);
    cout<<ans1+ans2; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}