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
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ll MOD = (1LL<<61)-1;
struct HashedString
{
    ll n;  
    ll maxn = 1e6+5;
    ll base = 331;
    string s;
    vector<ll> pw, hs;

    HashedString() {}
    void init(string _s)
    {
        maxn = n = _s.size(); s = _s; _s = " " + _s; s=" "+s;
        base = uniform_int_distribution<ll>(0, MOD - 1)(rng);
        pw.resize(maxn+5, 1);
        hs.resize(maxn+5, 0);
        for (ll i = 1; i <= maxn; i++) pw[i] = mul(pw[i - 1], base);
        for (ll i = 1; i <= n; i++) hs[i] = add(hs[i - 1], mul(_s[i] - '$' + 1, pw[i - 1]));
    }

    ll mul(ll a, ll b) { return ((__int128)a * b) % MOD; }
    ll add(ll a, ll b) { return (a + b) % MOD; }

    ll gethash(ll l, ll r)
    {
        ll x = (hs[r] - hs[l - 1] + MOD) % MOD;  
        x = mul(x, pw[maxn - r]);
        return x;
    }
} hsh;

ll calc_lcp(ll &a, ll &b)
{
    ll k=min(hsh.n-a+1, hsh.n-b+1);
    ll l=1, r=k, ans=0;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (hsh.gethash(a, a+mid-1)==hsh.gethash(b, b+mid-1)) l=mid+1, ans=mid;
        else r=mid-1;
    }
    return ans;
}

bool comp(ll &a, ll &b)
{
    ll ans=calc_lcp(a, b);
    return hsh.s[a+ans]<hsh.s[b+ans];
}

struct SuffixArray
{
    string s;
    vector<ll> pos, lcp;
    ll n;

    SuffixArray(){}
    SuffixArray(string _s)
    {
        s=_s;
        s=_s+"$";
        n=s.size()-1;
        pos.resize(n+5);
        lcp.resize(n+5);
        for (ll i=1; i<=n; i++) pos[i]=i;
        hsh.init(s);
        sort(pos.begin()+1, pos.begin()+n+1, comp);
        for (ll i=1; i<=n-1; i++) lcp[i]=calc_lcp(pos[i], pos[i+1]);
    }
};

void solve()
{
    string s; cin>>s;
    SuffixArray sa(s);
    cout<<s.size()<<" ";
    for (ll i=1; i<=sa.n; i++) cout<<sa.pos[i]-1<<" "; 
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