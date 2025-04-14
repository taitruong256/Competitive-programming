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
                                       Where is the bug, delete it there
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

const ll mod = 998244353;
const ll root = 10;
const ld PI=acos(-1);

ll binpow(ll x, ll n, ll mod)
{
    ll ans=1;
    while (n>0)
    {
        if (n%2==1) ans=(ans*x)%mod;
        x=(x*x)%mod;
        n/=2;
    }
    return ans;
}

void ntt(vector<ll> &a, ll n, ll inv)    //n = 2^x
{
    if (n==1) return;
    vector<ll> a_even(n/2), a_odd(n/2);
    for (ll i=0, j=0; i<n; i+=2)
    {
        a_even[j]=a[i];
        a_odd[j]=a[i+1];
        ++j;
    }
    
    ntt(a_even, n/2, inv);
    ntt(a_odd, n/2, inv);

    ll g=binpow(root, (mod-1)/n, mod);
    if (inv==true) g=binpow(g, mod-2, mod);
    ll w=1;
    for (ll i=0; i<n/2; i++)
    {
        a[i]=(a_even[i]+w*a_odd[i])%mod;
        a[i+n/2]=(a_even[i]-w*a_odd[i]+mod*mod)%mod;
        w=(w*g)%mod;
    }
}

vector<ll> mul(vector<ll> a, vector<ll> b)
{
    ll n=1;
    while (n<a.size()+b.size()) n*=2;
    a.resize(n);
    b.resize(n);
    ntt(a, n, false);
    ntt(b, n, false);
    for (ll i=0; i<n; i++) a[i]=(a[i]*b[i])%mod;
    ntt(a, n, true);
    ll inv=binpow(n, mod-2, mod);
    for (auto &i: a) i=(i*inv)%mod;
    return a;
}

void solve()
{
    ll n, m; cin>>n>>m;
    vector<ll> a(n), b(m);
    for (ll i=0; i<n; i++) cin>>a[i];
    for (ll i=0; i<m; i++) cin>>b[i];
    vector<ll> c=mul(a, b);
    for (ll i=0; i<n+m-1; i++) cout<<c[i]<<" ";
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