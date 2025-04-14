/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll a[100][100];
ll ans[4][4]={{1,0,0,1},{0,1,1,0},{0,1,1,0},{1,0,0,1}};

bool check(ll x, ll y, ll val)
{
    ll cnt=0;
    if (val==0)
    {
        if (a[x-1][y]==1) ++cnt;
        if (a[x+1][y]==1) ++cnt;
        if (a[x][y-1]==1) ++cnt;
        if (a[x][y+1]==1) ++cnt;
    }
    else
    {
        if (a[x-1][y]==0) ++cnt;
        if (a[x+1][y]==0) ++cnt;
        if (a[x][y-1]==0) ++cnt;
        if (a[x][y+1]==0) ++cnt;
    }
    return cnt==2;
}

void solve()
{
    ll n, m; cin>>n>>m;
    for (ll i=0; i<n; i++)
        for (ll j=0; j<m; j++) cout<<ans[i%4][j%4]<<" \n"[j+1==m];









    // for (ll i=0; i<=n+1; i++)
    //     for (ll j=0; j<=m+1; j++) a[i][j]=-1;

    // for (ll i=0; i<(1<<n*m); i++)
    // {
    //     for (ll j=0; j<n*m; j++) if (i&(1<<j)) a[j/m+1][j%m+1]=1; else a[j/m+1][j%m+1]=0;

    //     bool kt=true;
    //     for (ll k=1; k<=n; k++)
    //         for (ll l=1; l<=m; l++) kt&=check(k, l, a[k][l]);
    //     if (kt==true)
    //     {
    //         for (ll k=1; k<=n; k++)
    //             {
    //                 for (ll l=1; l<=m; l++) cout<<a[k][l]<<" "; cout<<endl;
    //             }   cout<<endl;
    //     }
    // }

    
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