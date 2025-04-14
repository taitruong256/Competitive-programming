#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;
    int i=3;
    float m=n*1.0;
    while (180.0-360.0/i<m)
    {
        ++i;
    }
    if (180.0-360.0/i==m) cout<<"YES\n"; else cout<<"NO\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while (t--)
    solve();
    return 0;
}
