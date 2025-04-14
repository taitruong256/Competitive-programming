/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll zone(ll a, ll b, ll c, ll d)
{
    if (a<c && b<d) return 1;
    if (a<c && b>d) return 2;
    if (a>c && b<d) return 3;
    if (a>c && b>d) return 4;
    return 0;
}

void solve()
{
    ll n; cin>>n;
    ll ax, ay, bx, by, cx, cy; cin>>ax>>ay>>bx>>by>>cx>>cy;
    ll u=zone(bx, by, ax, ay);
    ll v=zone(cx, cy, ax, ay);
    if (u==0 || v==0) cout<<"NO";
    else if (u!=v) cout<<"NO";
    else cout<<"YES";
}
 
int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; 
    while (t--) solve();
    return 0;
}
