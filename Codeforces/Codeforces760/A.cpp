#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll a[7];
    for (ll i=0; i<7; i++)  cin>>a[i];
    if (a[0]+a[1]<a[3])
    {
        cout<<a[0]<<" "<<a[1]<<" "<<a[3]<<"\n";
        return;
    }
    cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<"\n";
}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}
