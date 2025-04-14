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
    ll a[55];
    bool dau[55];
    memset(dau, false, sizeof(dau));
    
    for (ll i=1; i<=n; i++)
    {
      ll x; cin>>x;
      while (x>n) x/=2;
      while (x>0)
      {
        if (dau[x]==false) 
        {
          dau[x]=true;
          break;
        }
        x/=2;
      }
    }

    bool ok=true;
    for (ll i=1; i<=n; i++) if (dau[i]==false)
    {
      ok=false;
      break;
    }
    if (ok) cout<<"YES\n";
    else cout<<"NO\n";
}
 
int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    while (t--) solve();
    return 0;
}
