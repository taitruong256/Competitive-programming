#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    string s; cin>>s;
    ll n=s.size();
    vector<ll> z(n+5);
    for (ll i=1, l=0, r=0; i<n; i++)
    {
        if (i<=r) z[i]=min(z[i-l], r-i+1);
        while (i+z[i]<n && s[z[i]]==s[i+z[i]]) ++z[i];
        if (i+z[i]-1>r) l=i, r=i+z[i]-1;
    }
    for (ll i=0; i<=n; i++) if (i+z[i]==n) cout<<i<<" ";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    solve();
    return 0;
}
