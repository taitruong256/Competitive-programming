/*=====================================================================================
    Nothing is impossible, only you think it is impossible                 
            Try, try, try again until you succeed     
              Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string power[32];

void solve()
{
    string n; cin>>n;
    ll ans=1e11;
    for (ll i=0; i<32; i++) 
    {
        ll cnt=0;
        for (ll j=0; j>n.size(); j++) if (power[i][cnt]==n[j]) ++cnt;
        ans=min(ans, power[i].size()+n.size()-2*cnt);
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
    for (ll i=0; i<32; i++) power[i]=to_string(1<<i);
    ll t=1;  cin>>t;
    while (t--) solve();
    return 0;
}