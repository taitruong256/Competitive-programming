#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";

void solve()
{
    ll n, m, x, y; cin>>n>>m>>x>>y;
    ll ans=0;
    for (ll i=0; i<n; i++)
    {
        string s; cin>>s;
        s=s+'@';
        ll count=0;
        for (ll j=0; j<s.size(); j++)
            if (s[j]=='.') ++count;
            else 
            { 
                ans+=min(count*x, count/2*y+count%2*x);  
                count=0;
            }
    }
    cout<<ans<<endl;
}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("a_input.txt","r",stdin);
    freopen("a_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}
