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
#define ll int
#define endl '\n'
const ll maxn = (1<<9);
const ll mod = 1e9+7;
ll dp[maxn+1][maxn+1], n, a[100005];

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=0; i<maxn; i++) dp[0][i]=1;
    for (ll k=1; k<=n; k++) if (a[k]!=0)
    {
        ll x=a[k];
        for (ll i=0; i<maxn; i++)
        {
            dp[(x^i)][x]|=dp[i][x-1];
            ll j=x+1;
            if (dp[x^i][x]==1 && dp[x^i][j]==0)
                while (j<maxn) dp[x^i][j]|=dp[(x^i)][j-1], ++j;
        }
    }
    vector<ll> ans;
    for (ll i=0; i<maxn; i++) if (dp[i][maxn-1]==1) ans.push_back(i);
    cout<<ans.size()<<endl;
    for (auto i: ans) cout<<i<<" " ; 
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