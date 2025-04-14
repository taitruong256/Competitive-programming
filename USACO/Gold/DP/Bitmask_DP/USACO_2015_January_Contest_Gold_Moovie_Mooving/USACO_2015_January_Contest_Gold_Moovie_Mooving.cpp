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
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll maxn = 1LL<<20;
const ll mod = 1e9+7;

void setIO(string s)
{
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}
ll n, l, d[25], dp[maxn+5];
vector<ll> movie[25];

void solve()
{
    setIO("movie");
    cin>>n>>l;
    for (ll i=0; i<n; i++)
    {
        cin>>d[i];
        ll m; cin>>m;
        for (ll j=0; j<m; j++) 
        {
            ll x; cin>>x;
            movie[i].push_back(x);
        }
    }

    for (ll i=0; i<(1LL<<n); i++) dp[i]=-1e18;
    dp[0]=0;
    ll ans=1e9;
    for (ll mask=1; mask<(1LL<<n); mask++)
    {
        for (ll j=0; j<n; j++) if (mask&(1LL<<j))
        {
            ll old_mask=mask^(1LL<<j);
            if (old_mask==-1e18) continue;
            auto it=upper_bound(movie[j].begin(), movie[j].end(), dp[old_mask]);
            if (it!=movie[j].begin())
            {
                --it;
                dp[mask]=max(dp[mask], *it+d[j]);
            }
        }
        ll cnt=__builtin_popcountll(mask);
        if (dp[mask]>=l) ans=min(ans, cnt); 
    }
    if (ans==1e9) ans=-1;
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}