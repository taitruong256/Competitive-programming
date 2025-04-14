/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[300005]={0};

void solve()
{
    ll a, b; cin>>a>>b;
    ll t=x[a-1];
    if (t==b) cout<<a<<endl;
    else if ((t^b)==a) cout<<a+2<<endl;
    else cout<<a+1<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    for (ll i=1; i<300005; i++) x[i]=x[i-1]^i;
    ll t=1; cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}