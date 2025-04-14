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
vector<ll> quiz[100005];

void solve()
{
    ll n, m; cin>>n>>m;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    if (m==1)
    {
        cout<<0<<endl;
        return;
    }
    for (ll i=1; i<=n; i++) 
    {
        for (ll j=1; j*j<=a[i]; j++) if (a[i]%j==0)
        {
            quiz[j].push_back(a[i]);
            if (j*j!=a[i]) quiz[a[i]/j].push_back(a[i]);
        }
    }
    for (ll i=1; i<=m; i++) 
    {
        if (quiz[i].size()==0)
        {
            cout<<-1<<endl;
            for (auto &j: quiz) j.clear();
            return;
        }
        sort(quiz[i].begin(), quiz[i].end());
    }
    ll mx=quiz[m].front(), mn=quiz[m].front();
    for (ll i=m-1; i>=2; i--)
    {
        ll pos=upper_bound(quiz[i].begin(), quiz[i].end(), mx)-quiz[i].begin();
        if (pos>0) --pos;
        
    }
    for (auto &j: quiz) j.clear();
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