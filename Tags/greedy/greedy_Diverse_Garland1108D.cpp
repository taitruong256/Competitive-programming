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
    ll n; cin>>n;
    string s; cin>>s;
    ll ans=0;
    for (ll i=0; i<n; i++)
    {
        ll j=i;
        while (j<n && s[i]==s[j]) ++j;
        string p="BGR";
        p.erase(p.find(s[i]), 1);
        if (j<n) p.erase(p.find(s[j]), 1);     
        for (ll k=i+1; k<j; k+=2) 
        {
            ++ans;
            s[k]=p[0];
        }
        i=j-1;
    }
    cout<<ans<<endl;
    cout<<s;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  //cin>>t;
    while (t--) solve();
    return 0;
}