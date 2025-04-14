#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, n, kq=0;
    cin>>x>>n;
    int a[n+1];
    for (int i=1; i<=n; i++) cin>>a[i];
    bool d[1000001]={false};
    d[0]=true;
    for (int i=1; i<=n; i++) d[a[i]]=true;

    for (int i=1; i<=n; i++)
        for (int j=0; j<=x/a[i]; j++) if (d[x-a[i]*j]==true)
        {
            ++kq;
            cout<<a[i]<<" "<<j<<" "<<x-a[i]*j<<endl;
        }

    for (int i=1; i<=x; i++) cout<<d[i]<<" "; cout<<endl;
    cout<<kq;
    return 0;
}
