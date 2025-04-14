/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; string s, t; cin>>n>>s>>t;
    ll ans=0;
    for (ll i=0; i<n; i++) 
        if (s[i]!=t[i]) ans+=2;
        else if (s[i]=='0')
        {
            if (i+1<n && s[i+1]=='1' && t[i+1]=='1') ans+=2, i++;
            else ans++;
        }
        else if (s[i]=='1')
        {
            if (i+1<n && s[i+1]=='0' && t[i+1]=='0') ans+=2, i++;
        } 
    
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}