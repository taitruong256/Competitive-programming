/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ok=true;

void cong(ll a, ll b, ll c, ll d)
{
    ll x=a+c, y=b+d;
    if (x==0) 
    {
        if (y==0) cout<<0<<" ";
        else if (y>0) cout<<y<<"*i ";
        else cout<<y<<"*i ";
        return;
    }
    cout<<x;
    if (y>0) cout<<"+"<<y<<"*i ";
    else if (y<0) cout<<y<<"*i ";
    else if (y==0) cout<<" ";
}

void nhan(ll a, ll b, ll c, ll d)
{             
    ll x=a*c-b*d, y=a*d+b*c;
    if (x==0) 
    {
        if (y==0) cout<<0;
        else if (y>0) cout<<y<<"*i";
        else cout<<y<<"*i";
        return;
    }
    cout<<x;
    if (y>0) cout<<"+"<<y<<"*i";
    else if (y<0) cout<<y<<"*i";
}

void solve()
{
    ll a, b, c, d; cin>>a>>b>>c>>d;
    cong(a, b, c, d);
    nhan(a, b, c, d);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}
