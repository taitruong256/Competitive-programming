/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define mod 1000000007

void solve()
{
    ll n; cin>>n;
    char a[n+5][n+5];
    ll x1=0, y1=0, x2, y2; 
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) 
        {
            cin>>a[i][j];
            if (a[i][j]=='*')
            {
                if (x1==0 && y1==0)
                {
                    x1=i;
                    y1=j;
                }
                else
                {
                    x2=i;
                    y2=j;
                }
            }
        }
    
    if (x1==x2)
    {
        if (x1>1)
        {
            a[x1-1][y1]='*';
            a[x2-1][y2]='*';
        }
        else
        {
            a[x1+1][y1]='*';
            a[x2+1][y2]='*';
        }
    }
    else if (y1==y2)
    {
        if (y1>1)
        {
            a[x1][y1-1]='*';
            a[x2][y2-1]='*';
        }
        else
        {
            a[x1][y1+1]='*';
            a[x2][y2+1]='*';
        }
    }
    else
    {
        if (x1<x2 && y1<y2)
        {
            a[x2][y1]='*';
            a[x1][y2]='*';
        }
        else
        {
            a[x1][y2]='*';
            a[x2][y1]='*';
        }
    }

    for(ll i=1; i<=n; i++)
    {
        for (ll j=1; j<=n; j++) cout<<a[i][j];
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
    ll t=1; cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}