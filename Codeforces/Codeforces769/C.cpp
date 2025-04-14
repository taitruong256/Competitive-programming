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
    ll a, b; cin>>a>>b;
    ll ans=b-a;              //after operation a|b, then a>=b
    for (ll i=a; i<=b; i++)  //tang a len xong a=a|b, +1 la thao tac or
    {
        ll c=(i|b);
        ans=min(ans, i-a+c-b+1);
    }
    for (ll i=b+1; i<=b+a; i++)   //tang b len xong a=a|b, +1 la thao tac or
    {
        ll c=(a|i);
        ans=min(ans, i-b+c-i+1);
    }
    cout<<ans<<endl;
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