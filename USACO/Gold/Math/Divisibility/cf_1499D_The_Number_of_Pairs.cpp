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
const ll mod = 1e9+7;
const ll maxn = 2e7+10;
ll minprime[maxn+5], cnt[maxn+5];
vector<ll> pw;

void solve()
{
    ll c, d, x; cin>>c>>d>>x;     
    ll ans=0;
    for (ll g=1; g*g<=x; g++) if (x%g==0)
    {
        ll t=x/g+d;     
        if (t%c==0) ans+=pw[cnt[t/c]];
        if (g*g==x) continue;
        t=g+d;       
        if (t%c==0) ans+=pw[cnt[t/c]];
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    minprime[1]=1;
    for (ll i=2; i*i<=maxn; i++) if (minprime[i]==0)
        for (ll j=i*i; j<=maxn; j+=i) if (minprime[j]==0) minprime[j]=i;
    for (ll i=1; i<=maxn; i++) if (minprime[i]==0) minprime[i]=i;

    pw.push_back(1);
    while (pw.size()<=30) pw.push_back(pw.back()*2);
    
    for (ll i=2; i<=maxn; i++)
    {
        ll x=i/minprime[i];
        cnt[i]=cnt[x]+(minprime[i]!=minprime[x]);
    }

    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}