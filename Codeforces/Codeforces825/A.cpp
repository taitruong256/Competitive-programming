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
                             Nothing is impossible, only you think it is impossible                 
                                     Try, try, try again until you succeed     
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;

void solve()
{
    ll n; cin>>n;
    ll a[n+5], b[n+5], one1=0, one2=0;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) cin>>b[i];
    ll ans=0;
    for (ll i=1; i<=n; i++) if (a[i]==1) ++one1;
    for (ll i=1; i<=n; i++) if (b[i]==1) ++one2;
    if (one1==one2)
    {
        bool check=false;
        for (ll i=1; i<=n; i++) if (a[i]!=b[i]) check=true;
        // for (ll i=1; i<=n; i++) cout<<a[i]<<" "; cout<<endl;
        // for (ll i=1; i<=n; i++) cout<<b[i]<<" "; cout<<endl;
        ans+=check;
        cout<<ans<<endl;
        return;
    }
    else if (one1<one2)
    {
        for (ll i=1; i<=n; i++) if (a[i]==0 && b[i]==1 && one1<one2) a[i]=1, ++one1, ++ans;
        bool check=false;
        for (ll i=1; i<=n; i++) if (a[i]!=b[i]) check=true;
        // for (ll i=1; i<=n; i++) cout<<a[i]<<" "; cout<<endl;
        // for (ll i=1; i<=n; i++) cout<<b[i]<<" "; cout<<endl;
        ans+=check;
        cout<<ans<<endl;
        return;
    }
    else 
    {
        for (ll i=1; i<=n; i++) if (a[i]==1 && b[i]==0 && one1>one2) a[i]=0, --one1, ++ans;
        bool check=false;
        for (ll i=1; i<=n; i++) if (a[i]!=b[i]) check=true;
        // for (ll i=1; i<=n; i++) cout<<a[i]<<" "; cout<<endl;
        // for (ll i=1; i<=n; i++) cout<<b[i]<<" "; cout<<endl;
        ans+=check;
        cout<<ans<<endl;
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}