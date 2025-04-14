/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|     
      __|  |__              __|  |_                                          |_|  | |  | |       | |  
     |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
        |  |    _____         |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | \_/ | | |_| | | /  \ | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  | | \__   |   |______| |______/  \_______/
                                                                        | |
                                                                      __/ |
                                                                     |___/  
                             Nothing is impossible, only you think it is impossible                 
                                     Try, try, try again until you succeed     
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
ll coso[3][3], donvi[3][3], tam[3][3], ans[3][3];

void nhanmatran(ll a[][3], ll b[][3])
{
    ll c[3][3];
    memset(c, 0, sizeof(c));
    for (ll i=1; i<=2; i++)
        for (ll j=1; j<=2; j++)
            for (ll k=1; k<=2; k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
                c[i][j]%=mod;  
            }
        
    for (ll i=1; i<=2; i++)
        for (ll j=1; j<=2; j++) a[i][j]=c[i][j];
}

void luythua(ll n)
{
    while (n>0)
    {
        if (n&1) nhanmatran(ans, coso);
        nhanmatran(coso, coso);
        n/=2;
    }
}

void solve()
{
    ll n; cin>>n;                  
    ans[1][1]=ans[2][2]=1; ans[1][2]=ans[2][1]=0;
    coso[1][1]=coso[1][2]=coso[2][1]=1; coso[2][2]=0;
    luythua(n);
    cout<<ans[1][1]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    // #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}