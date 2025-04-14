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
const ll mod = 1e9+7;
ll n, m;
vector<vector<ll>> a, pref;
 
bool check(ll l)
{
    for (ll i=0; i<=n; i++)
        for (ll j=0; j<=m; j++) pref[i][j]=0;
    
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) 
            pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+(a[i][j]>=l);
    
    for (ll i=l; i<=n; i++)
        for (ll j=l; j<=m; j++) 
            if (pref[i][j]-pref[i-l][j]-pref[i][j-l]+pref[i-l][j-l]==l*l) 
                return true;
    return false;
}
 
void solve()
{
    cin>>n>>m;
    a.resize(n+5);
    pref.resize(n+5);
    for (ll i=0; i<=n; i++) a[i].resize(m+5);
    for (ll i=0; i<=n; i++) pref[i].resize(m+5);
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) cin>>a[i][j];
    
    ll l=1, r=min(n, m), ans=r;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (check(mid)==true) ans=mid, l=mid+1;
        else r=mid-1;
    }
    cout<<ans<<endl;
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
