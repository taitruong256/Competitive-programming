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
    ll n, q; scanf("%lld%lld", &n, &q);
    ll a[n+5];
    ll mod=1e9+7;
    for (ll i=1; i<=n; i++) scanf("%lld", &a[i]);
    while (q--)
    {
        ll type; scanf("%lld", &type);
        if (type==1)
        {
            ll l, r, x; scanf("%lld%lld%lld", &l, &r, &x);
            for (ll i=l; i<=r; i++) a[i]=(a[i]+x)%mod;
        }
        else if (type==2)
        {
            ll l, r, x; scanf("%lld%lld%lld", &l, &r, &x);
            for (ll i=l; i<=r; i++) a[i]=(a[i]*x)%mod;
        }
        else if (type==3)
        {
            ll l, r, x; scanf("%lld%lld%lld", &l, &r, &x);
            for (ll i=l; i<=r; i++) a[i]=x;
        }
        else 
        {
            ll l, r; scanf("%lld%lld", &l, &r);
            ll ans=0;
            for (ll i=l; i<=r; i++) ans=(ans+a[i])%mod;
            printf("%lld\n", ans);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}