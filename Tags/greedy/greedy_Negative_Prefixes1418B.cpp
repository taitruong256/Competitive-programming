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
    ll a[n+5], d[n+5];
    vector<ll> b;
    for (ll i=0; i<n; i++) cin>>a[i];
    for (ll i=0; i<n; i++)
    {
        cin>>d[i];
        if (d[i]==0) b.push_back(a[i]);
    }
    sort(b.begin(), b.end(), greater<ll>());
    ll j=0;
    for (ll i=0; i<n; i++)
    {
        if (d[i]==1) cout<<a[i]<<" ";
        else cout<<b[j++]<<" ";
    }
    cout<<endl;
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