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
ll n, thoigian, a[3][200005], cach1[3][200005], cach2[3][200005], cach3[3][200005], cach4[3][200005];
 
void solve()
{
    cin>>n;
    for (ll i=1; i<=2; i++)
        for (ll j=1; j<=n; j++) cin>>a[i][j];
    cach1[1][1]=cach2[1][1]=cach3[1][1]=0;
 
    thoigian=0;
    for (ll i=2; i<=n; i++) thoigian=max(thoigian+1, a[1][i]+1), cach1[1][i]=thoigian;
    thoigian=max(thoigian+1, a[2][n]+1);
    cach1[2][n]=thoigian;
    for (ll i=n-1; i>=1; i--) thoigian=max(thoigian+1, a[2][i]+1), cach1[2][i]=thoigian;
    // for (ll i=1; i<=2; i++) for (ll j=1; j<=n; j++) cout<<cach1[i][j]<<" \n"[j==n]; cout<<endl;
 
    thoigian=0;
    thoigian=max(thoigian+1, a[2][1]+1);
    cach2[2][1]=thoigian;
    for (ll i=2; i<=n; i++) thoigian=max(thoigian+1, a[2][i]+1), cach2[2][i]=thoigian;
    thoigian=max(thoigian+1, a[1][n]+1);
    cach2[1][n]=thoigian;
    for (ll i=n-1; i>=1; i--) thoigian=max(thoigian+1, a[1][i]+1), cach2[1][i]=thoigian;
    // for (ll i=1; i<=2; i++) for (ll j=1; j<=n; j++) cout<<cach2[i][j]<<" \n"[j==n]; cout<<endl;
    
    thoigian=0;
    thoigian=max(thoigian+1, a[2][1]+1);  
    cach3[2][1]=thoigian;
    for (ll i=2; i<=n; i++)
    {
        if (i%2==0)
        {
            thoigian=max(thoigian+1, a[2][i]+1);
            cach3[2][i]=thoigian;
            thoigian=max(thoigian+1, a[1][i]+1);
            cach3[1][i]=thoigian;
        }
        else 
        {
            thoigian=max(thoigian+1, a[1][i]+1);
            cach3[1][i]=thoigian;
            thoigian=max(thoigian+1, a[2][i]+1);
            cach3[2][i]=thoigian;
        }
    }
    // for (ll i=1; i<=2; i++) for (ll j=1; j<=n; j++) cout<<cach3[i][j]<<" \n"[j==n]; cout<<endl;
 
    ll ans=min(cach1[2][1], cach2[1][2]);   
    if (n%2==0) ans=min(ans, cach3[1][n]);
    else ans=min(ans, cach3[2][n]);       // cout<<ans<<endl; 
    for (ll i=1; i<=n-1; i++)
    {
        if (i%2==1) ans=min(ans, cach3[2][i]+cach2[1][i+1]-cach2[2][i]);
        else ans=min(ans, cach3[1][i]+cach1[2][i+1]-cach1[1][i]);   //    cout<<ans<<endl;
    }
    cout<<ans<<endl;
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
