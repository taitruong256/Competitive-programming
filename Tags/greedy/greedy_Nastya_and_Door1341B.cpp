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
    ll n, k; cin>>n>>k;
    ll a[n+5], s[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    memset(s, 0, sizeof(s));
    for (ll i=2; i<=n-1; i++) s[i]=s[i-1]+(a[i]>max(a[i-1], a[i+1]));

    //for (ll i=1; i<=n; i++) cout<<s[i]<<" "; cout<<endl;
    ll ans=-1, pos=-1;
    for (ll i=1; i<=n-k+1; i++) if (s[i+k-2]-s[i]>ans)
    {
        ans=s[i+k-2]-s[i];
        pos=i;
    }
    cout<<ans+1<<" "<<pos<<endl;
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