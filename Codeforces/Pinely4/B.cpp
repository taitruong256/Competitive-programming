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

void solve()
{
    ll n; cin>>n;
    ll b[n+5];
    for (ll i=1; i<=n-1; i++) cin>>b[i];
    ll ans[n+5][35];
    for (ll i=1; i<=n; i++)
        for (ll j=0; j<30; j++) 
            ans[i][j]=0;
    for (ll i=1; i<=n-1; i++)
    {
        for (ll j=0; j<30; j++)
        {
            ll bit=b[i]&(1LL<<j);
            if (bit!=0) ans[i][j]=ans[i+1][j]=1;
        }
    }
    // for (ll i=1; i<=n-1; i++)
    // {
    //     for (ll j=0; j<30; j++) cout<<ans[i][j]<<" ";
    //     cout<<endl;
    // }
    ll a[n+5];
    for (ll i=1; i<=n; i++)
    {
        ll x=0;
        for (ll j=0; j<30; j++) if (ans[i][j]==1) x+=(1LL<<j);
        a[i]=x;
    }
    for (ll i=1; i<=n-1; i++) if ((a[i]&a[i+1])!=b[i])
    {
        cout<<-1<<endl;
        return;
    }
    for (ll i=1; i<=n; i++) cout<<a[i]<<" "; 
    cout<<endl;
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