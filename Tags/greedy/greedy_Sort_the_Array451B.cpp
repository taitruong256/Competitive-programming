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
    ll a[n+5], b[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) b[i]=a[i];
    sort(b+1, b+n+1);

    // for (ll i=1; i<=n; i++) cout<<a[i]<<" "; cout<<endl;
    // for (ll i=1; i<=n; i++) cout<<b[i]<<" "; cout<<endl;

    if (is_sorted(a+1, a+n+1))
    {
        cout<<"yes\n";
        cout<<1<<" "<<1;
        return;
    }
    ll st=1, en=n;
    for (ll i=1; i<=n; i++) if (a[i]!=b[i])
    {
        st=i;
        break;
    }
    for (ll i=n; i>=1; i--) if (a[i]!=b[i])
    {
        en=i;
        break;
    }                       
                                                      //   cout<<st<<" "<<en<<endl;
    for (ll i=st; i<=en; i++) if (b[en+st-i]!=a[i])
    {                                //   cout<<en-+st+i<<" "<<i<<endl;
        cout<<"no";
        return;
    }
    cout<<"yes\n";
    cout<<st<<" "<<en;
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