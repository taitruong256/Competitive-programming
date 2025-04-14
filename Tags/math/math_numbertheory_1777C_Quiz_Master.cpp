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
const ll mod = 1e9+7;
vector<ll> divisor[100005];

void solve()
{
    ll n, m; cin>>n>>m;
    ll a[n+5], cnt[m+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=0; i<=m; i++) cnt[i]=0;

    sort(a+1, a+n+1);
    ll l=1, quiz=0, ans=1e9;
    for (ll r=1; r<=n; r++)
    {
        for (auto x: divisor[a[r]]) 
        {
            if (x>m) break;
            ++cnt[x];
            if (cnt[x]==1) ++quiz;
        }
        while (quiz==m)
        {
            ans=min(ans, a[r]-a[l]);
            for (auto x: divisor[a[l]]) 
            {
                if (x>m) break;
                --cnt[x];
                if (cnt[x]==0) --quiz;
            }
            ++l;
        }
    }
    if (ans==1e9) ans=-1;
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
    for (ll i=1; i<=100000; i++)
        for (ll j=i; j<=100000; j+=i) divisor[j].push_back(i);
    for (ll i=1; i<=100000; i++) sort(divisor[i].begin(), divisor[i].end());
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}