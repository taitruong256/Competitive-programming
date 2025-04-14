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

ll calc(vector<ll> a, vector<ll> b, vector<ll> c)
{
    ll res=4e18;
    for (auto y: b)
    {
        auto pa=upper_bound(a.begin(), a.end(), y);
        auto pc=lower_bound(c.begin(), c.end(), y);
        if (pa==a.begin() || pc==c.end()) continue;
        --pa;
        ll x=*pa, z=*pc;  
        res=min(res, (x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x));
    }              
    return res;
}

void solve()
{
    ll n1, n2, n3; cin>>n1>>n2>>n3;
    vector<ll> red(n1), green(n2), blue(n3);
    for (auto &i: red) cin>>i;
    for (auto &i: green) cin>>i;
    for (auto &i: blue) cin>>i;
    sort(red.begin(), red.end());
    sort(green.begin(), green.end());
    sort(blue.begin(), blue.end());
    ll ans=4e18;
    ans=min(ans, calc(red, green, blue));    
    ans=min(ans, calc(red, blue, green));
    ans=min(ans, calc(green, red, blue));
    ans=min(ans, calc(green, blue, red));
    ans=min(ans, calc(blue, green, red));
    ans=min(ans, calc(blue, red, green));
    assert(ans!=4e18);
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