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

struct HashedString
{
    vector<ll> pw, hash;
    ll n, base, mod = (1LL<<61)-1;
    string s;
    mt19937 rng{(uint32_t)chrono::steady_clock::now().time_since_epoch().count()};
    const ll B = uniform_int_distribution<ll>(30, mod - 1)(rng); 

    HashedString() {}
    HashedString(string _s, ll _base)
    {
        n = _s.size(); base = _base; s = _s; _s = " " + _s;
        pw.resize(n + 5); 
        hash.resize(n + 5);
        pw[0] = 1;
        for (ll i = 1; i <= n; i++) pw[i] = mul(pw[i - 1], base);
        hash[0] = 0;
        for (ll i = 1; i <= n; i++) hash[i] = add(hash[i - 1], mul(_s[i] - 'a' + 1, pw[n - i])); //chu y _s khong phai s
    }

    ll mul(ll a, ll b) { return ((__int128)a * b) % mod; }
    ll add(ll a, ll b) { return (a + b) % mod; }

    ll binpow(ll x, ll n, ll mod)
    {
        ll ans = 1;
        while (n > 0)
        {
            if (n % 2 == 1) ans = mul(ans, x);
            x = mul(x, x);
            n /= 2;
        }
        return ans;
    }

    ll gethash(ll l, ll r)
    {
        ll x = (hash[r] - hash[l - 1] + mod) % mod;  
        x = mul(x, binpow(pw[n - r], mod - 2, mod));
        return x;
    }
};

bool check(vector<ll> a, vector<ll> b)
{
    for (ll i = 0; i < 26; i++) if (a[i] != b[i]) return false;
    return true;
}

void solve()
{
    string n, h; cin >> n >> h; 
    HashedString hashh(h, 9973);
    vector<ll> cntn(30), cnth(30), ans;
    for (ll i = 0; i < n.size(); i++) ++cntn[n[i] - 'a'];
    for (ll i = 0; i < h.size(); i++)
    {
        ++cnth[h[i] - 'a'];
        if (i >= n.size()) --cnth[h[i - n.size()] - 'a'];
        if (i >= n.size() - 1 && check(cntn, cnth)) ans.push_back(hashh.gethash(i - n.size() + 2, i + 1));
    }
    set<ll> st;
    for (auto i : ans) st.insert(i);
    cout << st.size() << endl;
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
    cerr << "Time: " << fixed << setprecision(10) << double(end - start) / double(CLOCKS_PER_SEC) << "\n";
    return 0;
}
