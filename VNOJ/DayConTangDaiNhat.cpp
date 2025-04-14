#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a[1001];
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    int f[1001]={0};
    f[0]=0;
    a[0]=-100000;
    for (int i=1; i<=n; i++)
    {
        int max=f[0];
        for (int j=0; j<=i-1; j++) if (a[j]<a[i] && f[j]>max) max=f[j];
        f[i]=max+1;
    }
    int gtmax=f[1];
    for (int i=2; i<=n; i++) if (f[i]>gtmax) gtmax=f[i];
    cout<<gtmax;
    return 0;
}

