/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, sx, sy; 
ll x[200005], y[200005];
ll ans=-1, tx, ty;

void solve(ll px, ll py)
{
    ll cnt=0;
    for (ll i=0; i<n; i++) 
        if (min(x[i], sx)<=px && px<=max(x[i], sx) && min(y[i], sy)<=py && py<=max(y[i], sy)) 
            ++cnt;
    
    if (cnt>ans)
    {
        tx=px;
        ty=py;
        ans=cnt;
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
    for (ll tc=1; tc<=t; tc++) 
    {
        cin>>n>>sx>>sy;
        for (ll i=0; i<n; i++) cin>>x[i]>>y[i];
        solve(sx+1, sy);
        solve(sx-1, sy);
        solve(sx, sy+1);
        solve(sx, sy-1);
        cout<<ans<<endl<<tx<<" "<<ty<<endl;
    }
    return 0;
}