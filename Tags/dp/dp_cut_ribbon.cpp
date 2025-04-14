#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, a[4]; cin>>n;
    for (int i=1; i<=3; i++) cin>>a[i];
    int f[n+1]; for (int i=0; i<=n; i++) f[i]=-100000;
    f[0]=0;
    for (int i=1; i<=3; i++)
        for (int j=a[i]; j<=n; j++)
            f[j]=max(f[j], f[j-a[i]]+1);
    for (int i=1; i<=n; i++) cout<<f[i]<<" "; cout<<endl;
    cout<<f[n];
    return 0;
}
