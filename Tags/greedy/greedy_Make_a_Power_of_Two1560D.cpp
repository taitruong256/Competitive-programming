/*=====================================================================================
    Nothing is impossible, only you think it is impossible                 
            Try, try, try again until you succeed     
              Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string power[60];
 
ll f(string s, string t)
{
    ll i=0, j=0, cnt=0;
    while (i<s.size() && j<t.size())
    {
        if (s[i]==t[j])
        {
            ++cnt;
            ++j;
        }
        ++i;
    }
    return s.size()+t.size()-2*cnt;
}
 
void solve()
{
    string n; cin>>n;
    ll ans=1e11;
    for (ll i=0; i<60; i++) ans=min(ans, f(n, power[i]));                        
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    for (ll i=0; i<60; i++) power[i]=to_string(1LL<<i);
    ll t=1;  cin>>t;
    while (t--) solve();
    return 0;
}