/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
 =====================================================================================
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
ll n, m, x, y;

void solve()
{
    cin>>n>>m>>x>>y;
    ll k, ans=0; cin>>k;
    while (k--)
    {
        ll a, b; cin>>a>>b;
        ll l=0, r=2e10, count=0;
        while (l<=r)
        {
            ll mid=(l+r)>>1; 
            ll h1=x+mid*a, h2=y+mid*b;
            if (1<=x+mid*a && x+mid*a<=n && 1<=y+mid*b && y+mid*b<=m) count=mid, l=mid+1;
            else r=mid-1;
        }          
        x+=a*count;           
        y+=b*count;  
        ans+=count;  //cout<<x<<" "<<y<<" "<<count<<endl;
    }
    cout<<ans;
}

int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; //cin>>t;
    while (t--) solve();
    return 0;
}