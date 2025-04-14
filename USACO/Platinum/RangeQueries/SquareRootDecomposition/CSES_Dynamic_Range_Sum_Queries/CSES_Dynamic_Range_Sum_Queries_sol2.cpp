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
ll n, q;
vector<ll> arr, prefix;
vector<pair<ll, ll>> updates;

void build()
{
    updates.clear();
    prefix.resize(n+5);
    prefix[0]=0;
    for (ll i=1; i<=n; i++) prefix[i]=prefix[i-1]+arr[i];
}

void solve()
{
    cin>>n>>q;
    arr.resize(n+5);
    for (ll i=1; i<=n; i++) cin>>arr[i];
    build();
    while (q--)
    {
        ll type; cin>>type;
        if (type==1)
        {
            ll pos, val; cin>>pos>>val;
            updates.push_back({pos, val-arr[pos]});
            arr[pos]=val;
        }
        else 
        {
            ll l, r; cin>>l>>r;
            ll ans=prefix[r]-prefix[l-1];
            for (auto [idx, val]: updates) if (l<=idx && idx<=r) ans+=val;
            cout<<ans<<endl;
        }
        if (updates.size()*updates.size()>=n) build();
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
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}