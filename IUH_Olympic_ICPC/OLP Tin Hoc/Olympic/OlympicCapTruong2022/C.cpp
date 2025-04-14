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
    ll n, t; cin>>n>>t;
    char s[n]; 
    for (ll i=0; i<n; i++) cin>>s[i];
    ll cnt=0;
    while (true)
    {
        bool ok=false;
        for (ll i=0; i<n-1; i++) if (s[i]=='B' && s[i+1]=='G') 
        {
            swap(s[i], s[i+1]);
            ok=true;
            ++i;
        }    
        ++cnt;
        if (ok==false) break;
        if (cnt==t) break;
    }
    for (ll i=0; i<n; i++) cout<<s[i];
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}