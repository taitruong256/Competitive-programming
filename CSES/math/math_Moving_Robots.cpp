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
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
ll dx[]={0, 0, 1, -1}, dy[]={1, -1, 0, 0};

void solve()
{
    ll n; cin>>n;
    ld dp[n+5][10][10], ans[10][10];
    for (ll i=1; i<=8; i++)
        for (ll j=1; j<=8; j++) ans[i][j]=1;

    for (ll i=1; i<=8; i++)
        for (ll j=1; j<=8; j++)
        {
            for (ll k=0; k<=n; k++)
                for (ll x=1; x<=8; x++)
                    for (ll y=1; y<=8; y++) dp[k][x][y]=0;
            
            dp[0][i][j]=1;
            for (ll k=0; k<=n-1; k++)
                for (ll x=1; x<=8; x++)
                    for (ll y=1; y<=8; y++) 
                    {
                        ll cnt=0;
                        for (ll t=0; t<4; t++)
                        {
                            ll new_x=x+dx[t], new_y=y+dy[t];
                            if (1<=new_x && new_x<=8 && 1<=new_y && new_y<=8) ++cnt; 
                        }  
                        for (ll t=0; t<4; t++)
                        {
                            ll new_x=x+dx[t], new_y=y+dy[t];
                            if (1<=new_x && new_x<=8 && 1<=new_y && new_y<=8) dp[k+1][new_x][new_y]+=dp[k][x][y]/cnt;
                        }
                    }

            for (ll x=1; x<=8; x++)
                for (ll y=1; y<=8; y++) ans[x][y]*=(1-dp[n][x][y]);
        }

    ld exp=0;
    for (ll i=1; i<=8; i++)
    {
        for (ll j=1; j<=8; j++) 
        {
            exp+=ans[i][j];
            // cout<<fixed<<setprecision(6)<<ans[i][j]<<" ";
        } 
        // cout<<endl;
    }
    cout<<fixed<<setprecision(6)<<exp<<endl;
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