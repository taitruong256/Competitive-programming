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
                                       Where is the bug, delete it there
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;

void solve()
{
    ll n; cin>>n;
    vector<ll> a(n+5), pref(n+5), suff(n+5);
    a[0]=a[n+1]=1e18;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=2; i<=n; i++) 
    {
        if (abs(a[i-1]-a[i])<abs(a[i-1]-a[i-2]))
            pref[i]=pref[i-1]+1;
        else 
            pref[i]=pref[i-1]+abs(a[i]-a[i-1]);
    }

    for (ll i=n-1; i>=1; i--)
    {
        if (abs(a[i+1]-a[i])<abs(a[i+1]-a[i+2]))
            suff[i]=suff[i+1]+1;
        else 
            suff[i]=suff[i+1]+abs(a[i]-a[i+1]);
    }

    // for (ll i=1; i<=n; i++) cout<<pref[i]<<" "; cout<<endl;
    // for (ll i=1; i<=n; i++) cout<<suff[i]<<" "; cout<<endl;

    ll q; cin>>q;
    while (q--)
    {
        ll l, r; cin>>l>>r;
        if (l<=r) cout<<pref[r]-pref[l]<<endl;
        else cout<<suff[r]-suff[l]<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}