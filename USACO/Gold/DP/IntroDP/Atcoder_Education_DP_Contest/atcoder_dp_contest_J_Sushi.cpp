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
long double dp[305][305][305];
ll n, a[305], cnt[5];

long double calc(ll x, ll y, ll z)
{
    if (x<0 || y<0 || z<0) return 0;
    if (x==0 && y==0 && z==0) return 0;
    if (dp[x][y][z]>0) return dp[x][y][z];
    long double res=n+x*calc(x-1, y, z)+y*calc(x+1, y-1, z)+z*calc(x, y+1, z-1);
    return dp[x][y][z]=1.0*res/(x+y+z);
}

void solve()
{
    cin>>n;
    for (ll i=0; i<=301; i++)
        for (ll j=0; j<=301; j++)
            for (ll k=0; k<=301; k++) dp[i][j][k]=-1;
    for (ll i=1; i<=n; i++) cin>>a[i], ++cnt[a[i]];
    cout<<fixed<<setprecision(10)<<calc(cnt[1], cnt[2], cnt[3]);
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