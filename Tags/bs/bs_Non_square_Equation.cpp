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

ll s(ll n)
{
    ll sum=0;
    while (n>0) sum+=n%10, n/=10;
    return sum;
}

void solve()
{
    ll n; cin>>n;
    for (ll i=0; i<=90; i++)
    {
        ll ans=-1, l=0, r=1e9;
        while (l<=r)
        {
            ll mid=(l+r)>>1;
            if (mid*mid + mid*i ==n) ans=mid, r=mid-1;
            else if (mid*mid + mid*i >n) r=mid-1;
            else l=mid+1;
            if (ans!=-1 && s(ans)==i)
            {
                cout<<ans;
                return;
            }
        }
    }
    cout<<-1;
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