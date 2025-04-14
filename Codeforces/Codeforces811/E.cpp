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
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define ll long long
//tree<ll, null_type, less<ll>, rb_tree_tag,
//tree_order_statistics_node_update> T;             //find_by_order            order_of_key
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    ll cnt=0;
    for (ll i=1; i<=n; i++) if (a[i]%5==0) ++cnt;
    if (cnt==n)
    {
        for (ll i=1; i<=n; i++) if (a[i]%5==0) a[i]=a[i]+a[i]%10;
        bool check=true;
        ll mx=*max_element(a+1, a+n+1);
        for (ll i=1; i<=n; i++) if (a[i]!=mx) check=false;
        if (check==true) cout<<"Yes\n";
        else cout<<"No\n";
        return;
    }
    else if (cnt>0)
    {
        cout<<"No\n";
        return;
    }

    ll m=*max_element(a+1, a+n+1);
    for (ll i=1; i<=n; i++) a[i]+=(m-a[i])/20*20;
    ll sl=4;
    while (sl--)
    {
        ll mx=*max_element(a+1, a+n+1);
        for (ll i=1; i<=n; i++)
        {
            while (a[i]<mx) a[i]=a[i]+a[i]%10;
        }
        bool check=true;
        for (ll i=1; i<=n; i++) if (a[i]!=mx) check=false;
        if (check==true)
        {
            cout<<"Yes\n";
            return;
        }
        for (ll i=1; i<=n; i++) if (a[i]==mx) a[i]=a[i]+a[i]%10;
        // for (ll i=1; i<=n; i++) cout<<a[i]<<" "; cout<<endl;
    }
    cout<<"No\n";
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