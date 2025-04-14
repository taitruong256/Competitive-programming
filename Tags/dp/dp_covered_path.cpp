#include<bits/stdc++.h>
using namespace std;

int main()
{
    int v1, v2, t, d; cin>>v1>>v2>>t>>d;
    int f[t+1], s=0;
    for (int i=1; i<=t; i++) f[i]=1e9;
    f[1]=v1; f[t]=v2;
    for (int i=2; i<=t-1; i++) f[i]=min(f[i], f[i-1]+d);
    for (int i=t-1; i>=2; i--) f[i]=min(f[i], f[i+1]+d);
    for (int i=1; i<=t; i++) s+=f[i];
    cout<<s;
    return 0;
}
