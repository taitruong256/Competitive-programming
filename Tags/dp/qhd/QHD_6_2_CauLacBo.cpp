/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
ll v[10005][10005], f[10005][10005];
ll a[10005], b[10005];

void truyvet(ll i, ll j)
{
    if (f[i][j]==0) return;
    if (f[i][j]==f[i-1][j-1]+v[i][j])
    {
        truyvet(i-1, j-1);
        cout<<i<<" "<<j<<endl;
    }
    else truyvet(i, j-1);
}

void solve()
{
    cin>>n>>k;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=k; i++) cin>>b[i];

    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=k; j++) v[i][j]=abs(a[i]-b[j]);

    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=k; j++) f[i][j]=1e9;
    
    for (ll i=0; i<=n; i++)
    {
        for (ll j=0; j<=k; j++)   
            if (i==0 || j==0) f[i][j]=0;
            else if (i==j) f[i][j]=f[i-1][j-1]+v[i][j];
            else if (i<j) f[i][j]=min(f[i-1][j-1]+v[i][j], f[i][j-1]);
    }

    // for (ll i=1; i<=n; i++)
    // {
    //     for (ll j=1; j<=k; j++) if (f[i][j]==1e9) cout<<"oo "; else cout<<f[i][j]<<" "; 
    //     cout<<endl;
    // }

    if (f[n][k]==1e9) cout<<-1;
    else
    {
        cout<<f[n][k]<<endl;
        truyvet(n, k);
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
