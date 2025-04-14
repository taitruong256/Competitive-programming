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
    ll a, b, sb, ss; cin>>a>>b;  
    sb=a+b;      
    ll ta=0, tb=0, ts=0;
    while (a>0)
    {
        ll x=a%10;
        if (x!=0) ta=ta*10+x;
        a/=10;
    }
    while (b>0)
    {
        ll x=b%10;
        if (x!=0) tb=tb*10+x;
        b/=10;
    }
    while (sb>0)
    {
        ll x=sb%10;
        if (x!=0) ts=ts*10+x;
        sb/=10;
    }
    a=ta;
    ta=0;
    while (a>0)
    {
        ll x=a%10;
        if (x!=0) ta=ta*10+x;
        a/=10;
    }
    b=tb;
    tb=0;
    while (b>0)
    {
        ll x=b%10;
        if (x!=0) tb=tb*10+x;
        b/=10;
    }
    sb=ts;
    ts=0;
    while (sb>0)
    {
        ll x=sb%10;
        if (x!=0) ts=ts*10+x;
        sb/=10;
    }
    //cout<<ta<<"  "<<tb<<"   "<<ts;
    if (ta+tb!=ts) cout<<"NO"; else cout<<"YES";
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