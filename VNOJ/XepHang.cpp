#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, a[50005];
    cin>>n>>q;
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=1; i<=q; i++)
    {
        int x, y, csmax=1;
        cin>>x>>y;
        int gtmin=a[x], gtmax=a[x];
        for (int j=x+1; j<=y; j++)
        {
            gtmin=min(gtmin, a[j]);
            gtmax=max(gtmax, a[j]);
        }
        cout<<gtmax-gtmin<<endl;
    }
    return 0;
}


