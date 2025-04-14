#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s;
    ll n; cin>>n;
    cin>>s; 
    bool kt=true;        
    for (ll i=0; i<n-3; i++)
    {
        string t; cin>>t;
        if (t[0]==s[s.size()-1]) s=s+t[1];
        else
        {
            kt=false;
            s=s+t;
        }
    }
    if (kt==true) cout<<s+"a\n"; else cout<<s<<"\n";
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
