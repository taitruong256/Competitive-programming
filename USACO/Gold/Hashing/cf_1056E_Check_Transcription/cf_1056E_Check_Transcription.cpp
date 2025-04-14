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
    ll n; 
    ll maxn = 1e6+5; // dat maxn theo gioi han cua de bai, neu time dat 3 dong const ra ngoai toan cuc
    ll base = 31;
    ll MOD = (1LL<<61)-1;
    vector<ll> pw, hs;
    string s;

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
    string s, t; cin>>s>>t;
    HashedString hasht(t);
    ll c0=0, c1=0, n=s.size(), m=t.size(), ans=0;
    for (auto i: s) if (i=='0') ++c0; else ++c1;
    t=" "+t; s=" "+s;
    for (ll r0=1; r0<=m; r0++)
    {
        if (m-c0*r0<=0 || (m-c0*r0)%c1!=0 || (m-c0*r0)/c1==0) continue;
        ll r1=(m-c0*r0)/c1;
        ll len[2]={r0, r1}, hsh[2]={0, 0}, idx=1;
        bool check=1;
        for (ll i=1; i<=n; i++)
        {
            ll si=s[i]-'0';
            if (i<n && idx+len[si]-1>m)
            {
                check=false;
                break;
            }
            if (hsh[si]==0) hsh[si]=hasht.gethash(idx, idx+len[si]-1);
            if (hasht.gethash(idx, idx+len[si]-1)!=hsh[si] || hsh[0]==hsh[1]) check=0; 
            idx+=len[si];
        }
        ans+=check;
    }
    cout<<ans;
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