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
                                       Where is the bug, delete it there
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 998244353;
vector<ll> adj[5];
ll dp[5][5][4000005], sum=0;

ll add(ll x, ll y)
{
    ll ans=x+y;
    if (ans>=mod) ans-=mod;
    return ans;
}

ll calc(ll u, ll pre, ll sum)
{
    if (sum==0) return 1;
    if (dp[u][pre][sum]!=-1) return dp[u][pre][sum];
    ll ans=0;
    for (ll v: adj[u])
    {
        ans=add(ans, calc(v, u, sum-1));
    }
    return dp[u][pre][sum]=ans;
}

void solve()
{
    ll c[10];
    sum=0;
    for (ll i=1; i<=4; i++) cin>>c[i], sum+=c[i];
    for (ll i=1; i<=4; i++)
        for (ll j=1; j<=4; j++)
            for (ll k=0; k<=sum; k++) dp[i][j][k]=-1;
    ll ans=0;
    for (ll i=1; i<=4; i++) ans=add(ans, calc(i, i, sum));
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(1);
    adj[3].push_back(2);
    adj[3].push_back(3);
    adj[4].push_back(4);
    adj[4].push_back(1);
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}