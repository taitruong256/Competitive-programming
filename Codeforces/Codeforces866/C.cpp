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

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    map<ll, ll> cnt;
    for (ll i=1; i<=n; i++) 
    {
        cin>>a[i];
        ++cnt[a[i]];
    }
    ll mex=0;
    for (ll i=0; i<=n; i++) if (cnt[i]==0)
    {
        mex=i;
        break;
    }
    if (mex==n)
    {
        cout<<"NO\n";
        return;
    }
    if (cnt[mex+1]==0)
    {
        cout<<"YES\n";
        return;
    }
    ll l=-1, r=-1;
    for (ll i=1; i<=n; i++) if (a[i]==mex+1)
    {
        l=i;
        break;
    }
    for (ll i=n; i>=1; i--) if (a[i]==mex+1)
    {
        r=i;
        break;
    }
    for (ll i=l; i<=r; i++) a[i]=mex;
    cnt.clear();
    for (ll i=1; i<=n; i++) ++cnt[a[i]];
    ll mex2=0;
    for (ll i=1; i<=n; i++) if (cnt[i]==0)
    {
        mex2=i;
        break;
    }
    if (mex+1==mex2) cout<<"YES\n";
    else cout<<"NO\n";
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