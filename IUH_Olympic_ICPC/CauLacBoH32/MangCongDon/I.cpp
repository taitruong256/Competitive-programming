/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
ll dosang[1000][1000][15], f[1000][1000][15];



void solve()
{
    ll n, q, c; cin>>n>>q>>c;
    for (ll i=0; i<=105; i++)
        for (ll j=0; j<=105; j++)
            for (ll k=0; k<=15; k++) f[i][j][k]=0, dosang[i][j][k]=0;
    for (ll i=1; i<=n; i++)
    {
        ll x, y, s; cin>>x>>y>>s;
        for (ll k=0; k<=c; k++) 
        {
            ll temp=(k+s)%(c+1);
            dosang[x][y][k]+=temp;
        }
    }

    // for (ll k=0; k<=c; k++)
    // {   
    //     cout<<"k = "<<k<<endl;
    //     for (ll i=0; i<=10; i++)
    //     {
    //         for (ll j=0; j<=10; j++) cout<<dosang[i][j][k]<<" "; 
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }

    for (ll k=0; k<=c; k++)
        for (ll i=1; i<=100; i++)
            for (ll j=1; j<=100; j++) 
                f[i][j][k]=dosang[i][j][k]+f[i-1][j][k]+f[i][j-1][k]-f[i-1][j-1][k];

    while (q--)
    {
        ll t, x1, y1, x2, y2; cin>>t>>x1>>y1>>x2>>y2;
        t=t%(c+1);
        ll ans=f[x2][y2][t]-f[x1-1][y2][t]-f[x2][y1-1][t]+f[x1-1][y1-1][t];
        cout<<ans<<endl;
    }
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