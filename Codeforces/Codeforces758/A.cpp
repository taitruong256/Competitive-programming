#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(nullptr);
#define ll long long
using namespace std;

void solve()
{
    ll n; cin>>n; 
    for (int i=1; i<=n; i++) cout<<i<<" ";
    cout<<"\n";
}

int main() {                   
    FAST;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t; cin>>t; 
    while (t--) solve();
    return 0;
}
