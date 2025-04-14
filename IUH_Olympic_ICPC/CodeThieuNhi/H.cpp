#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s; cin>>s;
    int d1=0, d2=0;
    for (int i=0; i<s.size(); i++) if(s[i]=='1') ++d1; else ++d2;
    if (min(d1, d2)%2==1) cout<<"DA\n"; else cout<<"NET\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while (t--) solve();
    return 0;
}