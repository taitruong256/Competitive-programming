/*=====================================================================================
    Nothing is impossible, only you think it is impossible                 
            Try, try, try again until you succeed     
              Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, m; cin>>n>>m;
    if (n%m==0)
    {
        cout<<m*(n/m)*(n/m-1)/2<<" "<<(n-m+1)*(n-m)/2;
        return;
    }
    ll x=n/m, y=n%m;      
    ll mx=(n-m+1)*(n-m)/2;
    ll mi=y*(x+1)*x/2+(m-y)*x*(x-1)/2;
    cout<<mi<<" "<<mx;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  //cin>>t;
    while (t--) solve();
    return 0;
}