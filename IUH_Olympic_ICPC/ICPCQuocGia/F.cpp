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
    ll n; cin>>n;
    ll f[100];
    memset(f, 0, sizeof(f));
    f[1]=1;
    for (ll i=2; i<=50; i++)
    {
        f[i]=0;
        for (ll j=1; j<i; j++) f[i]+=f[j];
        ++f[i];
    }
    //for (ll i=1; i<=50; i++) cout<<f[i]<<" "; cout<<endl;
    cout<<f[n];
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