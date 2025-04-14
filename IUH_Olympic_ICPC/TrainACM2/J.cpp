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
    ll n, x0, y0; cin>>n>>x0>>y0;
    set<double> st;
    float INF=2000000005;
    for (ll i=0; i<n; i++)
    {
        ll x, y; cin>>x>>y;
        x-=x0;
        y-=y0;
        if (y==0) st.insert(INF);
        else st.insert(x*1.0/y);
    }
    cout<<st.size();
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