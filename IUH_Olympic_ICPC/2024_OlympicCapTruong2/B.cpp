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

ll is_prime[205];

void solve()
{
    for (ll i=2; i<=200; i++)
    {
        is_prime[i]=1;
        for (ll j=2; j*j<=i; j++) if (i%j==0) is_prime[i]=0;
    }

    ll l, r; cin>>l>>r;
    ll ans=0;
    for (ll i=1; i<=9; i++) if (l<=i && i<=r && is_prime[i]==1) ++ans;
    for (ll i=1; i<=1000000; i++)
    {
        string s=to_string(i);
        string t=s;
        reverse(t.begin(), t.end());
        ll x=0, sumdigit=0;
        for (auto c: s) x=x*10+c-'0', sumdigit+=c-'0';
        for (auto c: t) x=x*10+c-'0', sumdigit+=c-'0';
        if (l<=x && x<=r && is_prime[sumdigit]==true) ++ans;
    }
    for (ll i=1; i<=100000; i++)
    {
        string s=to_string(i);
        string t=s;
        reverse(t.begin(), t.end());
        ll x=0, sumdigit=0;
        for (char c1='0'; c1<='9'; c1++)
        {
            x=0;
            sumdigit=0;
            for (auto c2: s) x=x*10+c2-'0', sumdigit+=c2-'0';
            x=x*10+c1-'0'; sumdigit+=c1-'0';
            for (auto c3: t) x=x*10+c3-'0', sumdigit+=c3-'0';
            if (l<=x && x<=r && is_prime[sumdigit]==true) ++ans;
        }
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}
