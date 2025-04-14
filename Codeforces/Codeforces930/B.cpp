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
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

const ll MOD = (1LL<<61)-1; 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
ll base = uniform_int_distribution<ll>(0, MOD - 1)(rng);  
struct HashedString
{
    ll n;  
    ll maxn = 1e6+5;
    string s;
    vector<ll> pw, hs;

    void init(string _s)
    {
        maxn = n = _s.size(); s = " "+_s; 
        pw.resize(0);
        pw.resize(maxn+5, 1);
        hs.resize(0);
        hs.resize(maxn+5, 0);
        for (ll i = 1; i <= maxn; i++) pw[i] = mul(pw[i - 1], base);
        for (ll i = 1; i <= n; i++) hs[i] = add(hs[i - 1], mul(s[i] - '0' + 1, pw[i - 1])); 
    }

    ll mul(ll a, ll b) { return ((__int128)a * b) % MOD; }
    ll add(ll a, ll b) { return (a + b) % MOD; }
    ll sub(ll a, ll b) { return (a-b+MOD)%MOD;}
} hsh1, hsh2;

ll n; 
string s1, s2;

ll gethash(ll x, ll len)
{
    ll a=0, b=0, c=0, res=0;
    if (len<=x)
    {
        a=hsh1.hs[len];
        b=hsh1.sub(hsh1.hs[x], hsh1.hs[len]);
        c=hsh1.mul(hsh1.sub(hsh2.hs[n], hsh2.hs[x-1]), base);
        b=0;
        c=0;
        res=hsh1.add(res, a);
        res=hsh1.add(res, b);
        res=hsh1.add(res, c);
    }
    else 
    {
        a=hsh1.hs[x];
        b=hsh1.mul(hsh1.sub(hsh2.hs[len-1], hsh2.hs[x-1]), base);
        c=hsh1.mul(hsh1.sub(hsh2.hs[n], hsh2.hs[len-1]), base);
        c=0;
        res=hsh1.add(res, a);
        res=hsh1.add(res, b);
        res=hsh1.add(res, c);
    }
    return res;
}

char getchar(ll x, ll pos)
{
    if (pos<=x) return hsh1.s[pos];
    return hsh2.s[pos-1];
}

void solve()
{
    cin>>n;
    cin>>s1;
    cin>>s2;
    hsh1.init(s1);
    hsh2.init(s2);
    ll mn=1, cnt=1;
    for (ll i=2; i<=n; i++)
    {
        if (gethash(i, n+1)==gethash(mn, n+1))
        {
            ++cnt;
            continue;
        }
        ll l=1, r=n+1, ans=-1;
        while (l<=r)
        {
            ll mid=(l+r)/2;
            if (gethash(i, mid)==gethash(mn, mid)) ans=mid, l=mid+1;
            else r=mid-1;
        }
        assert(ans!=-1);
        if (getchar(i, ans+1)<getchar(mn, ans+1)) mn=i, cnt=1;
    }
    s1=" "+s1;
    s2=" "+s2;
    for (ll i=1; i<=mn; i++) cout<<s1[i];
    for (ll i=mn; i<=n; i++) cout<<s2[i];
    cout<<endl;
    cout<<cnt<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}