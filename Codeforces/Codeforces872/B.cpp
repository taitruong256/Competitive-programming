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

void solve()
{
    ll n, m; cin>>n>>m;
    ll a[n*m+5];
    for (ll i=1; i<=n*m; i++) cin>>a[i];
    sort(a+1, a+n*m+1);
    ll ans1=n*m*a[n*m]-n*(m-1)*a[1]-a[2]*(n-1)-a[n*m];
    ll ans2=n*m*a[n*m]-(n-1)*m*a[1]-a[2]*(m-1)-a[n*m];
    ll ans3=-n*m*a[1]+(n-1)*m*a[n*m]+a[n*m-1]*(m-1)+a[1];
    ll ans4=-n*m*a[1]+(m-1)*n*a[n*m]+a[n*m-1]*(n-1)+a[1];
    cout<<max({ans1, ans2, ans3, ans4})<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}