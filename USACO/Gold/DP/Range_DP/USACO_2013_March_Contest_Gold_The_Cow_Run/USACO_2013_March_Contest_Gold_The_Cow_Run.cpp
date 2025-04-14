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
const ll inf = 1e18;
const ll mod = 1e9+7;

void setIO(string s)
{
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}
ll n, a[1005], dp[1005][1005][3];

ll calc(ll l, ll r, ll dir)
{
    ll left=inf, right=inf, remain=n-r+l;
    if (dp[l][r][dir]!=-1) return dp[l][r][dir];
    if (dir==1)
    {
        if (l-1>=0) left=min(left, calc(l-1, r, 0)+abs(a[r]-a[l-1])*remain);
        if (r+1<=n) right=min(right, calc(l, r+1, 1)+abs(a[r+1]-a[r])*remain);
    }
    else 
    {
        if (l-1>=0) left=min(left, calc(l-1, r, 0)+abs(a[l]-a[l-1])*remain);
        if (r+1<=n) right=min(right, calc(l, r+1, 1)+abs(a[r+1]-a[l])*remain);
    }                  
    if (left==inf && right==inf) return 0;
    return dp[l][r][dir]=min(left, right);
}

void solve()
{
    setIO("cowrun");
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=0; i<=n+1; i++)
        for (ll j=0; j<=n+1; j++)
            for (ll k=0; k<=1; k++) dp[i][j][k]=-1;
    sort(a, a+n+1);
    ll l=lower_bound(a, a+n+1, 0)-a, r=l;  
    cout<<calc(l, r, 0);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}