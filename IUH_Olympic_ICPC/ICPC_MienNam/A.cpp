#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define cint int t; cin >> t; while(t--)
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int N = 1e5 + 9, MOD = 1e9 + 7;
ll dp[505][505], vis[505][505], a[505][505];

ll solve1()
{
    ll n, g; cin>>n>>g;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) cin>>a[i][j];
    
    dp[1][1]=(a[1][1]<g);
    for (ll i=2; i<=n; i++) 
    {
        dp[1][i]=dp[1][i-1]+(a[1][i]<g);
        dp[i][1]=dp[i-1][1]+(a[i][1]<g);
    }
    for (ll i=2; i<=n; i++)
        for (ll j=2; j<=n; j++)
            dp[i][j]=min(dp[i-1][j], dp[i][j-1])+(a[i][j]<g);
    return dp[n][n];
}

bool check(ll g, ll n)
{
    if (a[1][1]<g) return false;

    queue<pair<ll, ll>> q;
    ll dx[]={0, 0, -1, 1};
    ll dy[]={-1, 1, 0, 0};
    for (ll i=1; i<=500; i++)
        for (ll j=1; j<=500; j++)
            vis[i][j]=0;

    q.push({1, 1});
    vis[1][1]=1;
    while (!q.empty())
    {
        auto [x, y]=q.front(); q.pop();
        for (ll i=0; i<4; i++)
        {
            ll newx=x+dx[i], newy=y+dy[i];
            if (1<=newx && newx<=n && 1<=newy && newy<=n && a[newx][newy]>=g && vis[newx][newy]==0)
            {
                vis[newx][newy]=1;
                q.push({newx, newy});
            }
        }
    }
    return vis[n][n];
}

ll solve2()
{
    ll n; cin>>n;
    for (ll i=1; i<=n; i++) 
        for (ll j=1; j<=n; j++)
            cin>>a[i][j];
    ll l=1, r=1e4, ans=1;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (check(mid, n)==true) ans=mid, l=mid+1;
        else r=mid-1;
    }
    return ans;
}

void solve() {
    ll type; cin>>type;
    if (type==1) cout<<solve1()<<endl;
    else cout<<solve2()<<endl;
}
signed main () {
    ios
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    solve();
    return 0;
}