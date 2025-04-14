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
const ll maxn = 1e6+5; // dat maxn theo gioi han cua de bai, neu time dat 3 dong const ra ngoai toan cuc
const ll base = 331;
const ll MOD = (1LL<<61)-1;
 
struct HashedString
{
    ll n;  
    string s;
    vector<ll> pw, hs;
 
    HashedString() {}
    HashedString(string _s)
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
 
void solve()
{
    string s; cin>>s;
    ll n=s.size(); 
    HashedString hashs(s);  
    for (ll i=1; i<=n; i++)
    {
        ll check=1;
        for (ll j=1; j<=n; j+=i)
        {  
            ll rem=min(n-j+1, j);
            if (hashs.gethash(j, j+rem-1)!=hashs.gethash(1, rem)) 
            {
                check=0;
                break;
            }
        }
        if (check==1) cout<<i<<endl;
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
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}