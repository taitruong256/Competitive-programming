#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
 
void solve()
{
    ll n, m; cin>>n>>m;
    ll a[n+1], b[m+1], s[n+1]={0};
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=m; i++) cin>>b[i];
    for (ll i=1; i<n; i++) s[i]=s[i-1]+a[i];

    ll j=1;
    for (ll i=1; i<=m; i++)
    {
        while (j<n && s[j]<b[i]) ++j;
        cout<<j<<" "<<b[i]-s[j-1]<<endl;
    }
}
 
int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("a_input.txt","r",stdin);
    freopen("a_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}