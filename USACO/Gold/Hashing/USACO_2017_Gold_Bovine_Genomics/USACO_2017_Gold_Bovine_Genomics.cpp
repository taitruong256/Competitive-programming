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

void setIO(string s)
{
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}

struct HashedString
{
    ll n;  
    const ll maxn = 505; // dat maxn theo gioi han cua de bai, neu time dat 3 dong const ra ngoai toan cuc
    const ll base = 31;
    const ll MOD = (1LL<<61)-1;
    string s;
    vector<ll> pw, hs;

    void init(string _s)
    {
        n = _s.size(); s = _s; _s = " " + _s;
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

ll n, m;
string spotty[505], plain[505];
HashedString hsh_spotty[505], hsh_plain[505];

bool check(ll len, ll col)
{
    set<ll> st;
    for (ll i=1; i<=n; i++) st.insert(hsh_spotty[i].gethash(col, col+len-1));
    for (ll i=1; i<=n; i++) if (st.find(hsh_plain[i].gethash(col, col+len-1))!=st.end()) return false;
    return true;
}

bool good(ll len)
{
    for (ll col=1; col<=m-len+1; col++) if (check(len, col)==true) return true;
    return false;
}

void solve()
{
    setIO("cownomics");
    cin>>n>>m;
    for (ll i=1; i<=n; i++) cin>>spotty[i], hsh_spotty[i].init(spotty[i]);
    for (ll i=1; i<=n; i++) cin>>plain[i], hsh_plain[i].init(plain[i]);

    ll l=1, r=m, ans=m;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (good(mid)==true) ans=mid, r=mid-1;
        else l=mid+1;
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}