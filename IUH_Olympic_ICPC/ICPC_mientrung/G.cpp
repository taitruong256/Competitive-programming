#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll a[500005];

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>s;
    for (ll i=0; i<s.size(); i++) a[i]=ll(s[i])-'A';
    ll t; cin>>t;
    while (t--)
    {
        ll n, l, r; cin>>n>>l>>r;
        for (ll i=l-1; i<r; i++) a[i]=(a[i]+n)%26;
    }
    for (ll i=0; i<s.size(); i++) cout<<char('A'+a[i]);
    return 0;
}
