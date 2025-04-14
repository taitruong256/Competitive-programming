#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void swap(char &a, char &b)
{
    char t=a;
    a=b;
    b=t;
}

bool check(string s)
{
    for (ll i=0; i<s.size(); i++) if (s[i]=='a')
        for (ll j=0; j<s.size(); j++) if (s[j]=='b')
            for (ll k=0; k<s.size(); k++) if (s[k]=='c') return true;
    return false;
}

void solve()
{
    string s, t; cin>>s>>t;
    sort(s.begin(), s.end());
    if (t=="abc" && check(s)==true)
    for (ll i=0; i<s.size(); i++) if (s[i]=='b')
        for (ll j=i+1; j<s.size(); j++) if (s[j]=='c') swap(s[i], s[j]);
    cout<<s<<"\n";
}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}
