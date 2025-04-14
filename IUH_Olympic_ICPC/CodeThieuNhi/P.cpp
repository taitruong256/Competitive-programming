#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, a[200], d0[200], d1[200]; cin>>n;
    for (int i=0; i<=100; i++)
    {
        d0[i]=0;
        d1[i]=1;
    }
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=1; i<=n; i++) if(a[i]==0) d0[i]=d0[i-1]+1;
    for (int i=1; i<=n; i++) if(a[i]==1) d1[i]=d1[i-1]+1;

    m=d1[n];
    for (int i=1; i<=n-1; i++)
        for (int j=i+1; j<=n; j++) 
            if (d1[n]+d0[j]-d0[i-1]-(d1[j]-d1[i-1])>m) m=d1[n]+d0[j]-d0[i-1]-(d1[j]-d1[i-1]);
    cout<<m;
    return;
}

int main() {                   //      system("cls");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
