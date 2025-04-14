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
    ll n,m; cin>>n>>m;
    ll a[105];
    bool p[105];
    for (ll i=1; i<=n; i++) cin>>a[i];
    memset(p, false, sizeof(p));
    for (ll i=1; i<=m; i++)
    {
        ll x; cin>>x;
        p[x]=true;
    }
 
    while (true)
    {
        bool ok=false;
        for (ll i=1; i<=n; i++) if (p[i]==true && a[i]>a[i+1]) 
        {
            swap(a[i], a[i+1]);
            ok=true;
        }
        if (ok==false) break;
    }
    
    //for (ll i=1; i<=n; i++) cout<<a[i]<<" "; cout<<endl;
    if (is_sorted(a+1, a+n+1)) cout<<"YES\n";
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