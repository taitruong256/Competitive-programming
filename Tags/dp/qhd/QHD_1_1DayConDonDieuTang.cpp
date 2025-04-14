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
ll n; 
ll a[100005], f[100005], truoc[100005];

void truyvet(ll x)
{
    if (x==0) return;
    truyvet(truoc[x]);
    cout<<a[x]<<" ";
}

void solve()
{
    cin>>n;

    for (ll i=1; i<=n; i++) cin>>a[i];       
    for (ll i=1; i<=n; i++) truoc[i]=0;
    for (ll i=1; i<=n; i++) f[i]=1;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<i; j++) if (a[j]<=a[i] && f[i]<f[j]+1) 
        {
            f[i]=f[j]+1;
            truoc[i]=j;
        }
    
    ll mx=0, vt=0;
    for (ll i=1; i<=n; i++) if (f[i]>mx) mx=f[i], vt=i;
    cout<<mx<<endl;
    truyvet(vt);
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