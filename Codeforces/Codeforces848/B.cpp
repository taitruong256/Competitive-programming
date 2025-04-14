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

void solve()
{
    ll n, m, d; cin>>n>>m>>d;  
    ll a[n+5], pos[n+5], b[m+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) pos[a[i]]=i;
    for (ll i=1; i<=m; i++) cin>>b[i];

    ll ans=1e9;
    for (ll i=1; i<=m-1; i++)
    {  
        if (pos[b[i]]>=pos[b[i+1]]) ans=0;
        if (pos[b[i+1]]>pos[b[i]]+d) ans=0;
        ll d1=pos[b[i+1]]-pos[b[i]]; 
        ll l=pos[b[i+1]]-d-1;
        if (l<1) l=1;
        ll d2=pos[b[i]]-l;  
        if (d2<d)
        {
            ll r=l+d+1;
            d2+=r-pos[b[i+1]]; 
            if (r>n) d2=1e9;
            if (r-l<d) d2=1e9;
        }         
        ans=min({ans, d1, d2});
    }
    if (ans<0) ans=0;
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