#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s; cin>>s;
    char min1='z', min2='z';
    for (int i=0; i<s.size(); i++) if (s[i]<min1) min1=s[i];
    for (int i=0; i<s.size(); i++) if (s[i]==min1)
    {
        if (i-1>=0 && s[i-1]<min2) min2=s[i-1];
        if (i+1<s.size() && s[i+1]<min2) min2=s[i+1];
    }
    ll k; cin>>k;
    for (int i=0; i<k; i++) if (i%2==0) cout<<min1; else cout<<min2;
}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
