/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll C(ll n, ll k)
{
    ll res=1;
    for (ll i=1; i<=k; i++)
    {
        res*=(n-i+1);
        res/=i;
    }
    return res;
}


void solve()
{
    ll n; cin>>n;
    cout<<C(n, 7)+C(n, 6)+C(n, 5);
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