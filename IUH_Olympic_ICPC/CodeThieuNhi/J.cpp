#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    long long n, x, , min, max;
    cin>>n>>x;
    for (long long i=1; i<=n; i++)
    {
        cin>>a[i];
        min=min+a[i];
        max=max+(a[i]+x-1)/x;
    }
    cout<<(min+x-1)/x<<" "<<max<<"\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while (t--) solve();
    return 0;
}