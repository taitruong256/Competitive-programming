/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed                     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
ll n, w; 
ll a[10005];
ll f[10005][10005];
map<ll, ll> cnt;

void truyvet(ll i, ll j)
{
    if (f[i][j]==0 || i==0 || j==0) return;
    if (f[i][j]==f[i-1][j]) truyvet(i-1, j);
    else
    {
        truyvet(i, j-a[i]);
        ++cnt[i];
    }
}

void solve()
{
    cin>>n>>w;
    for (ll i=1; i<=n; i++) cin>>a[i];


    for (ll i=0; i<=n; i++) f[i][0]=0;
    for (ll i=1; i<=w; i++) f[0][i]=1e9;

    for (ll i=1; i<=n; i++)
    {
        for (ll j=1; j<=w; j++) 
            if (j>=a[i]) f[i][j]=min(f[i-1][j], f[i][j-a[i]]+1);
            else f[i][j]=f[i-1][j];
    }

    // for (ll i=1; i<=n; i++)
    // {
    //     for (ll j=1; j<=w; j++) cout<<f[i][j]<<" "; cout<<endl;
    // }
    if (f[n][w]==1e9) cout<<-1; else cout<<f[n][w]<<endl;
    //truyvet(n, w);
    //for (auto it: cnt) cout<<a[it.first]<<" "<<it.second<<endl;
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