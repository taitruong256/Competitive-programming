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
#define ll int
#define endl '\n'
const ll mod = 1e9+7;
ll n, a[200005];
pair<ll, ll> sum[5000005];

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n-1; i++)
    {
        for (ll j=i+1; j<=n; j++) 
        {
            ll u=sum[a[i]+a[j]].first, v=sum[a[i]+a[j]].second;
            if (u==0 || v==0) continue;
            if (u!=i && u!=j && v!=i && v!=j) 
            {
                cout<<"YES\n";
                cout<<i<<" "<<j<<" "<<u<<" "<<v;
                return;
            }
        }
        for (ll j=i+1; j<=n; j++)
            sum[a[i]+a[j]]={i, j};
    }
    cout<<"NO";
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