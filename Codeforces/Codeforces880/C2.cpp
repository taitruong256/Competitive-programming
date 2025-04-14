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
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
vector<ll> dp[8][8][8];

void solve()
{
    ll a, b, c, k; cin>>a>>b>>c>>k;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif

    for (ll i=1; i<=6; i++)
    {
        for (ll j=1; j<=6; j++)
        {
            ll a=1, b=1;
            if (i<=j)
            {
                for (ll k=1; k<=i-1; k++) a=a*10;
                for (ll k=1; k<=j; k++) b=b*10; 
                dp[i][j][j].push_back(0);
                dp[i][j][j+1].push_back(0);
                for (ll k=a; k<=a*10-1; k++) dp[i][j][j].push_back(b-k);
                for (ll k=a; k<=a*10-1; k++) dp[i][j][j+1].push_back(k);
            }
            else 
            {
                for (ll k=1; k<=i-1; k++) a=a*10;
                for (ll k=1; k<=j-1; k++) b=b*10; 
                dp[i][j][i].push_back(0);
                dp[i][j][i+1].push_back(0);
                for (ll k=a; k<=a*10-1; k++) dp[i][j][i].push_back(min(b*10-b, a*10-1-k));
                for (ll k=b; k<=b*10-1; k++) dp[i][j][i+1].push_back(b*10-b);
            }
        }
    }

    for (ll i=2; i<=2; i++)
    {
        for (ll j=2; j<=2; j++)
        {
            for (auto k: dp[i][j][i]) cout<<k<<" "; cout<<endl;
            for (auto k: dp[i][j][i+1]) cout<<k<<" "; cout<<endl;
        }
    }

    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}