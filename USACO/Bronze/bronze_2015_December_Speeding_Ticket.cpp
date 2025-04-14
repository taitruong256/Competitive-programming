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
#define cout_return(x) return void(cout<<(x)<<endl)
const ll inf = 1e18;
const ll mod = 1e9+7;

void solve()
{
    ll limit[105], speed[105];
    ll n, m, idx=0; cin>>n>>m;
    for (ll i=0; i<n; i++)
    {
        ll x, y; cin>>x>>y;
        while (x--) limit[++idx]=y;
    }
    idx=0;
    for (ll i=0; i<m; i++)
    {
        ll x, y; cin>>x>>y;
        while (x--) speed[++idx]=y;
    }
    ll ans=0;
    for (ll i=1; i<=100; i++) if (speed[i]>limit[i]) ans=max(ans, speed[i]-limit[i]);
    cout<<ans;
}  

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}