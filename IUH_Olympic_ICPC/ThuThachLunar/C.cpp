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
const ll mod = 1e9+7;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
struct HashedString
{
    ll n;  
    ll maxn = 1e6+5; // dat maxn theo gioi han cua de bai, neu time dat 3 dong const ra ngoai toan cuc
    ll base = 31;
    const ll MOD = (1LL<<61)-1;
    string s;
    vector<ll> pw, hs;

    HashedString() {}
    HashedString(string _s)
    {
        maxn = n = _s.size(); s = _s; _s = " " + _s;
        base = uniform_int_distribution<ll>(0, MOD - 1)(rng);
        pw.resize(maxn+5, 1);
        hs.resize(maxn+5, 0);
        for (ll i = 1; i <= maxn; i++) pw[i] = mul(pw[i - 1], base);
        for (ll i = 1; i <= n; i++) hs[i] = add(hs[i - 1], mul(_s[i] - 'a' + 1, pw[i - 1])); //chu y _s khong phai s
    }

    ll mul(ll a, ll b) { return ((__int128)a * b) % MOD; }
    ll add(ll a, ll b) { return (a + b) % MOD; }

    ll gethash(ll l, ll r)
    {
        ll x = (hs[r] - hs[l - 1] + MOD) % MOD;  
        x = mul(x, pw[maxn - r]);
        return x;
    }
};

set<ll> st;
string s;
ll a[30], K, n, val[30];

void solve()
{
    cin>>s;
    n=s.size();
    for (ll i=0; i<26; i++) cin>>a[i], a[i]=1-a[i];
    cin>>K;
    HashedString hs(s);
    s=" "+s;
    for (ll i=1; i<=n; i++)
    {
        vector<ll> val(30);
        for (ll j=i; j<=n; j++)
        {
            ++val[s[j]-'a'];
            ll cnt=0;
            for (ll l=0; l<26; l++) cnt+=val[l]*a[l];
            if (cnt<=K) st.insert(hs.gethash(i, j));
        }
    }
    cout<<st.size();
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