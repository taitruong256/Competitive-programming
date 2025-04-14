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
    string s; cin>>s;
    ll ans=0, mx=0, n=s.size();
 
    for (ll i=s.size()-1; i>=0; i--)
    {
        ll a=s[i]-'0';
        ll b=s[i+1]-'0';
        if (a+b>mx)
        {
            mx=a+b;
            ans=i;
        }
    }      
    if (mx>=10)
    {
        for (ll i=0; i<ans; i++) cout<<s[i];
        cout<<mx;
        for (ll i=ans+2; i<n; i++) cout<<s[i];
        cout<<endl;
    }
    else
    {
        ll pos=0;
        for (ll i=0; i<n-1; i++) if (s[i]!='0' && s[i+1]!='0')
        {
            pos=i;
            break;
        }
        for (ll i=0; i<pos; i++) cout<<s[i];
        cout<<s[pos]+s[pos+1]-2*'0';
        for (ll i=pos+2; i<n; i++) cout<<s[i];
        cout<<endl;
    }
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