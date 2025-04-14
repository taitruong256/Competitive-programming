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

void solve()
{
    ll n, m; cin>>n>>m;
    ll a[n+5][m+5], sum[n+5], total=0;
    for (ll i=1; i<=n; i++)
    {
        sum[i]=0;
        for (ll j=1; j<=m; j++) 
        {
            cin>>a[i][j];
            sum[i]+=a[i][j];
            total+=a[i][j];
        }
    }
    if (total%n!=0)
    {
        cout<<-1<<endl;
        return;
    }
    
    ll avg=total/n;
    vector<ll> greater, less;
    vector<pair<pair<ll, ll>, ll>> ans;
    for (ll i=1; i<=m; i++)
    {
        for (ll j=1; j<=n; j++) 
        {
            if (sum[j]>avg && a[j][i]==1) greater.push_back(j);
            if (sum[j]<avg && a[j][i]==0) less.push_back(j);
        }
        for (ll j=0; j<min(greater.size(), less.size()); j++) 
        {
            ans.push_back({{greater[j], less[j]}, i});
            --sum[greater[j]];
            ++sum[less[j]];
        }
        greater.clear();
        less.clear();
    }
    cout<<ans.size()<<endl;
    for (auto i: ans) cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
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