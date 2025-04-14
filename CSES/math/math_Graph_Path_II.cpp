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
const ll inf = 2e18;
struct matrix{ll a[105][105];} x;
ll n, m, k;

matrix operator * (matrix a, matrix b)
{
    matrix c;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) c.a[i][j]=inf;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++)
            for (ll k=1; k<=n; k++)
            {
                c.a[i][j]=min(c.a[i][j], a.a[i][k]+b.a[k][j]);
            }
    return c;
}

matrix binpow(matrix a, ll k)
{
    matrix ans;
    for (ll i=1; i<=n; i++)
      for (ll j=1; j<=n; j++) if (i==j) ans.a[i][j]=0; else ans.a[i][j]=inf;
    while (k>0)
    {
        if (k&1) ans=ans*a;
        a=a*a;
        k/=2;
    }
    return ans;
}


void solve()
{
    cin>>n>>m>>k;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) x.a[i][j]=inf;
    for (ll i=0; i<m; i++)
    {
        ll u, v, c; cin>>u>>v>>c;
        x.a[u][v]=min(x.a[u][v], c);
    }
    
    matrix y=binpow(x, k); 
    // for (ll i=1; i<=n; i++)
        // for (ll j=1; j<=n; j++) cout<<y.a[i][j]<<" \n"[j==n];
    if (y.a[1][n]<inf) cout<<y.a[1][n];
    else cout<<(-1);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}