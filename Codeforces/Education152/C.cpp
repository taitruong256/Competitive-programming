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
                                       Where is the bug, delete it there
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
    ll base = 331;
    const ll MOD = (1LL<<61)-1;
    string s;
    vector<ll> pw, hs;
 
    ll mul(ll a, ll b) { return ((__int128)a * b) % MOD; }
    ll add(ll a, ll b) { return (a + b) % MOD; }
    ll sub(ll a, ll b) { return (a - b + MOD) % MOD; }
 
    HashedString() {}
    HashedString(string _s)
    {
        n = _s.size(); s = _s; _s = " " + _s;
        pw.resize(n+5, 1);
        hs.resize(n+5, 0);
        base=uniform_int_distribution<ll>(0, MOD - 1)(rng);
        for (ll i = 1; i <= n; i++) pw[i] = mul(pw[i - 1], base);
        for (ll i = 1; i <= n; i++) hs[i] = add(hs[i - 1], mul(_s[i] - '0' + 1, pw[i - 1])); //chu y _s khong phai s
    }
 
    ll gethash(ll l, ll r)
    {
        ll x = (hs[r] - hs[l - 1] + MOD) % MOD;  
        // x = mul(x, pw[maxn - r]);
        return x;
    }
};
 
struct fenwick
{
    ll n; 
    vector<ll> bit;
 
    fenwick(){}
    fenwick(ll _n)
    {
        n=_n;
        bit.resize(n+5);
    }
 
    void update(ll idx, ll val)
    {
        for (ll i=idx; i<=n; i+=-i&i) bit[i]+=val;
    }
 
    ll query(ll idx)
    {
        ll sum=0;
        for (ll i=idx; i>0; i-=-i&i) sum+=bit[i];
        return sum;
    }
 
    ll query(ll l, ll r)
    {
        if (l>r) return 0;
        return query(r)-query(l-1);
    }
};
 
void solve()
{
    ll n, m; cin>>n>>m;
    string s; cin>>s;
    fenwick ft(n);
    HashedString hs(s); // cout<<hs.base<<endl;
    s=" "+s;
    set<ll> st;
    for (ll i=1; i<=n; i++) if (s[i]=='0') ft.update(i, 1);
 
 
    ll pref1[n+5], pref2[n+5];
    pref1[0]=pref2[0]=0;
    for (ll i=1; i<=n; i++)
    {
        pref1[i]=hs.add(pref1[i-1], hs.mul(1, hs.pw[i-1]));
        pref2[i]=hs.add(pref2[i-1], hs.mul(2, hs.pw[i-1]));
    }
    
    for (ll i=1; i<=m; i++)
    {
        ll l, r; cin>>l>>r;
        ll cnt=ft.query(l, r); 
        ll hsh=hs.sub(hs.gethash(1, n), hs.gethash(l, r)); 
        ll hsh0=hs.sub(pref1[l+cnt-1], pref1[l-1]);    
        ll hsh1=hs.sub(pref2[r], pref2[l+cnt-1]);   
        hsh=hs.add(hs.add(hsh, hsh0), hsh1);
        st.insert(hsh);
    }
    cout<<st.size()<<endl;       
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
