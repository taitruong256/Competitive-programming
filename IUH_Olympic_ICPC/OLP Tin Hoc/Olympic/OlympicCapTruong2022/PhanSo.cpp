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
    ll x=1, y=1, n;
    cin>>n;
    for (ll i=0; i<n; i++)
    {
        ll t; cin>>t;
        x*=t;
        while (y%2==0) y/=2;
        while (y%5==0) y/=5;
    }
    for (ll i=0; i<n; i++)
    {
        ll t; cin>>t;
        y*=t;
        while (y%2==0) y/=2;
        while (y%5==0) y/=5;
    }
    ll temp=__gcd(x, y);
    x/=temp;
    y/=temp;
    while (y%2==0) y/=2;
    while (y%5==0) y/=5;
    if (y==1) cout<<"finite\n";
    else cout<<"repeating\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("fraction.txt", "r", stdin);
    freopen("fraction.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}