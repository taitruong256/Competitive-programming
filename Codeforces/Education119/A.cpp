#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s; cin>>s;
    ll d=0; 
    for (ll i=0; i<s.size(); i++) if (s[i]=='N') ++d;
    if (d==1) cout<<"NO\n";
    else cout<<"YES\n";
    }

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}
