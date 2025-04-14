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

ll n, k, q;
vector<vector<ll>> arr, or_arr;

void solve()
{
    cin>>n>>k>>q;
    arr.resize(k+5);
    for (ll i=1; i<=k; i++) arr[i].resize(n+5);
    or_arr.resize(k+5);
    for (ll i=1; i<=k; i++) or_arr[i].resize(n+5);

    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=k; j++)
        {
            cin>>arr[j][i];
            or_arr[j][i]=(arr[j][i]|or_arr[j][i-1]);
        }

    while (q--)
    {
        vector<pair<ll, ll>> seg;
        ll m; cin>>m;
        while (m--)
        {
            ll r, c;
            char o; 
            cin>>r>>o>>c;
            ll L=1, R=n;
            if (o=='>')
                L=upper_bound(or_arr[r].begin()+1, or_arr[r].begin()+n+1, c)-or_arr[r].begin();
            else 
                R=lower_bound(or_arr[r].begin()+1, or_arr[r].begin()+n+1, c)-or_arr[r].begin()-1;
            seg.push_back({L, R});
        }
        ll L=1, R=n;
        for (auto [x, y]: seg) L=max(L, x), R=min(R, y);
        if (L<=R) cout<<L<<endl;
        else cout<<-1<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    solve();
    return 0;
}