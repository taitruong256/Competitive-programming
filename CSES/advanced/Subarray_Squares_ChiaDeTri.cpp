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
const ll inf = 1LL<<60;
ll n, k;
ll a[3005], pref[3005];
vector<ll> dp_before(3005), dp_cur(3005);

ll cost(ll l, ll r)
{
    return (pref[r]-pref[l-1])*(pref[r]-pref[l-1]);
}

void calc(ll l, ll r, ll x, ll y)
{
    if (l>r) return;
    ll mid=(l+r)/2;
    pair<ll, ll> best={inf, -1};
    for (ll i=x; i<=y; i++)
        best=min(best, {dp_before[i-1]+cost(i, mid), i});
    dp_cur[mid]=best.first;
    calc(l, mid-1, x, best.second);
    calc(mid+1, r, best.second, y);
}

void solve()
{
    cin>>n>>k;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) pref[i]=pref[i-1]+a[i];

    for (ll i=1; i<=n; i++) dp_before[i]=cost(1, i);
    for (ll i=1; i<=n; i++) cout<<dp_before[i]<<" "; cout<<endl;
    for (ll i=2; i<=k; i++)
    {
        calc(1, n, 1, n);
        dp_before=dp_cur;
        for (ll j=1; j<=n; j++) cout<<dp_before[j]<<" "; cout<<endl;
    }
    cout<<dp_before[n];
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