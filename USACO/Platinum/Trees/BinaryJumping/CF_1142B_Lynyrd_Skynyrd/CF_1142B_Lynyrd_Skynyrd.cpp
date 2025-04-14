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
ll n, m, pre, q, p[200005], pos[200005], a[200005], lst[200005], f[200005], par[200005][25];

ll jump(ll x, ll n)
{
    for (ll j=20; j>=0; j--) if (n&(1LL<<j)) x=par[x][j];
    return x;
}

void solve()
{
    cin>>n>>m>>q;
    for (ll i=1; i<=n; i++) cin>>p[i], pos[p[i]]=i;
    p[0]=p[n];
    pos[0]=n;
    for (ll i=1; i<=m; i++)
    {
        cin>>a[i];
        lst[a[i]]=i;
        pre=pos[a[i]]-1;    
        if (pre==0) pre=n;
        par[i][0]=lst[p[pre]];       
        for (ll j=1; j<=20; j++) par[i][j]=par[par[i][j-1]][j-1];
        f[i]=max(jump(i, n-1), f[i-1]);
    }
    while (q--)
    {
        ll l, r; cin>>l>>r;
        if (l<=f[r]) cout<<1; 
        else cout<<0;
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