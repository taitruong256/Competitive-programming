/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k, n, a, b;

bool check(ll x)
{
    if (a*x+(n-x)*b<k) return true;
    else return false;
}

void solve()
{
    cin>>k>>n>>a>>b;
    if (k<=n*b)
    {
        cout<<-1<<endl;
        return;
    }

    ll l=0, r=n, ans=0;
    while (l<=r)
    {
        ll mid=(l+r)>>1;
        if (check(mid)) ans=mid, l=mid+1;
        else r=mid-1;
    }
    cout<<ans<<endl;
}

int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    while (t--) solve();
    return 0;
}