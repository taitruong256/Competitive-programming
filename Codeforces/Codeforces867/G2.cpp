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
const ll inf = 1e18;
const ll mod = 1e9+7;
const ll maxn= 1e6+100;
vector<ll> uoc[maxn+5];

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    ll ans=0;
    set<ll> st;
    map<ll, ll> cnt;
    for (ll i=1; i<=n; i++) cin>>a[i], ++cnt[a[i]], st.insert(a[i]);
    for (auto [x, y]: cnt)
    {
        ans+=y*(y-1)*(y-2);
        if (x<=1000000)
        {
            for (auto j: uoc[x]) 
                if (x%j==0 && cnt.find(x/j)!=cnt.end() && cnt.find(x*j)!=cnt.end()) 
                    ans+=cnt[x/j]*cnt[x]*cnt[x*j];
        }
        else 
        {
            for (ll j=2; ; j++) 
            {
                if (x*j>=1000000000) break;
                if (x%j==0 && cnt.find(x/j)!=cnt.end() && cnt.find(x*j)!=cnt.end()) 
                    ans+=cnt[x/j]*cnt[x]*cnt[x*j];
            }
        }
    }
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
    for (ll i=2; i<=maxn; i++)
        for (ll j=i; j<=maxn; j+=i) uoc[j].push_back(i);
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}