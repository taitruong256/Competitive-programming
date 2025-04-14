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
ll minprime[200005];

void solve()
{
    ll n, x, m; cin>>n>>x;
    m=n;
    if (n%x!=0)
    {
        cout<<-1<<endl;
        return;
    }
    n/=x;
    vector<ll> thuaso;
    thuaso.push_back(1);
    thuaso.push_back(x);
    while (n>1)
    {
        thuaso.push_back(minprime[n]);
        n/=minprime[n];
    }
    if (n>1) thuaso.push_back(n);
    ll ans[m+5];
    for (ll i=1; i<=m; i++) ans[i]=0;
    ll pos=1;
    for (ll i=0; i<thuaso.size()-1; i++)
    {
        ans[pos]=pos*thuaso[i+1];
        pos*=thuaso[i+1];
    }
    ans[m]=1;
    for (ll i=1; i<=m; i++) if (ans[i]==0)  ans[i]=i;
    for (ll i=1; i<=m; i++) cout<<ans[i]<<" "; cout<<endl;
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
    for (ll i=2; i<=200005; i++) minprime[i]=0;
    for (ll i=2; i*i<=200005; i++)
        for (ll j=i*i; j<=200005; j+=i) if (minprime[j]==0) minprime[j]=i;
    for (ll i=2; i<=200005; i++) if (minprime[i]==0) minprime[i]=i;
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}