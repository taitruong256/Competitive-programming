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

void solve()
{
    ll n, s; cin>>n;
    ll a[n+5];
    for (ll i=0; i<n; i++) cin>>a[i];
    s=0;
    for (ll i=0; i<n; i++) s+=a[i];       

    ll f[40005];
    for (ll i=0; i<40005; i++) f[i]=0;
    f[0]=1;           
    for (ll i=0; i<n; i++)
        for (ll j=s; j>=a[i]; j--) if (f[j]==0 && f[j-a[i]]==1) f[j]=1;

    ll cnt=0;
    for (ll i=0; i<=s; i++) if (f[i]==1) ++cnt, cout<<i<<" ";  cout<<endl; 
    cout<<cnt;
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