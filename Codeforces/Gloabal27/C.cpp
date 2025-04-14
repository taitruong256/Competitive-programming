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
    ll p=1;
    while (p<=n) p*=2; 
    p/=2;
    vector<ll> ans;
    ans.push_back(0);
    if (n%2==1)
    {
        ans.push_back(2);
        ans.push_back(1);
        ans.push_back(3);
        for (ll i=4; i<=n; i++) ans.push_back(i);
        ll k=0; 
        for (ll i=1; i<=n; i++) if (i%2==1) k&=ans[i]; else k|=ans[i];
        cout<<k<<endl;
        for (ll i=1; i<=n; i++) cout<<ans[i]<<" "; cout<<endl;
    }
    else 
    {
        for (ll i=p+1; i<=n; i++) ans.push_back(i);
        ans.push_back(2);
        ans.push_back(1);
        ans.push_back(3);
        for (ll i=4; i<=p; i++) ans.push_back(i);
        ll k=0; 
        for (ll i=1; i<=n; i++) if (i%2==1) k&=ans[i]; else k|=ans[i];
        cout<<k<<endl;
        for (ll i=1; i<=n; i++) cout<<ans[i]<<" "; cout<<endl;
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