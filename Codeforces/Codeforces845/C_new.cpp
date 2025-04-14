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
ll cnt[100005];

void solve()
{
    ll n, m; cin>>n>>m;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);
    ll l=1, x=0, ans=1e9;
    cnt[0]=1;
    for (ll r=1; r<=n; r++)
    {  
        for (ll i=1; i*i<=a[r]; i++) if (a[r]%i==0)
        {
            if (i<=m) ++cnt[i];
            if (a[r]/i<=m && i*i!=a[r]) ++cnt[a[r]/i];
        }
        while (x<=m && cnt[x]>0) ++x;           
        while (x==m+1)
        {             
            ans=min(ans, a[r]-a[l]);
            for (ll i=1; i*i<=a[l]; i++) if (a[l]%i==0)
            {
                if (i<=m) cnt[i]-=1;
                if (i<=m && cnt[i]==0) x=min(x, i);
                if (a[l]/i<=m && i*i!=a[l]) cnt[a[l]/i]-=1;
                if (a[l]/i<=m && cnt[a[l]/i]==0) x=min(x, a[l]/i);
            }
            ++l;
        }
    }
    if (ans==1e9) ans=-1;
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
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}