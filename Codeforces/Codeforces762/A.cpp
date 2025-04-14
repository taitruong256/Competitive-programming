#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

void solve()
{
    string s; cin>>s;
    if (s.size()%2==1)
    {
        cout<<"NO\n";
        return;
    }
    ll n=s.size();
    for (ll i=0; i<n/2; i++) if (s[i]!=s[i+n/2])
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
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
