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
const ll maxn = 1e6;
ll minprime[maxn+5];

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];

    map<ll, ll> cnt;
    for (ll i=1; i<=n; i++) ++cnt[a[i]];
    ll ans=0;
    for (auto [x, y]: cnt) 
    {
        ans+=y*(y-1)*(y-2);
        vector<pair<ll, ll>> thuaso;
        ll n=x;
        while (n>1)
        {
            ll p=minprime[n], c=0;
            while (n%p==0) ++c, n/=p;
            thuaso.push_back({p, c});
        }
        for (auto [u, v]: thuaso) if (v>=2)
        {
            ll p=1; 
            for (ll i=1; i<=v/2; i++)
            {
                p*=u;
                ans+=cnt[x]*cnt[x/p]*cnt[x/p/p];
            }
        }
        for (auto [u, v]: thuaso) cout<<u<<" "<<v<<"    "; cout<<endl;
        cout<<x<<" "<<ans<<endl;
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
    for (ll i=2; i*i<=maxn; i++) if (minprime[i]==0)
        for (ll j=i*i; j<=maxn; j+=i) if (minprime[j]==0) minprime[j]=i;
    for (ll i=1; i<=maxn; i++) if (minprime[i]==0) minprime[i]=i;
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}