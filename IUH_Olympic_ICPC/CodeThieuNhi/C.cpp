#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;
    int a[n+1], b[n+1];
    for (int i=0; i<n; i++)
    {
        char ch; cin>>ch;
        a[i]=(int)ch;
        b[i]=(int)ch;
    }
    sort(b, b+n);
    int ans=0;
    for (int i=0; i<n; i++) if (a[i]!=b[i]) ++ans;
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while (t--) solve();
    return 0;
}
