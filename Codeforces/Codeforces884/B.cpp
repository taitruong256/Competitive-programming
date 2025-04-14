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

bool isprime(ll n)
{
    if (n<2) return false;
    for (ll i=2; i*i<=n; i++) if (n%i==0) return false;
    return true;
}

void solve()
{
    ll n; cin>>n;  
    ll a[n+5], b[n+5];
    for (ll i=1; i<=n; i++) a[i]=i;
    ll mx=0;
    do
    {
        ll val=0;
        for (ll i=1; i<=n; i++)
            for (ll j=i; j<=n; j++) 
            {
                vector<ll> cnt(n+5);
                for (ll k=i; k<=j; k++) ++cnt[a[k]];
                ll mex=1;
                for (ll k=1; k<=n+1; k++) if (cnt[k]==0) 
                {
                    mex=k;
                    break;
                }
                if (isprime(mex)==true) ++val; 
            }
        if (val>mx)
        {
            mx=val;
            for (ll i=1; i<=n; i++) b[i]=a[i];
        }
    }
    while (next_permutation(a+1, a+n+1));
    for (ll i=1; i<=n; i++) a[i]=i;
    do
    {
        ll val=0;
        for (ll i=1; i<=n; i++)
            for (ll j=i; j<=n; j++) 
            {
                vector<ll> cnt(n+5);
                for (ll k=i; k<=j; k++) ++cnt[a[k]];
                ll mex=1;
                for (ll k=1; k<=n+1; k++) if (cnt[k]==0) 
                {
                    mex=k;
                    break;
                }
                if (isprime(mex)==true) ++val; 
            }
        if (val==mx)
        {
            mx=val;
            for (ll i=1; i<=n; i++) b[i]=a[i];
            for (ll i=1; i<=n; i++) cout<<b[i]<<" "; cout<<endl;
        }
    }
    while (next_permutation(a+1, a+n+1)); cout<<endl;
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