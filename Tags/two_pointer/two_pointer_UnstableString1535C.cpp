#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";

void solve()
{
    string s; cin>>s;
    ll zero=0, one=0, ans=0;
    for (ll i=0; i<s.size(); i++)
    {
        if (s[i]=='0')
        {
            ++zero;
            one=0;
            ans+=zero;
        }
        else if (s[i]=='1')
        {
            ++one;
            zero=0;
            ans+=one;
        }
        else
        {
            ++zero;
            ++one;
            ans+=max(zero, one);
        }        
        swap(zero, one);
    }
    cout<<ans<<endl;
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
