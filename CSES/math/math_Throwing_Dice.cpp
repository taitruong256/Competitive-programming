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
struct matrix{ll a[10][10];} x;

matrix operator * (matrix a, matrix b)
{
    matrix c;
    for (ll i=1; i<=6; i++)
        for (ll j=1; j<=6; j++) c.a[i][j]=0;
    for (ll i=1; i<=6; i++)
        for (ll j=1; j<=6; j++)
            for (ll k=1; k<=6; k++)
            {
                c.a[i][j]+=a.a[i][k]*b.a[k][j];
                c.a[i][j]%=mod;  
            }
    return c;
}

matrix binpow(matrix a, ll n)
{
    matrix ans;
    for (ll i=1; i<=6; i++)
      for (ll j=1; j<=6; j++) if (i==j) ans.a[i][j]=1; else ans.a[i][j]=0;
    while (n>0)
    {
        if (n&1) ans=ans*a;
        a=a*a;
        n/=2;
    }
    return ans;
}


void solve()
{
    ll n; cin>>n;
    for (ll i=1; i<=6; i++)
      for (ll j=1; j <=6; j++) x.a[i][j]=0;
    for (ll i=1; i<=6; i++) x.a[1][i]=1;
    for (ll i=1; i<=5; i++) x.a[i+1][i]=1;
    matrix y=binpow(x, n);
    cout<<y.a[1][1];
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