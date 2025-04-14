#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                    Try, try, try again until you succeed                          
 =====================================================================================
*/
 
void solve()
{
    ll n, x0, y0; cin>>n>>x0>>y0;
    set<double> s;
    ll INF=2000000005;
    for (ll i=0; i<n; i++) 
    {
        ll x, y; cin>>x>>y;
        x=x-x0;
        y=y-y0;
        if (y==0) s.insert(INF);
        else s.insert(x*1.0/y);
    }
    cout<<s.size();
}

int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}