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
ll sparse[200005][20], n, a[200005], b[200005], lg[200005];

bool check(ll x)
{
    ll k=lg[x];
    for (ll i=1; i<=n-x+1; i++) if (__gcd(sparse[i][k], sparse[i+x-1-(1LL<<k)+1][k])>1) 
        return true;
    return false;
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n-1; i++) b[i]=abs(a[i]-a[i+1]);

    --n;
    for (ll i=1; i<=n; i++) sparse[i][0]=b[i];
    for (ll k=1; k<=20; k++)
        for (ll i=1; i<=n-(1LL<<k)+1; i++)
            sparse[i][k]=__gcd(sparse[i][k-1], sparse[i+(1LL<<(k-1))][k-1]);

    ll l=1, r=n, ans=0;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (check(mid)==true) ans=mid, l=mid+1;
        else r=mid-1;
    }
    cout<<ans+1<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    lg[1]=0;
    for (ll i=2; i<=200000; i++) lg[i]=lg[i/2]+1;
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}