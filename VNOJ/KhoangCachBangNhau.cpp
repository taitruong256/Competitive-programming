#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n;
    cin>>m>>n;
    int a[m+1][n+1];
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++) cin>>a[i][j];
    int f[m+1][n+1]={0}, d[10000]={0};
    int x[4]={-1, 1, 0, 0};
    int y[4]={0, 0, 1, -1};

    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
        {
            f[i][j]=a[i][j];
            for (int k=0; k<4; k++)
            {
                int p=i+x[k];
                int q=j+y[k];
                if (p==0 || q==0 || p==m+1 || q==n+1) continue;
                f[i][j]+=a[p][q];
            }
            ++d[f[i][j]];
        }

    int kq=0, max=0;
    for (int i=0; i<=5001; i++) if (d[i]>=max)
    {
        kq=i;
        max=d[i];
    }
    cout<<kq;
    return 0;
}

