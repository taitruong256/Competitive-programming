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
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
     Laziness is only temporary comfort. The future will regret that day. Don't fall into the trap of comfort.
                The most beautiful meeting in this world is meeting the best version of yourself.
                          Practice doing things you don't like but are useful to you
                                   Success is born from problem solving
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

pair<ld, ld> hinhchieu(ld xm, ld ym, ld xa, ld ya, ld xb, ld yb) {
    ld a = yb - ya;
    ld b = xa - xb;
    ld c = xb * ya - xa * yb;

    ld xH = (b * (b * xm - a * ym) - a * c) / (a * a + b * b);
    ld yH = (a * (-b * xm + a * ym) - b * c) / (a * a + b * b);
    return {xH, yH};
}

ld dist(ld xa, ld ya, ld xb, ld yb)
{
    ld d=((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
    return d;
}

void solve()
{
    ll n; cin>>n;
    ll x[n+5], y[n+5];
    for (ll i=1; i<=n; i++) cin>>x[i]>>y[i];
    ll xs, ys, xt, yt; cin>>xs>>ys>>xt>>yt;

    for (ll i=1; i<=n; i++) 
    {
        auto [xh, yh] = hinhchieu(x[i], y[i], xs, ys, xt, yt);
        ld d1=dist(x[i], y[i], xt, yt);
        ld d2=dist(xs, ys, xt, yt);
        if (d1>d2)
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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