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
    ll n, k; cin>>n>>k;
    string s; cin>>s;
    if (n==1 && k==1) cout<<0<<endl;
    else if (k==0) cout<<s<<endl;
    else if (s[0]=='1') 
    {
        cout<<1;
        ll d=0;
        for (ll i=1; i<n; i++) 
            if (d>=k) cout<<s[i];
            else if (s[i]=='0') cout<<0;
            else 
            {
                cout<<0;
                ++d;
            }
        cout<<endl;
    }
    else 
    {
        ll d=0;
        cout<<1;
        for (ll i=1; i<n; i++) 
            if (d>=k-1) cout<<s[i];
            else if (s[i]=='0') cout<<0;
            else 
            {
                cout<<0;
                ++d;
            }
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
    ll t=1;
    while (t--) solve();
    return 0;
}