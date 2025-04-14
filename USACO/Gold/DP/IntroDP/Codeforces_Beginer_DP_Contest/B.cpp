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
ll n, dp[1005];
string s;

void setIO(string s)
{
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}
void solve()
{
    // setIO("lepus");
    cin>>n;
    cin>>s; s=" "+s;
    for (ll i=1; i<=n; i++) dp[i]=-1e18;
    dp[1]=0;
    for (ll i=1; i<=n; i++)
    {
        if (s[i]=='w') dp[i]=-1e9;
        else if (s[i]=='.')
        {
            if (i>=2) dp[i]=max(dp[i], dp[i-1]+0);
            if (i>=4) dp[i]=max(dp[i], dp[i-3]+0);
            if (i>=6) dp[i]=max(dp[i], dp[i-5]+0);
        }
        else
        {
            if (i>=2) dp[i]=max(dp[i], dp[i-1]+1);
            if (i>=4) dp[i]=max(dp[i], dp[i-3]+1);
            if (i>=6) dp[i]=max(dp[i], dp[i-5]+1);
        }
    }
    cout<<max(dp[n], -1LL)<<endl;
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