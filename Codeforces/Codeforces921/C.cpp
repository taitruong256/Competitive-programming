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
const ll mod = 1e9+7;
ll n, k, m, dp[30][30], lst[30];
string s, t;

ll calc_dp(ll p, ll c)
{
    if (dp[p][c]!=-1) return dp[p][c];
    if (p==n) 
    {
      ll ans=0;
      for (ll i=m; i>=1; i--) 
        if (s[i-1]-'a'+1==c) 
        {
          ans=i;
          break;
        }
      return dp[p][c]=ans;
    }
    
    ll mn=1e9;
    for (ll i=1; i<=k; i++) mn=min(mn, calc_dp(p+1, i));
    ll ans=0;
    for (ll i=mn-1; i>=1; i--) if (s[i-1]-'a'+1==c) 
    {
      ans=i;
      break;
    }
    return dp[p][c]=ans;
}

void solve()
{
    cin>>n>>k>>m;
    cin>>s;
    if (m<n) 
    {
      cout<<"NO\n";
      for (ll i=0; i<n; i++) cout<<'a';
      cout<<endl;
      return;
    }
    t.clear();
    for (ll i=0; i<=27; i++)
      for (ll j=0; j<=27; j++)
        dp[i][j]=-1;

    calc_dp(0, 0);
    ll mn=1e18;
    for (ll i=1; i<=k; i++) mn=min(mn, dp[1][i]);

    // for (ll i=1; i<=n; i++)
    // {
    //   for (ll j=1; j<=k; j++) cout<<dp[i][j]<<" ";
    //   cout<<endl;
    // }

    if (mn!=0) cout<<"YES\n";
    else 
    {
      cout<<"NO\n";
      for (ll i=1; i<=n; i++)
      {
          ll mn=1;
          for (ll j=2; j<=k; j++) if (dp[i][j]<dp[i][mn]) mn=j;
          t.push_back('a'+mn-1);
      }
      cout<<t<<endl;
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
    ll tc; cin>>tc;
    while (tc--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}