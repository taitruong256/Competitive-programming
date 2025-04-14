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
#define before 1
#define after 2
const ll inf = 1e18;
ll n, k, a[3005], pref[5][3005], dp[3005][3005];

ll travel(ll type, ll l, ll r)
{
    return (pref[type][r]-pref[type][l-1])-(pref[0][r]-pref[0][l-1])*(type==before?n-r+1:l);
}

ll cost(ll l, ll r)
{
    ll m=(l+r)/2;
    return travel(after, l, m)+travel(before, m+1, r);
}

void calc(ll k, ll l, ll r, ll from, ll to)
{
    if(l>r) return;
    ll mid=(l+r)/2;
    pair<ll, ll> best={inf, -1};
    for (ll i=from; i<=mid; i++) 
        best=min(best, {dp[i][k-1]+cost(i, mid), i});
    dp[mid][k]=best.first;
    calc(k, l, mid-1, from, best.second);
    calc(k, mid+1, r, best.second, to);
}

void solve()
{
    cin>>n>>k;
    for (ll i=1; i<=n; i++)
    {
        cin>>a[i];
        pref[0][i]=pref[0][i-1]+a[i];
        pref[1][i]=pref[1][i-1]+a[i]*(n-i+1);
        pref[2][i]=pref[2][i-1]+a[i]*i;
    }

    for (ll i=1; i<=n; i++) dp[i][1]=travel(before, 1, i);
    for (ll i=2; i<=k; i++) calc(i, 1, n, 1, n);
    ll ans=inf;
    for (ll i=1; i<=n; i++) ans=min(ans, dp[i][k]+travel(after, i, n));
    cout<<ans;
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