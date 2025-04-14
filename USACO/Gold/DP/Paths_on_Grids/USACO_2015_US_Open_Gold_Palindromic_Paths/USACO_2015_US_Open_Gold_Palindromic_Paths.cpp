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

void setIO(string s)
{
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}
ll n, pre[505][505];
char s[505][505];

void solve()
{
    setIO("palpath");
    cin>>n;   
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) cin>>s[i][j];
    for (ll i=1; i<=n; i++) pre[i][i]=1;

    for (ll i=1; i<=n-1; i++)
    {
        ll now[505][505]={};
        for (ll r1=1; r1<=n; r1++)
        {
            ll c1=n-r1-i+1;
            if (c1<1) continue;
            for (ll r2=1; r2<=n; r2++)
            {
                ll c2=n-r2+i+1; 
                if (c2>n) continue;  
                if (s[r1][c1]!=s[r2][c2]) continue;
                now[r1][r2] =pre[r1][r2];
                now[r1][r2]+=pre[r1+1][r2];
                now[r1][r2]+=pre[r1][r2-1];
                now[r1][r2]+=pre[r1+1][r2-1];
                now[r1][r2]%=mod;
            }  
        }
        swap(pre, now);
    }
    cout<<pre[1][n];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}