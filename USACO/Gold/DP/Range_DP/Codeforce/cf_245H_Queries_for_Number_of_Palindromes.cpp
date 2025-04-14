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
const ll maxn = 200005;
const ll mod = 1e9+7;
bool ispal[5005][5005];
ll dp[5005][5005], n;

void solve()
{
    string s; cin>>s; s=" "+s;
    n=s.size()-1;
    for (ll i=1; i<=n; i++)
    {
        ispal[i][i]=1;
        ispal[i+1][i]=1;
        dp[i][i]=1;
    }
    for (ll len=2; len<=n; len++)
    {
        for (ll i=1; i+len-1<=n; i++)
        {
            ll j=i+len-1;
            if (ispal[i+1][j-1]==1 && s[i]==s[j]) ispal[i][j]=1;
            else ispal[i][j]=0;
            dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+ispal[i][j];
        }
    }
    ll q; cin>>q;
    while (q--)
    {
        ll l, r; cin>>l>>r;
        cout<<dp[l][r]<<endl;
    }
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