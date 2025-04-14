/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n+5], b[n+5], ans[n+5];
    for (ll i=0; i<n; i++) cin>>a[i];
    ll left=0, right=n-1, value=-1;
    for (ll i=0; i<n; i++) if (a[i]!=i+1)
    {
        value=i+1;
        left=i;
        break;
    }
    for (ll i=0; i<n; i++) if (a[i]==value) 
    {
        right=i;
        break;
    }
    if (value!=-1) reverse(a+left, a+right+1);
    for (ll i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}