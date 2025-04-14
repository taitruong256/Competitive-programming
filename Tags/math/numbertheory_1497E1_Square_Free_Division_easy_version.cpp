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
#define cout_return(x) return void(cout<<(x)<<endl)
const ll inf = 1e18;
const ll mod = 1e9+7;
ll minprime[10000005];

ll phantich(ll n)
{
    ll res=1;
    while (n>1)
    {
        ll x=minprime[n], cnt=0;
        while (n%x==0) n/=x, ++cnt;
        if (cnt%2==1) res*=x;
    }
    return res;
}

void solve()
{
    ll n, k; cin>>n>>k;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i], a[i]=phantich(a[i]);
    ll ans=1;
    set<ll> st;
    for (ll i=1; i<=n; i++)
    {
        if (st.find(a[i])!=st.end())
        {
            ++ans;
            st.clear();
        }
        st.insert(a[i]);
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
    for (ll i=2; i*i<=10000000; i++) if (minprime[i]==0)
        for (ll j=i*i; j<=10000000; j+=i) if (minprime[j]==0) minprime[j]=i;
    for (ll i=2; i<=10000000; i++) if (minprime[i]==0) minprime[i]=i;
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}