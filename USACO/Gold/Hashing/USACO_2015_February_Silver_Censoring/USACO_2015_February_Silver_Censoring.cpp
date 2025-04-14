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
const ll mod = 1e9+7;
const ll maxn = 1e6+5;
const ll base = 31;
ll pw[maxn+5], hasht;

void solve()
{
    string s, t; cin>>s>>t;
    ll n=s.size(), m=t.size(); s=" "+s; t=" "+t;
    pw[0]=1;
    for (ll i=1; i<=maxn; i++) pw[i]=(pw[i-1]*base)%mod; 
    hasht=0;
    for (ll i=1; i<=m; i++) hasht=(hasht+(t[i]-'a'+1)*pw[i-1]%mod)%mod;
    hasht=(hasht*pw[maxn-m])%mod; 

    vector<ll> hashs; hashs.push_back(0);
    string ans=" ";
    for (ll i=1; i<=n; i++)
    {
        ll k=hashs.size();
        hashs.push_back((hashs.back()+(s[i]-'a'+1)*pw[k-1]%mod)%mod);
        ans.push_back(s[i]);
        if (k>=m)
        {
            ll x=(hashs[k]-hashs[k-m]+mod)%mod;
            x=(x*pw[maxn-k])%mod;
            if (x==hasht)
            {
                ll cnt=m;
                while (cnt--) hashs.pop_back(), ans.pop_back();
            }
        }
    }
    ll k=ans.size()-1;
    for (ll i=1; i<=k; i++) cout<<ans[i];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}