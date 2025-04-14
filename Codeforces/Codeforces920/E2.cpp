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
#define ll int
#define endl '\n'
const ll mod = 1e9+7;
int n, q, ans[200005], pref[200205][205], a[200005];

void solve()
{
    cin>>n>>q;   
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll k=1; k<=q; k++)
    {
        ll x, y, z; cin>>y>>x>>z;
        if (z>200)
        {
            for (ll i=x; i<=x+(y-1)*z; i+=z) ans[k]+=a[i];
        }
        else 
        {
            pref[x][z]+=a[x];
            --pref[x+y*z][z];
        }
    }
    for (ll j=1; j<=200; j++)
        for (ll i=j; i<=n; i++) pref[i][j]+=pref[i-j][j];
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=200; j++) ans[i]+=pref[i][j];
    for (ll i=1; i<=n; i++) cout<<ans[i]<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t; while (t--)
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}