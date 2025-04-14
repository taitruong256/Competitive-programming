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
    ll n; cin>>n;
    for (ll i=2; i*i<=n; i++) if (n%i==0)
        for (ll j=i+1; j*j<=n; j++) if (n%(i*j)==0 && n/(i*j)>2 && n/(i*j)!=i && n/(i*j)!=j)
        {
            cout<<"YES\n";
            cout<<i<<" "<<j<<" "<<n/(i*j)<<endl;
            return;
        }
    cout<<"NO\n";
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  cin>>t;
    while (t--) solve();
    return 0;
}