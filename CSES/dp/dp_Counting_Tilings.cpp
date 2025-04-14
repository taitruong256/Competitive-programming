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
const ll mod = 1e9+7;
vector<ll> prev_state[(1LL<<10)+5];
ll dp[1005][(1LL<<10)+5];

void generate_prev(ll idx, ll n, ll prev, ll next)
{      
    if (idx>=n)
    {
        prev_state[next].push_back(prev);
        return;
    }
    if (prev&(1LL<<idx)) 
    {
        generate_prev(idx+1, n, prev, next);
        return;
    }
    if ((idx<n-1) && !(prev & 1LL<<(idx+1)))
    {
        generate_prev(idx+2, n, prev, next);     //canh doc
    }
    next|=(1LL<<idx);
    generate_prev(idx+1, n, prev, next);     //canh ngang
}

void solve()
{
    ll n, m; cin>>n>>m;
    for (ll i=0; i<(1LL<<n); i++)
        generate_prev(0, n, i, 0);

    dp[0][0]=1;
    for (ll i=1; i<=m; i++)
    {
        for (ll j=0; j<(1LL<<n); j++)
            for (auto k: prev_state[j])
                dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
    }
    cout<<dp[m][0];
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