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
    ll n, m, k; cin>>n>>m>>k;
    ll a[n+5], b[m+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=m; i++) cin>>b[i];


    set<ll> x, y, z, sta, stb;
    for (ll i=1; i<=n; i++) if (a[i]<=k) sta.insert(a[i]);
    for (ll i=1; i<=m; i++) if (b[i]<=k) stb.insert(b[i]);


    for (ll i=1; i<=n; i++) if (a[i]<=k && sta.find(a[i])!=sta.end() && stb.find(a[i])!=stb.end()) z.insert(a[i]);
    for (ll i=1; i<=n; i++) if (a[i]<=k && z.find(a[i])==z.end()) x.insert(a[i]);
    for (ll i=1; i<=m; i++) if (b[i]<=k && z.find(b[i])==z.end()) y.insert(b[i]);


    if (x.size()<=k/2 && y.size()<=k/2 && x.size()+y.size()+z.size()==k) cout<<"YES\n";
    else cout<<"NO\n";
    // for (auto i: sta) cout<<i<<" "; cout<<endl;
    // for (auto i: stb) cout<<i<<" "; cout<<endl;
    // for (auto i: x) cout<<i<<" "; cout<<endl;
    // for (auto i: y) cout<<i<<" "; cout<<endl;
    // for (auto i: z) cout<<i<<" "; cout<<endl;
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