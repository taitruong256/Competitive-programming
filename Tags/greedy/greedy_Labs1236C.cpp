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
    ll n; cin>>n;
    ll a[n+5][n+5];

    ll cur=1;
    for (ll j=0; j<n; j++)
    {
        if (j%2==0)
        {
            for (ll i=0; i<n; i++) 
            {
                a[i][j]=cur;
                ++cur;
            }
        }
        else
        {
            for (ll i=n-1; i>=0; i--)
            {
                a[i][j]=cur;
                ++cur;
            }
        }
    }

    for (ll i=0; i<n; i++)
    {
        for (ll j=0; j<n ;j++) cout<<a[i][j]<<" ";
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
    ll t=1; //cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}