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
    ll n, m; cin>>n>>m;
    for (ll i=0; i<n; i++)
    {
        string s; cin>>s;
        for (ll j=0; j<m; j++) 
            if (s[j]=='.')
            {
                if ((i+j)%2==0) cout<<"W"; else cout<<"B";
            }
            else cout<<s[j];
        cout<<endl;
    }
}
 
int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;
    while (t--) solve();
    return 0;
}
