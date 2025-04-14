#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int x; cin>>x;
    bool f[1000]={false}; f[0]=true; f[3]=true; f[7]=true;
    for (int i=8; i<=x; i++) if (f[i-3]==true || f[i-7]==true) f[i]=true;
    if (f[x]==true) cout<<"YES"<<endl; else cout<<"NO";
    return;
}

int main()
{
    int n; cin>>n;
    while (n--) solve();
    return 0;
}
