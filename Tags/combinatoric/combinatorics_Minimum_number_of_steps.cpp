/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define mod 1000000007
void solve()
{
    string s; cin>>s;
    ll cnt=0, ans=0;
    for (ll i=s.size()-1; i>=0; i--)
    {
        if (s[i]=='b') ++cnt;
        else
        {
            ans=(ans+cnt)%mod;
            cnt=(cnt*2)%mod;
        }
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; //cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}