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
                                Hãy hoàn thành công việc một cách cẩu thả nhất
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
vector<pair<ll, ll>> truoc[6][50], sau[6][50];
map<vector<ll>, ll> cnt;

void solve()
{
    ll n; cin>>n;
    string s[n+5];
    for (ll i=1; i<=n; i++) cin>>s[i];
    for (ll i=1; i<=n; i++)
    {
        ll m=s[i].size();
        vector<ll> pref(m+5);
        for (ll j=1; j<=m+1; j++) pref[j]=pref[j-1]+s[i][j-1]-'0';
        for (ll j=0; j<=m+1; j++) ++cnt[{m, j, pref[j], m-j, pref[m]-pref[j]}];
    }
    
    ll ans=0;
    for (ll i=1; i<=n; i++)
    {
        ll m=s[i].size();
        vector<ll> pref(m+5);
        for (ll j=1; j<=m; j++) pref[j]=pref[j-1]+s[i][j-1]-'0';
        for (ll len=1; len<=5; len++)
        {
            for (ll j=1; j<=m; j++)
                for (ll sum=pref[j]; sum<=45; sum++) 
                {
                    if (j<=len) ans+=cnt[{2*len-m, len-j, sum-pref[j], len, sum}];
                    else ans+=cnt[{2*len-m, 0, 0, 2*len-j, 2*sum-pref[j]}];
                }
        }
    } 
    cout<<ans<<endl;
    cout<<endl;
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