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
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e18;
const ll maxn=(1LL<<10)+5;
ll dp[maxn][maxn], a[maxn], n;

bool check(ll x)
{
    string s=to_string(x);
    vector<ll> cnt(15);
    for (auto c: s) ++cnt[c-'0'];
    for (ll i=0; i<10; i++) if (cnt[i]>1) return false;
    return true;
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++)
    {
        for (ll mask=0; mask<(1LL<<10); mask++)
        {
            dp[i][mask]=dp[i-1][mask];
            if (check(a[i])==false) continue;
            string s=to_string(a[i]);
            vector<ll> cnt(15);
            for (auto c: s) ++cnt[c-'0'];
            bool chk=true;
            for (ll j=0; j<10; j++) if (cnt[j]>0 && !(mask&(1LL<<j))) chk=false;
            if (chk==false) continue;
            ll old_mask=0;
            for (ll j=0; j<10; j++) if (cnt[j]>0) old_mask+=1LL<<j;
            old_mask=mask^old_mask;
            dp[i][mask]=max(dp[i][mask], dp[i-1][old_mask]+a[i]);
        }
    }
    ll ans=0;
    for (ll i=1; i<=n; i++)
        for (ll j=0; j<(1LL<<10); j++)
            ans=max(ans, dp[i][j]), dp[i][j]=0;
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}