#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";

void solve()
{
    ll n; cin>>n;
    ll a[n];
    vector<ll> ans;
    for (ll i=0; i<n; i++) cin>>a[i];
    for (ll i=0; i<n; i++) 
        if (i==0 || i==n-1 || (a[i]>a[i-1] && a[i]>a[i+1]) || (a[i]<a[i-1] && a[i]<a[i+1]))
            ans.push_back(a[i]);
    
    cout<<ans.size()<<endl;
    for (auto x: ans) cout<<x<<" ";
    cout<<endl;
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
