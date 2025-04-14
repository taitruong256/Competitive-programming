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
vector<ll> chinhphuong;
ll cnt[1000000];
 
void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    ll pref[n+5];
    pref[0]=0;
    for (ll i=1; i<=n; i++) pref[i]=pref[i-1]^a[i];
    
    ll ans=0;
    cnt[0]=1;
    for (ll i=1; i<=n; i++)
    {
        ll res=0;
        for (auto j: chinhphuong) 
        {
            ll x=pref[i]^j;
            res+=cnt[x];
        }
        ++cnt[pref[i]]; 
        ans+=res;
    }
    cout<<n*(n+1)/2-ans<<endl;
    for (ll i=1; i<=n; i++) --cnt[pref[i]];
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    for (ll i=0; i<=600; i++) chinhphuong.push_back(i*i);
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}