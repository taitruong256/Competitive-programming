#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c; cin>>a>>b>>c;
    if (a==b+c || b==a+c || c==a+b) cout<<"YES\n";
    else cout<<"NO\n";
}

int main()
{
    int t; cin>>t;
    for (int i=0; i<t; i++) solve();
    return 0;
}