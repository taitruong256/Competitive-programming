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
const ll mod = 998244353;
bool prime[1000005];
vector<ll> v;

void solve()
{
    ll l, r; cin>>l>>r;
    ll p=1, cnt=1;
    while (l*p<=r) p*=2, ++cnt;
    p/=2; --cnt;
    if (p==0)
    {
        cout<<0<<" "<<0<<endl;
        return;
    }
    if (p==1)
    {
        cout<<1<<" "<<r-l+1<<endl;
        return;
    }
    ll ans=0;
    p/=2;
    for (auto i: v)
    {
        if (l*p*i>r) break;  
        ll x=r/(p*i);
        if (i==2) ans=(ans+x-l+1)%mod;
        else ans=(ans+(x-l+1)*(cnt-1))%mod;
    }
    cout<<cnt<<" "<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    for (ll i=2; i<=1000000; i++) prime[i]=true;
    for (ll i=2; i*i<=1000000; i++) if (prime[i]==true)
        for (ll j=i*i; j<=1000000; j+=i) prime[j]=false;

    for (ll i=2; i<=1000000; i++) if (prime[i]==true) v.push_back(i);
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}