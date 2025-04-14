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
    ll n, k; cin>>n>>k;
    string s[10];
    for (int i=0; i<n; i++) cin>>s[i];
    
    ll ans=1e11;
    ll p[10];
    for (ll i=0; i<k; i++) p[i]=i;


    do
    {
        ll x=0, mx=-1e9, mn=1e9;
        for (ll i=0; i<n; i++)
        {
            x=0;
            for (ll j=0; j<k; j++) x=x*10+s[i][p[j]]-'0';
            mx=max(mx, x); 
            mn=min(mn, x);
        }
        if (mx-mn<ans) ans=mx-mn;      
    }
    while (next_permutation(p, p+k));
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