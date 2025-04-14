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
ll n, k; 
vector<ll> a;
bool check(ll x)
{
    ll move=0;
    for (ll i=n/2; i<n; i++) if (x-a[i]>0) move+=x-a[i]; 
    return move<=k;
}

void solve()
{
    cin>>n>>k;
    for (ll i=0; i<n; i++) 
    {
        ll x; cin>>x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    
    ll l=0, r=2000000000, ans=0;
    while (l<=r)
    {
        ll mid=(l+r)>>1;
        if (check(mid)) ans=mid, l=mid+1;
        else r=mid-1;
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