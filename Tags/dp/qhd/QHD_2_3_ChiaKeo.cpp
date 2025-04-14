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
ll n, s=0; 
ll a[40005], f[40005], truoc[40005], dau[40005];

void truyvet(ll i)
{
    if (i==0) return;
    truyvet(i-a[truoc[i]]);
    dau[truoc[i]]=1;
    cout<<a[truoc[i]]<<" ";
}

void solve()
{
    cin>>n;
    
    for (ll i=0; i<n; i++) cin>>a[i];
    ll s=0;
    for (ll i=0; i<n; i++) s+=a[i];  

    for (ll i=0; i<40005; i++) f[i]=0;
    for (ll i=0; i<40005; i++) truoc[i]=0;
    for (ll i=0; i<40005; i++) dau[i]=0;
    f[0]=1;
    for (ll i=0; i<n; i++)
        for (ll j=s; j>=a[i]; j--) if (f[j]==0 && f[j-a[i]]==1) 
        {
            f[j]=1;
            truoc[j]=i;
        }

    ll m=s/2;
    while (f[m]==0) --m;
    cout<<s-2*m<<endl;
    truyvet(m); cout<<endl;
    for (ll i=0; i<n; i++) if (dau[i]==0) cout<<a[i]<<" ";
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