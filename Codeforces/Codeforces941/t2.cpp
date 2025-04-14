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
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll n, m, color[200005][15], black[200005], white[200005];

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++)
        {
            if ((i+j)%2==0) color[i][j]=0, white[i]+=1;
            else color[i][j]=1, black[i]+=1;
        }
    
    for (ll i=1; i<=n; i++) white[i]+=white[i-1];
    for (ll i=n; i>=1; i--) black[i]+=black[i+1];


    ll q; cin>>q;
    while (q--)
    {
        ll x, y; cin>>x>>y;
        if (color[x][y]==0)
        {
            for (ll i=x; i<=n; i++) --white[i];
            for (ll i=x; i>=1; i--) ++black[i];
        }
        else 
        {
            for (ll i=x; i>=1; i--) --black[i];
            for (ll i=x; i<=n; i++) ++white[i];
        }
        color[x][y]=1-color[x][y];
        ll ans=1e18;
        for (ll i=1; i<=n; i++) ans=min(ans, white[i]+black[i+1]);
        cout<<ans<<endl;
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
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}