/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, x, y; 

bool check(ll k)
{
    ll cnt;  
    if (k/(x/__gcd(x, y))<y) cnt=0;
    else cnt=n/(x/__gcd(x, y)*y);
    if (y%x==0) return k-k/x;
    return k-k/x-k/y+cnt>=n;
}

void solve()
{
    cin>>n>>x>>y;
    if (x>y) swap(x, y);
    ll l=0, r=3e18+5;
    ll ans=1;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (check(mid)) ans=mid, r=mid-1;
        else l=mid+1;    
    }
    while (ans%x==0 || ans%y==0) ++ans;
    cout<<ans<<endl;
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