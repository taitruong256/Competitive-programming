#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, ans=1000000000, j=1; cin>>n>>k;
    int a[n+1], s[n+1]={0};
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=1; i<=n; i++) s[i]=s[i-1]+a[i];
    for (int i=k; i<=n; i++) if(s[i]-s[i-k]<ans)
    {
        ans=s[i]-s[i-k];
        j=i-k+1;
    }
    cout<<j;
    return 0;
}
