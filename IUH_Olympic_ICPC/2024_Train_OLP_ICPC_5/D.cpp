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
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
     Laziness is only temporary comfort. The future will regret that day. Don't fall ll o the trap of comfort.
                The most beautiful meeting in this world is meeting the best version of yourself.
                          Practice doing things you don't like but are useful to you
                                   Success is born from problem solving
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll isprime[1000005];
vector<ll> v;

// Tính a * b mod n
long long binaryMul(long long a, long long b, long long n)
{
    a = a % n;
    long long res = 0;
    while (b)
    {
        if (b & 1)
            res = (res + a) % n;
        a = (2 * a) % n;
        b /= 2;
    }
    return res;
}

// Tính a^b mod n
long long binaryPow(long long a, long long k, long long n)
{
    a = a % n;
    long long res = 1;
    while (k)
    {
        if (k & 1)
            res = binaryMul(res, a, n);
        a = binaryMul(a, a, n) % n;
        k /= 2;
    }
    return res;
}

bool isProbablyPrime(ll n)
{
    if (n < 7)
        return n == 2 || n == 3 || n == 5;

    static const ll  repeatNum = 8;
    for (ll  i = 0; i < repeatNum; ++i)
    {
        ll a = rand() % (n - 3) + 2;
        if (binaryPow(a, n - 1, n) != 1)
            return false;
    }
    return true;
}

ll find_sqrt(ll n)
{
    ll l=1, r=1e9, ans=-1;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (mid*mid>=n) ans=mid, r=mid-1;
        else l=mid+1;
    }
    return ans;
}

void solve()
{
    ll n; cin>>n;
    ll ans=1;
    for (auto x: v)
    {
        ll cnt=0;
        while (n%x==0) ++cnt, n/=x;
        ans*=(cnt+1);
    }

    if (n>1)     
    {
        ll d=find_sqrt(n);
        if (d*d==n) ans*=3;
        else if (isProbablyPrime(n)==true) ans*=2;
        else ans*=4;
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    for (ll i=1; i<=1000000; i++) isprime[i]=1;
    isprime[1]=0;
    for (ll i=2; i*i<=1000000; i++) if (isprime[i]==1)
        for (ll j=i*i; j<=1000000; j+=i) isprime[j]=0;

    for (ll i=2; i<=1000000; i++)
        if (isprime[i]==1) v.push_back(i);

    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}