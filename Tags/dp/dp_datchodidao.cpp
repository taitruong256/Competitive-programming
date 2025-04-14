#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k; cin>>n>>k;
    int a[n+1], b[n+1], s=0;
    for (int i=0; i<n; i++) cin>>a[i];
    b[0]=a[0];
    for (int i=1; i<n; i++) if (a[i]+b[i-1]<k)
    {
        s=s+k-a[i]-b[i-1];
        b[i]=max(k-b[i-1], a[i]);
    }
    else b[i]=a[i];
    cout<<s<<endl;
    for (int i=0; i<n; i++) cout<<b[i]<<" ";
    return 0;
}
