/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define mod 1000000007

void solve()
{
    string s; cin>>s;
    ll l=0, r=s.size()-1;
    for (ll i=0; i<s.size(); i++) if (s[i]=='1')
    {
        l=i;
        break;
    }
    for (ll i=s.size()-1; i>=0; i--) if (s[i]=='1')
    {
        r=i;
        break;
    }           //  cout<<l<<"   "<<r<<endl;
    if (l==0 && r==s.size()-1 && s[0]=='0') cout<<0<<endl;
    else
    {
        ll cnt=0;
        for (ll i=l; i<=r; i++) if (s[i]=='0') ++cnt;
        cout<<cnt<<endl;
    }
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