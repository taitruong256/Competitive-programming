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
    char f[10];
    memset(f, 0, sizeof(f));
    for (ll i=1; i<=9; i++) cin>>f[i];

    for (ll i=0; i<n; i++) if (f[s[i]-'0']>s[i]) 
    {
        for (ll j=i; j<n; j++) if (f[s[j]-'0']>s[j]) s[j]=f[s[j]-'0']; else break;
        break;
    }
    
    cout<<s;

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; // cin>>t;
    for (ll _=0; _<t; _++)
    {
        //cout<<"Test case "<<_<<endl;
        solve();
    }
    return 0;
}