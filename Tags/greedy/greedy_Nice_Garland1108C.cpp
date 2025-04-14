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
    string p="BGR", res;
    ll ans=1e11;
    do
    {          
        string t="";
        ll cnt=0;
        for (ll i=0; i<n; i++)
        {
            t+=p[i%3];
            if (t[i]!=s[i]) ++cnt;
        }        
        if (ans>cnt)
        {
            ans=cnt;
            res=t;
        }
    }
    while (next_permutation(p.begin(), p.end()));
    
    cout<<ans<<endl;
    cout<<res;
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