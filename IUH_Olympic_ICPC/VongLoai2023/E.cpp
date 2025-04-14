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
#define ll int
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
ll n, a[20005], ans, x, y, c, s;
long long pre[20005];
map<pair<ll, ll>, ll> dp;

ll chiadetri(ll l, ll r, ll cnt)
{
    if (dp.find({l, r})!=dp.end()) return dp[{l, r}];
    ans=max(ans, cnt);
    if (l>r) return cnt;
    s=pre[r]-pre[l-1];
    if (s%2==1) return 0;
    ll u=lower_bound(pre+l, pre+r+1, pre[l-1]+s/2)-pre;
    ll v=upper_bound(pre+l, pre+r+1, pre[l-1]+s/2)-pre;
    for (ll i=u; i<v; i++) if (pre[i]-pre[l-1]==s/2)
    {
        chiadetri(l, i, cnt+1);
        chiadetri(i+1, r, cnt+1);
    }
    return cnt;
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) pre[i]=pre[i-1]+a[i];
    ans=0, x=1, y=n, c=0;
    dp.clear();
    chiadetri(x, y, c);
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