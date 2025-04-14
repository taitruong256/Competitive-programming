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
const ll mod = 1e9+7;
ll cnt[10000005], f[10000005], pref[10000005], n;
bool prime[10000005];

void solve()
{
    cin>>n;
    for (ll i=0; i<n; i++)
    {
        ll x; cin>>x;
        ++cnt[x];
    }
    for (ll i=2; i<=10000000; i++) prime[i]=true;
    for (ll i=2; i*i<=10000000; i++) if (prime[i]==true)
        for (ll j=i*i; j<=10000000; j+=i) prime[j]=false;
    for (ll i=2; i<=10000000; i++) if (prime[i]==true)
        for (ll j=i; j<=10000000; j+=i) f[i]+=cnt[j];
    pref[0]=0;
    for (ll i=1; i<=10000000; i++) pref[i]=pref[i-1]+f[i];
    ll q; cin>>q;
    while (q--)
    {
        ll l, r; cin>>l>>r;
        l=min(l, 10000000*1LL);
        r=min(r, 10000000*1LL);
        cout<<pref[r]-pref[l-1]<<endl;
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