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

vector<vector<char>> a;
ll n, m;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    ll t; cin>>t;
    while (t--)
    {
        cin>>n>>m;
        a.resize(n+5);
        ll ans=0;
        for (ll i=1; i<=n; i++) a[i].resize(m+5);

        for (ll i=1; i<=n; i++)
            for (ll j=1; j<=m; j++) cin>>a[i][j];


        for (ll layer=1; layer<=n/2; layer++)
        {
            string v;
            for (ll i=layer; i<=m-layer+1; i++) v.push_back(a[layer][i]);
            for (ll i=layer+1; i<=n-layer; i++) v.push_back(a[i][m-layer+1]);
            for (ll i=m-layer+1; i>=layer; i--) v.push_back(a[n-layer+1][i]);
            for (ll i=n-layer; i>=layer+1; i--) v.push_back(a[i][layer]);
            ll m=v.size();
            v=v+v;
            // cout<<v<<endl;
            if (m>=4) for (ll i=0; i<m; i++) if (v[i]=='1' && v[i+1]=='5' && v[i+2]=='4' && v[i+3]=='3') ++ans;
        }
        cout<<ans<<endl;
        for (ll i=1; i<=n; i++) a[i].clear();
        a.clear();
    }
    return 0;
}