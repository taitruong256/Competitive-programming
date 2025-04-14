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
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
bool isprime[1000005];
vector<vector<ll>> ans;

void solve()
{
    ll n, m; cin>>n>>m;
    ans.resize(n+5);
    for (ll i=1; i<=n; i++) ans[i].resize(m+5);
    if (isprime[n]==false)
    {
        ll cnt=0;
        for (ll i=1; i<=m; i++)
            for (ll j=1; j<=n; j++) ans[j][i]=++cnt;
        for (ll i=1; i<=n; i++)
        {
            for (ll j=1; j<=m; j++) cout<<ans[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    else if (isprime[m]==false)
    {
        for (ll i=1; i<=n; i++)
        {
            for (ll j=1; j<=m; j++) cout<<(i-1)*m+j<<" ";
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    else 
    {
        deque<ll> ntle;
        for (ll i=2; i<=n*m; i++) if (i%2==1 && isprime[i]==true) ntle.push_back(i);
        ll i=1, j=1;
        while (!ntle.empty())
        {
            
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    for (ll i=2; i<=1000000; i++) isprime[i]=true;
    for (ll i=2; i*i<=1000000; i++) if (isprime[i]==true)
        for (ll j=i*i; j<=1000000; j+=i) isprime[j]=false;
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}