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
    ll a[n+5];
    vector<ll> red, blue;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++)
    {
        char c; cin>>c;
        if (c=='R') red.push_back(a[i]);
        else blue.push_back(a[i]);
    }
    sort(blue.begin(), blue.end());
    sort(red.begin(), red.end());
    ll m=1; 
    for (ll i=0; i<blue.size(); i++, m++) if (blue[i]<m)
    {
        cout<<"NO\n";
        return;
    }
    for (ll i=0; i<red.size(); i++, m++) if (red[i]>m)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
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