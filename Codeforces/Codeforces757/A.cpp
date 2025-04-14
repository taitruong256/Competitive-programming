#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, l, r, k, d=0;
    cin>>n>>l>>r>>k;
    int a[n+1];
    for (int i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);
    int s=0;
    for (int i=0; i<n; i++) if(a[i]>=l && a[i]<=r && a[i]<=k)
    {
        k=k-a[i];
        ++d;
    }
    cout<<d<<endl;
    return;
}

int main()
{
    int t; cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
