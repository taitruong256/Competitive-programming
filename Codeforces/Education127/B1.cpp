/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];

    if (n==1)
    {
        cout<<"YES\n";
        return;
    }
    if (a[2]-a[1]>3)
    {
        cout<<"NO\n";
        return;
    }
    if (a[n]-a[n-1]>3)
    {
        cout<<"NO\n";
        return;
    }
    ll b[n+5];
    for (ll i=1; i<=n; i++) b[i]=a[i];
    ll check=0;
    ll k=1;
    for (k=2; k<=n; k++)
    {
        if (b[k]-b[k-1]==1);
        else if (b[k]-b[k-1]==2) b[k]--;
        else break;
    }                    // cout<<k<<endl;
    if (k==n+1) check=1;
    // for (ll i=1; i<=n; i++) cout<<b[i]<<" "; cout<<endl;

    
    for (ll i=1; i<=n; i++) b[i]=a[i];
    ++b[1];
    k=1;
    for (k=2; k<=n; k++)
    {
        if (b[k]-b[k-1]==0) ++b[k];
        else if (b[k]-b[k-1]==1);
        else if (b[k]-b[k-1]==2) b[k]--;
        else break;
    }          //        cout<<k<<endl;
    if (k==n+1) check=1;
    // for (ll i=1; i<=n; i++) cout<<b[i]<<" "; cout<<endl;


    if (check==1) cout<<"YES\n";
    else cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}