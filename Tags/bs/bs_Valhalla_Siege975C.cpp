/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, q;
    cin>>n>>q;
    ll a[n+5];
    for (ll i=0; i<n; i++) cin>>a[i];
    for (ll i=1; i<n; i++) a[i]+=a[i-1];

    ll sum=0;
    for (ll i=0; i<q; i++)
    {
        ll x; cin>>x;
        sum+=x;
        if (sum>=a[n-1])
        {
            cout<<n<<endl;
            sum=0;
            continue;
        }
        ll pos=upper_bound(a, a+n, sum)-a;
        cout<<n-pos<<endl;
    }
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