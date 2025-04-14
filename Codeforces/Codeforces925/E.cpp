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

ll f(ll n)
{
    ll x=0;
    while (n>0 && n%10==0) ++x, n/=10;
    return x;
}

ll len(ll n)
{
    ll x=0;
    while (n>0) ++x, n/=10;
    return x;
}

void solve()
{
    ll n, m; cin>>n>>m;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    if (n==1)
    {
        if (len(a[1])-f(a[1])>m) cout<<"Sasha\n";
        else cout<<"Anna\n";
        return;
    }
    multiset<pair<ll, ll>> ms;
    for (ll i=1; i<=n; i++) ms.insert({f(a[i]), len(a[i])});
    for (ll i=1; i<=2*(n-1); i++)
    {
        if (i%2==1)
        {
            auto [fx1, x1]=*ms.rbegin(); 
            ms.erase(ms.find({fx1, x1}));
            ms.insert({0, x1-fx1});
        }
        else
        {
            auto [fx1, x1]=*ms.rbegin(); 
            ms.erase(ms.find({fx1, x1}));
            auto [fx2, x2]=*ms.begin(); 
            ms.erase(ms.find({fx2, x2}));
            ms.insert({fx2, x1+x2});
        }
        // for (auto [x, y]: ms) cout<<x<<" "<<y<<endl; cout<<endl;

    }
    if ((*ms.begin()).second>m) cout<<"Sasha\n";
    else cout<<"Anna\n";
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