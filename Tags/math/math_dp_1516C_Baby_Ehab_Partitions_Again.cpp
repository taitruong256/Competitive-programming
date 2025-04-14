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
ll dp[105][200005];

void solve()
{
    ll n; cin>>n;
    ll a[n+5], g=0, s=0;
    for (ll i=1; i<=n; i++)
    {
        cin>>a[i];
        g=__gcd(g, a[i]);
        s+=a[i];
    }
    dp[0][0]=1;
    for (ll i=1; i<=n; i++)
        for (ll j=s; j>=0; j--)
        {
            dp[i][j]=dp[i-1][j];
            if (j>=a[i] && dp[i-1][j-a[i]]==1) dp[i][j]=1;
        }
    if (s%2==1 || dp[n][s/2]==0)
    {
        cout<<0;
        return;
    }
    ll pos=1;
    for (ll i=1; i<=n; i++)
    {
        a[i]/=g;
        if (a[i]%2==1) pos=i;
    }
    cout<<1<<endl<<pos;
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