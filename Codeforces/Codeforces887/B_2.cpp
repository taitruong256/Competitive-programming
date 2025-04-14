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
                                          Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
ll f[30], maxn, N, K, chk;

bool check(ll x, ll y)
{
    f[1]=x;
    f[2]=y;
    for (ll i=3; i<=K; i++)
    {
        f[i]=f[i-1]+f[i-2];
        if (i==K && f[K]==N) chk=1;
        if (f[i]>=N) return true;
    }
    return false;
}

void solve()
{
    cin>>N>>K;
    if (K>30)
    {
        cout<<0<<endl;
        return;
    }
    ll cnt=0;
    for (ll i=0; i<=N; i++)
    {
        ll l=i, r=N, ans=-1;
        chk=0;
        while (l<=r)
        {
            ll mid=(l+r)/2;
            if (check(i, mid)==true) ans=mid, r=mid-1;
            else l=mid+1;
        }
        cnt+=chk;
    }
    cout<<cnt<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    f[1]=1;
    f[2]=1;
    maxn=2;
    for (ll i=3; ; i++)
    {
        f[i]=f[i-2]+f[i-1];
        if (f[i]>2e5) break;
        ++maxn;
    }
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}