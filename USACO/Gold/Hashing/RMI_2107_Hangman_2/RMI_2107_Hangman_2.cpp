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
const ll base = 331;
const ll MOD = (1LL<<61)-1;

struct HashedString
{
    ll n, maxn;    
    string s;
    vector<ll> pw, hs;

    void init(string _s, ll _maxn)
    {
        n = _s.size(); s = _s; _s = " " + _s;
        maxn=_maxn;
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
        // x = mul(x, pw[maxn - r]);
        return x;
    }
};
HashedString hsh[30005];

void solve()
{
    ll n, m; cin>>n>>m;
    string s[n+5];
    
    for (ll i=1; i<=n; i++) cin>>s[i];
    vector<ll> ans(n+5, 0);

    if (n<=1000)
    {
        //O(n^2.k)
        for (ll i=1; i<=n-1; i++)
            for (ll j=i+1; j<=n; j++) 
            {
                ll cnt=0;
                for (ll k=1; k<=m; k++) if (s[i][k-1]!=s[j][k-1]) ++cnt;
                if (cnt<=2) ans[i]=ans[j]=1;
            }
        for (ll i=1; i<=n; i++) cout<<ans[i];
        cout<<endl;
    }
    else 
    {
        //O(n.logn.k^2)
        for (ll i=1; i<=n; i++) hsh[i].init(s[i], m+5);
        for (ll i=1; i<=m-1; i++)
            for (ll j=i+1; j<=m; j++)  
            {
                vector<pair<ll, ll>> v;
                for (ll k=1; k<=n; k++)
                {
                    ll hs=(hsh[k].gethash(1, m)-hsh[k].gethash(i, i)-hsh[k].gethash(j, j)+MOD*2)%MOD;
                    v.push_back({hs, k});
                }
                sort(v.begin(), v.end());
                for (ll k=0; k<n; k++)
                {
                    if (k>0 && v[k].first==v[k-1].first) ans[v[k].second]=1;
                    if (k<n-1 && v[k].first==v[k+1].first) ans[v[k].second]=1;
                }
            }
        for (ll i=1; i<=n; i++) cout<<ans[i];
        cout<<endl;
    }
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