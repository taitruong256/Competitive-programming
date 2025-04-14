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

void solve()
{
    ll n; cin>>n; 
    ll a[n+5], b[n+5];
    for (ll i=1; i<=n; i++) a[i]=i;
    do 
    {
        // for (ll i=1; i<=n; i++) cout<<a[i]<<" "; cout<<endl;
        b[0]=0;
        for (ll i=1; i<=n; i++) b[i]=(b[i-1]+a[i])%n;
        vector<ll> cnt(n+5);
        for (ll i=1; i<=n; i++) ++cnt[b[i]+1];
        bool check=true;
        for (ll i=1; i<=n; i++) if (cnt[i]!=1) check=false;
        if (check==true)
        {
            for (ll i=1; i<=n; i++) cout<<a[i]<<" "; 
            cout<<endl;
        }
    }
    while (next_permutation(a+1, a+n+1));
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