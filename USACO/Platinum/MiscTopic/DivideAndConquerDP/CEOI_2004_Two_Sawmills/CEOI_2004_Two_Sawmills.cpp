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
                                          Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
ll N, d[20005], w[20005], sumWD[20005], sumW[20005], sumD[20005], dp[20005];

ll cost(ll l, ll r)
{
    return (sumWD[l]-sumWD[r]-sumD[r]*(sumW[l]-sumW[r]));
}

ll eval(ll l, ll r)
{
    if (l>r) return 1e18;
    return cost(1, l)+cost(l+1, r)+cost(r+1, N+1);
}

void divide_and_conquer(ll l, ll r, ll optl, ll optr)
{
    if (l>r) return;
    ll mid=(l+r)/2;
    pair<ll, ll> best={1e18, -1};
    for (ll i=optl; i<=min(mid, optr); i++) 
        best=min(best, {eval(i, mid), i});  
    dp[mid]=best.first;
    divide_and_conquer(l, mid-1, optl, best.second);
    divide_and_conquer(mid+1, r, best.second, optr);
}

void solve()
{
    cin>>N;
    for (ll i=1; i<=N; i++) cin>>w[i]>>d[i];
    for (ll i=N; i>=1; i--)
    {
        sumW[i]=sumW[i+1]+w[i];
        sumD[i]=sumD[i+1]+d[i];
        sumWD[i]=sumWD[i+1]+w[i]*sumD[i];
    }
    divide_and_conquer(1, N, 1, N);
    ll ans=1e18;
    for (ll i=1; i<=N; i++) ans=min(ans, dp[i]);
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