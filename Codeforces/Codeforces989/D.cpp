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
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    set<ll> st0, st1, st2;
    for (ll i=1; i<=n; i++)
        if (a[i]==0) st0.insert(i);
        else if (a[i]==1) st1.insert(i);
        else st2.insert(i);
    vector<pair<ll, ll>> ans;
    while (true)
    {
        bool change=false;
        while (!st1.empty() && !st0.empty() && *st1.begin()<*st0.rbegin())
        {
            change=true;
            ll x=*st1.begin();
            ll y=*st0.rbegin();
            ans.push_back({x, y});  cerr<<x<<" "<<y<<endl;
            st1.erase(x);
            st1.insert(y);
            st0.erase(y);
            st0.insert(x);
        }
        while (!st2.empty() && !st1.empty() && *st2.begin()<*st1.rbegin())
        {
            change=true;
            ll x=*st2.begin();
            ll y=*st1.rbegin();
            ans.push_back({x, y});  cerr<<x<<" "<<y<<endl;
            st2.erase(x);
            st2.insert(y);
            st1.erase(y);
            st1.insert(x);
        }
        if (change==false) break;
    }
    cout<<ans.size()<<endl;
    for (auto [u, v]: ans) cout<<u<<" "<<v<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}