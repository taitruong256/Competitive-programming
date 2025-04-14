/*=====================================================================================
    Nothing is impossible, only you think it is impossible                 
            Try, try, try again until you succeed     
              Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    string s;
    char c;
    cin>>n>>c>>s;
    
    ll cnt=0;
    for (ll i=0; i<s.size(); i++) if (s[i]==c) ++cnt;
    if (cnt==n)
    {
        cout<<0<<endl;
        return;
    }
    for (ll i=2; i<=n; i++)
    {
        bool ok=true;
        for (ll j=i; j<=n; j+=i) if (s[j-1]!=c)
        {
            ok=false;    
            break;
        }
        if (ok==true)
        {
            cout<<1<<endl;
            cout<<i<<endl;
            return;
        }
    }
    cout<<2<<endl;
    cout<<n-1<<" "<<n<<endl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  cin>>t;
    while (t--) solve();
    return 0;
}