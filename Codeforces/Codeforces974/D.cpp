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

ll n, d, k; 
vector<ll> st[200005], fi[200005];

void solve()
{
    cin>>n>>d>>k;
    for (ll i=1; i<=k; i++)
    {
        ll l, r; cin>>l>>r;
        st[l].push_back(i);
        fi[r].push_back(i);
    }




    set<ll> diff1;
    for (ll i=1; i<=d; i++) 
        for (auto x: st[i]) 
            diff1.insert(x);
    ll ans1=1, mx1=diff1.size();
    // cout<<mx1<<endl;
    for (ll i=2; i<=n-d+1; i++)
    {
        if (i+d-1<=n) 
            for (auto x: st[i+d-1])
                diff1.insert(x);
        for (auto x: fi[i-1])
            diff1.erase(x);
        if (diff1.size()>mx1)
        {
            mx1=diff1.size();
            ans1=i;
        }
        // cout<<diff1.size()<<endl;
    }
    cout<<ans1<<" ";




    set<ll> diff2;
    for (ll i=1; i<=d; i++) 
        for (auto x: st[i]) 
            diff2.insert(x);
    ll ans2=1, mx2=diff2.size();
    // cout<<mx2<<endl;
    for (ll i=2; i<=n-d+1; i++)
    {
        if (i+d-1<=n) 
            for (auto x: st[i+d-1])
                diff2.insert(x);
        for (auto x: fi[i-1])
            diff2.erase(x);
        if (diff2.size()<mx2)
        {
            mx2=diff2.size();
            ans2=i;
        }
        // cout<<diff2.size()<<endl;
    }
    cout<<ans2<<endl;

    for (ll i=1; i<=n; i++) 
    {
        st[i].clear();
        fi[i].clear();
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