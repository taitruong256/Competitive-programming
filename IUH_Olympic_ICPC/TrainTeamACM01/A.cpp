/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    for (ll i=0; i<n; i++) cin>>a[i];
    a[n]=a[0];
    ll mn=1e18, index=-1;
    for (ll i=0; i<n; i++) if (a[i]-a[i+1]<mn)
    {
        mn=a[i]-a[i+1];
        index=i;
    }//
    //cout<<index<<endl;
    ll sum=0;
    for (ll i=0; i<n; i++) sum+=a[i];
    cout<<sum+mn<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}