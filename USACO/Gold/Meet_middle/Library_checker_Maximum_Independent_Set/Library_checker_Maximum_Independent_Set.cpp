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
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
ll n, m, dp[(1LL<<20)+5], ans, x, y;
vector<ll> adj[45];

ll popmax(ll a, ll b)
{
    if (__builtin_popcountll(a)>__builtin_popcountll(b)) return a;
    return b;
}

void solve()
{
    cin>>n>>m;
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll l=n/2, r=n-l;
    for (ll mask=0; mask<(1LL<<l); mask++)
    {
        bool good=true;
        for (ll u=0; u<l; u++) if (mask&(1LL<<u)) 
            for (ll v: adj[u]) if (v<l && (mask&(1LL<<v))) 
            {
                good=false;
                break;
            }
        if (good==true) dp[mask]=mask;
        for (ll u=0; u<l; u++) if (mask&(1LL<<u)) dp[mask]=popmax(dp[mask], dp[mask^(1LL<<u)]);
    }   

    for (ll mask=0; mask<(1LL<<r); mask++)
    {
        bool good=true;
        for (ll u=0; u<r; u++) if (mask&(1LL<<u)) 
            for (ll v: adj[l+u]) if (v>=l && (mask&(1LL<<(v-l))))
            {
                good=false;
                break;
            }
        if (good==true)
        {
            ll lmask=(1LL<<l)-1;
            for (ll u=0; u<r; u++) if (mask&(1LL<<u))
                for (ll v: adj[l+u]) if (v<l && (lmask&(1LL<<v))) lmask^=(1LL<<v);
            if ((__builtin_popcountll(dp[lmask])+__builtin_popcountll(mask))>ans)
            {
                ans=__builtin_popcountll(dp[lmask])+__builtin_popcountll(mask);
                x=dp[lmask];
                y=mask;
            }
        }
    }
    cout<<ans<<endl;  
    for (ll j=0; j<l; j++) if (x&(1LL<<j)) cout<<j<<" ";
    for (ll j=0; j<r; j++) if (y&(1LL<<j)) cout<<l+j<<" ";
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